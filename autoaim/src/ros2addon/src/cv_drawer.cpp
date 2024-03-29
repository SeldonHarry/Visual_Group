#include "cv_drawer.hpp"
#include "math/math.hpp"

namespace ros2addon::debug {
CvDrawer::CvDrawer(const param::ParamVisitor& param_visitor): param_visitor(param_visitor) {}

auto CvDrawer::draw_line(cv::Mat& image,
                         const cv::Point2f& pt1,
                         const cv::Point2f& pt2,
                         const cv::Scalar& color,
                         const int& thickness) -> void {
    cv::line(image, pt1, pt2, color, thickness);
}

auto CvDrawer::draw_lines(cv::Mat& image,
                          const std::vector<cv::Point2f>& pts,
                          const cv::Scalar& color,
                          const int& thickness,
                          const bool& closed) -> void {
    for (std::size_t i = 0; i < pts.size(); ++i) {
        if (!closed && i == pts.size() - 1) {
            break;
        }
        int p = (i + 1) % pts.size();
        cv::line(image, pts[i], pts[p], color, thickness);
    }
}

auto CvDrawer::draw_arrow(cv::Mat& image,
                          const cv::Point2f& pt1,
                          const cv::Point2f& pt2,
                          const cv::Scalar& color,
                          const int& thickness) -> void {
    cv::line(image, pt1, pt2, color, thickness);
    Eigen::Vector2d vec { pt2.x - pt1.x, pt2.y - pt1.y };
    Eigen::Vector2d vec_l = aimer::math::rotate(vec, M_PI / 4. * 3.) / 7.;
    cv::Point2f pt_l { pt2.x + (float)vec_l(0, 0), pt2.y + (float)vec_l(1, 0) };
    cv::line(image, pt2, pt_l, color, thickness);
    Eigen::Vector2d vec_r = aimer::math::rotate(vec, -M_PI / 4. * 3.) / 7.;
    cv::Point2f pt_r { pt2.x + (float)vec_r(0, 0), pt2.y + (float)vec_r(1, 0) };
    cv::line(image, pt2, pt_r, color, thickness);
}

cv::Scalar CvDrawer::heightened_color(const cv::Scalar& color, const double& z) {
    cv::Scalar res;
    for (int i = 0; i < 3; ++i) {
        res[i] = z >= 0. ? 255. - (255. - color[i]) * std::pow(0.5, z / FLASK_MAP_PETER_BY_BRIGHT)
                         : color[i] * std::pow(0.5, -z / FLASK_MAP_PETER_BY_BRIGHT);
    }
    return res;
}

FlaskPoint CvDrawer::pos_to_map_point(const Eigen::Vector3d& pos,
                                      const cv::Scalar& color,
                                      const int& radius,
                                      const int& thickness) {
    return FlaskPoint(
        { float(FLASK_MAP_MID_X
                + pos(0, 0)
                    * param::get_param<double>("auto-aim.debug.flask.map.pixel-per-meter",
                                               param_visitor)),
          float(FLASK_MAP_MID_Y
                - pos(1, 0)
                    * param::get_param<double>("auto-aim.debug.flask.map.pixel-per-meter",
                                               param_visitor)) },
        heightened_color(color, pos(2, 0)),
        radius,
        thickness);
}

std::vector<FlaskLine> CvDrawer::pts_to_map_lines(const std::vector<cv::Point2f>& pts,
                                                  const cv::Scalar& color,
                                                  const bool& closed,
                                                  const int& thickness) {
    // 一条一条放入
    std::vector<FlaskLine> lines;
    for (std::size_t i = 0; i < pts.size(); ++i) {
        int p = (i + 1) % pts.size();
        if (p == 0 && !closed) {
            break;
        }
        lines.emplace_back(std::pair<cv::Point2f, cv::Point2f>(pts[i], pts[p]), color, thickness);
    }
    return lines;
}

std::vector<FlaskLine> CvDrawer::poses_to_map_lines(const std::vector<Eigen::Vector3d>& poses,
                                                    const cv::Scalar& color,
                                                    const bool& closed,
                                                    const int& thickness) {
    // 一条一条放入
    std::vector<FlaskLine> lines;
    for (std::size_t i = 0; i < poses.size(); ++i) {
        int p = (i + 1) % poses.size();
        if (p == 0 && !closed) {
            break;
        }
        FlaskPoint pt1 = pos_to_map_point(poses[i], color, 0, 0);
        FlaskPoint pt2 = pos_to_map_point(poses[p], color, 0, 0);
        lines.emplace_back(std::pair<cv::Point2f, cv::Point2f>(pt1.pt, pt2.pt),
                           (pt1.color + pt2.color) / 2.,
                           thickness);
    }
    return lines;
}

std::vector<FlaskLine>
CvDrawer::pos_pair_to_map_arrow(const std::pair<Eigen::Vector3d, Eigen::Vector3d>& pos_pair,
                                const cv::Scalar& color,
                                const int& thickness) {
    // 一条一条放入
    std::vector<FlaskLine> lines;
    FlaskPoint pt1 = pos_to_map_point(pos_pair.first, color, 0, 0);
    FlaskPoint pt2 = pos_to_map_point(pos_pair.second, color, 0, 0);
    lines.emplace_back(std::make_pair(pt1.pt, pt2.pt), (pt1.color + pt2.color) / 2., thickness);
    Eigen::Vector2d vec { pt2.pt.x - pt1.pt.x, pt2.pt.y - pt1.pt.y };
    Eigen::Vector2d vec_l = aimer::math::rotate(vec, M_PI / 6. * 5.) / 7.;
    cv::Point2f pt_l { pt2.pt.x + (float)vec_l(0, 0), pt2.pt.y + (float)vec_l(1, 0) };
    lines.emplace_back(std::make_pair(pt2.pt, pt_l), pt2.color, thickness);
    Eigen::Vector2d vec_r = aimer::math::rotate(vec, -M_PI / 6. * 5.) / 7.;
    cv::Point2f pt_r { pt2.pt.x + (float)vec_r(0, 0), pt2.pt.y + (float)vec_r(1, 0) };
    lines.emplace_back(std::make_pair(pt2.pt, pt_r), pt2.color, thickness);
    return lines;
}

FlaskText CvDrawer::pos_str_to_map_text(const std::string& str,
                                        const Eigen::Vector3d& pos,
                                        const cv::Scalar& color,
                                        const double& scale) {
    return FlaskText(str, pos_to_map_point(pos, { 0., 0., 0. }, 0, .0).pt, color, scale);
}
} // namespace ros2addon::debug