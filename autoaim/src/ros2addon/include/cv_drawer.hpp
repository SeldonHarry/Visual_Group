#include "param/param.hpp"
#include <eigen3/Eigen/Core>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
namespace ros2addon::debug {
struct FlaskPoint {
    FlaskPoint(const cv::Point2f& pt,
               const cv::Scalar& color,
               const int& radius,
               const int& thickness):
        pt(pt),
        color(color),
        radius(radius),
        thickness(thickness) {}
    cv::Point2f pt;
    cv::Scalar color;
    int radius;
    int thickness;
};

struct FlaskLine {
    FlaskLine(const std::pair<cv::Point2f, cv::Point2f>& pt_pair,
              const cv::Scalar& color,
              const int& thickness):
        pt_pair(pt_pair),
        color(color),
        thickness(thickness) {}
    std::pair<cv::Point2f, cv::Point2f> pt_pair;
    cv::Scalar color;
    int thickness;
};

struct FlaskText {
    FlaskText(const std::string& str,
              const cv::Point2f& pt,
              const cv::Scalar& color,
              const double& scale):
        str(str),
        pt(pt),
        color(color),
        scale(scale) {}
    std::string str;
    cv::Point2f pt;
    cv::Scalar color;
    double scale;
};

const int FLASK_MAP_WIDTH = 1000;
const int FLASK_MAP_HEIGHT = 1000;
const int FLASK_MAP_MID_X = FLASK_MAP_WIDTH / 2;
const int FLASK_MAP_MID_Y = FLASK_MAP_HEIGHT / 2;
const double FLASK_MAP_PETER_BY_BRIGHT = 1.;
const cv::Scalar RED_MAIN_COLOR = { 63., 127., 255. };
const cv::Scalar BLUE_MAIN_COLOR = { 255., 127., 63. };
const cv::Scalar GRAY_MAIN_COLOR = { 190., 190., 190. };
const cv::Scalar MOTION_MAIN_COLOR = { 253, 238, 173 };
const cv::Scalar FLASK_MAP_TOP_CENTER_COLOR = { 255., 0., 255. };
const cv::Scalar FLASK_MAP_TOP_EDGE_COLOR = { 150., 135., 189. };
const cv::Scalar FLASK_MAP_TOP_PT_COLOR = { 0., 255., 0. };
const cv::Scalar FLASK_MAP_TEXT_COLOR = { 127, 127, 127 };
const double FLASK_MAP_TEXT_SCALE = 1.;
const int FLASK_MAP_PT_RADIUS = 4;
const int FLASK_MAP_THICKNESS = 2;

class CvDrawer {
public:
    explicit CvDrawer(const param::ParamVisitor& param_visitor);
    auto draw_line(cv::Mat& image,
                   const cv::Point2f& pt1,
                   const cv::Point2f& pt2,
                   const cv::Scalar& color,
                   const int& thickness) -> void;

    auto draw_lines(cv::Mat& image,
                    const std::vector<cv::Point2f>& pts,
                    const cv::Scalar& color,
                    const int& thickness,
                    const bool& closed) -> void;

    auto draw_arrow(cv::Mat& image,
                    const cv::Point2f& pt1,
                    const cv::Point2f& pt2,
                    const cv::Scalar& color,
                    const int& thickness) -> void;
    cv::Scalar heightened_color(const cv::Scalar& color, const double& z);

    FlaskPoint pos_to_map_point(const Eigen::Vector3d& pos,
                                const cv::Scalar& color,
                                const int& radius,
                                const int& thickness);

    std::vector<FlaskLine> pts_to_map_lines(const std::vector<cv::Point2f>& pts,
                                            const cv::Scalar& color,
                                            const bool& closed,
                                            const int& thickness);

    std::vector<FlaskLine> poses_to_map_lines(const std::vector<Eigen::Vector3d>& poses,
                                              const cv::Scalar& color,
                                              const bool& closed,
                                              const int& thickness);

    std::vector<FlaskLine>
    pos_pair_to_map_arrow(const std::pair<Eigen::Vector3d, Eigen::Vector3d>& pos_pair,
                          const cv::Scalar& color,
                          const int& thickness);

    FlaskText pos_str_to_map_text(const std::string& str,
                                  const Eigen::Vector3d& pos,
                                  const cv::Scalar& color,
                                  const double& scale);

private:
    param::ParamVisitor param_visitor;
};

class FlaskStream {
public:
    // 静态对象，唯一指针，应该避免多重定义
    FlaskStream& operator<<(const char* str) {
        this->logs.emplace_back(str);
        return *this;
    }

    FlaskStream& operator<<(const std::string& str) {
        this->logs.push_back(str);
        return *this;
    }

    FlaskStream& operator<<(const FlaskPoint& pt) {
        this->pts.push_back(pt);
        return *this;
    }

    FlaskStream& operator<<(const FlaskLine& line) {
        this->lines.push_back(line);
        return *this;
    }

    FlaskStream& operator<<(const std::vector<FlaskLine>& lines) {
        for (const auto& line: lines) {
            this->lines.push_back(line);
        }
        return *this;
    }

    FlaskStream& operator<<(const FlaskText& text) {
        this->texts.push_back(text);
        return *this;
    }

    FlaskStream& operator>>(cv::Mat& img) {
        int cnt = 0;
        for (auto& str: this->logs) {
            cv::putText(img,
                        str,
                        { 20, 80 + cnt * 24 },
                        cv::FONT_HERSHEY_DUPLEX,
                        0.8,
                        { 0, 0, 255 });
            ++cnt;
        }
        for (auto& pt: this->pts) {
            cv::circle(img, pt.pt, pt.radius, pt.color, pt.thickness);
        }
        for (auto& line: this->lines) {
            cv::line(img, line.pt_pair.first, line.pt_pair.second, line.color, line.thickness);
        }
        for (auto& text: this->texts) {
            cv::putText(img,
                        text.str,
                        { int(text.pt.x), int(text.pt.y) },
                        cv::FONT_HERSHEY_DUPLEX,
                        text.scale,
                        text.color);
        }
        return *this;
    }

    void clear() {
        this->logs.clear();
        this->pts.clear();
        this->lines.clear();
        this->texts.clear();
    }

private:
    std::vector<std::string> logs;
    std::vector<FlaskPoint> pts;
    std::vector<FlaskLine> lines;
    std::vector<FlaskText> texts;
};
} // namespace ros2addon::debug