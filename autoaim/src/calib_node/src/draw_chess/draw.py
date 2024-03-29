import numpy as np
import cv2

# 这个文件用来生成标准棋盘格，也许是用来测试

w, h, d = 10, 7, 100

# //为整数除法，3指三通道
chess = np.zeros([d//2 + h * d, d//2 + w * d, 3], dtype=np.uint8)
chess[:] = 255 # 将初始值设置为白色（255）

for i in range(w):
    for j in range(h):
        chess[d//4 + j * d: d//4 + d + j * d, d//4 + i * d: d//4 + d + i * d] = 0 if (i + j) % 2 == 0 else 255

cv2.imwrite("chess.png", chess)