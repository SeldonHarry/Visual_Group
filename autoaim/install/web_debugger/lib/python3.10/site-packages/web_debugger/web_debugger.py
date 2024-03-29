import os
import json
import rclpy
import rclpy.node
import threading
import time
import pytomlpp as toml
import ament_index_python
import numpy as np
import cv2
import base64
from flask import Flask, render_template, request, redirect, url_for, jsonify,send_file
from my_interfaces.msg import ReloadFlag 
from my_interfaces.srv import DebugInfo
from sensor_msgs.msg import CompressedImage

# setup paths
package_name = "web_debugger"
package_share_directory = ament_index_python.packages.get_package_share_directory(package_name)
WORKSPACE_PATH = os.path.join('/', *(package_share_directory.split('/')[:-4]))
BASE_PARAM_PATH = os.path.join(WORKSPACE_PATH, "src/param/assets/base.param.toml")
TEMPLATE_PATH = os.path.join(WORKSPACE_PATH, 'src/web_debugger/templates/')
STATIC_PATH=os.path.join(WORKSPACE_PATH, 'src/web_debugger/templates/static/')

class WebDebuggerNode(rclpy.node.Node):
    def __init__(self):
        super().__init__('web_debugger_node')
        self.publisher_ = self.create_publisher(ReloadFlag, 'ReloadParam', 10)
        self.srv = self.create_service(DebugInfo, 'web_debug', self.node_info_callback)
        self.sub = self.create_subscription(CompressedImage, 'debug_img_aim', self.node_img_callback, 10)
        self.debug_infos = {'node1': {'p1': 1}}
        self.node_img_base64_str_code = None
        self.mutex = threading.Lock()
    
    # def node_img_callback(self, msg):
    #     # 回调函数被触发后，输出调试信息
    #     print("topic updated")
    #     self.get_logger().info("img topic updated")
    #     # 转换为base64编码
    #     np_arr = np.fromstring(msg.data, np.uint8)
    #     node_img = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
    #     success, img_encoded = cv2.imencode('.jpg', node_img)

    #     # 输出调试信息
    #     self.get_logger().info("img encoding=",success) 

    #     # 新增'utf-8'
    #     self.node_img_base64_str_code = base64.b64encode(img_encoded).decode('utf-8')

    def node_img_callback(self, msg):
        self.node_img_base64_str_code = base64.b64encode(msg.data).decode('utf-8')
    
    def _set_debug_infos(self, key, value):
        # 将键值对转换为嵌套字典（类似json格式）
        paths = key.split('/')
        ptr = self.debug_infos
        for n in paths[:-1]:
            # 这里的n是键
            ptr[n] = ptr.get(n, {})
            ptr = ptr[n] # 将指针移动到下一级
        ptr[paths[-1]] = value
    
    # def _get_debug_infos(self, key):
    #     # 好像没有被调用到
    #     paths = key.split('/')
    #     ptr = self.debug_infos
    #     for n in paths:
    #         ptr = ptr[n]
    #     return ptr
    
    def node_info_callback(self, request, response):
        # self.get_logger().info("successfully get request")
        response.ok = True
        self.mutex.acquire()
        try:
            node_name = request.node_name
            key = request.key
            value = request.value
            self._set_debug_infos(node_name + '/' + key, value)
        except:
            response.ok = False
        self.mutex.release()
        return response
    
    def spin(self):
        rclpy.spin(self)

class MyFlaskApp(Flask):
    def __init__(self, import_path, template_folder,static_folder):
        super().__init__(import_path, template_folder=template_folder, static_folder=static_folder)
        rclpy.init()
        self.ros_node = WebDebuggerNode()
    
    def run(self, debug, host, port):
        node_thread = threading.Thread(target=self.ros_node.spin, daemon=True)
        # 将线程标记为守护线程（daemon），主程序在退出时不会等待守护线程的结束
        node_thread.start()
        super().run(debug=debug, host=host, port=port)

app = MyFlaskApp(__name__, template_folder=TEMPLATE_PATH, static_folder=STATIC_PATH)
@app.route('/')
def index():
    return render_template('index.html')

@app.route('/node_img')
def node_img():
    return render_template('node_img.html')

@app.route('/node_img/update')
def update_node_img():
    return jsonify({'img': app.ros_node.node_img_base64_str_code})

@app.route('/node_info')
def node_info():
    return render_template('node_info.html')

@app.route('/node_info/update')
def update_node_info():
    app.ros_node.mutex.acquire()
    data = jsonify(app.ros_node.debug_infos)
    app.ros_node.mutex.release()
    return data

@app.route('/node_video')
def node_video():
    return render_template('node_video.html')

@app.route('/get_img')
def get_img():
    # 读取PNG图像文件
    IMG_PATH = os.path.join(WORKSPACE_PATH, 'src/web_debugger/conda.png')
    return send_file(IMG_PATH, mimetype='image/png')

@app.route('/edit-param')
def edit_param():
    with open(BASE_PARAM_PATH) as file:
        data = file.read()
    return render_template('edit-param.html', data=data)

@app.route('/edit-param/post', methods=['POST'])
def edit_param_post():
    new_data = request.form['new-data']
    with open(BASE_PARAM_PATH, 'w') as file:
        file.write(new_data)
    # 这里暂时先不改了
    return '参数已保存捏 200'

def main():
    app.run(debug=False, host='0.0.0.0', port=8000)

if __name__ == '__main__':
    main()