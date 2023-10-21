#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <vector>
#include <assert.h>

class Location
{
private:
    Eigen::Quaterniond Eq;
    cv::Mat RotateMat;
    std::vector<cv::Point2d> pixel_cord;
    std::vector<cv::Point3d> world_cord;
    cv::Mat camera_i;
    cv::Mat dist_coeff;
    cv::Mat rvec, tvec; // Wait for solving
    double fetch_Zc()
    {
        // use when the surface is certain
        assert(pixel_cord.size() == 4 && world_cord.size() == 4);
        cv::Mat camera_cord = RotateMat * cv::Vec3d(world_cord[0]) + tvec;
        cv::Mat pixel = camera_i * camera_cord;
        return pixel.at<double>(2, 0);
    }

public:
    Location()
    {
        pixel_cord.insert(pixel_cord.end(), {{575.508, 282.175},
                                             {573.93, 331.819},
                                             {764.518, 337.652},
                                             {765.729, 286.741}});
        world_cord.insert(world_cord.end(), {{-0.115, 0.0265, 0.},
                                             {-0.115, -0.0265, 0.},
                                             {0.115, -0.0265, 0.},
                                             {0.115, 0.0265, 0.}});
        Eq = Eigen::Quaterniond(-0.0816168, 0.994363, -0.0676645, -0.00122528); // Eq.matrix() to transform
        RotateMat = cv::Mat(3, 3, CV_64F, Eq.matrix().data());
        dist_coeff = (cv::Mat_<double>(5, 1) << -1.5713532786218060e-01,
                      3.3883933349759310e-01,
                      7.0103028435554145e-04,
                      -2.9035486504482461e-04,
                      -4.2372708010388316e-01);
        camera_i = (cv::Mat_<double>(3, 3) << 1.4142055480888289e+03, 0., 6.5792667877101735e+02,
                            0., 1.4137212634286254e+03, 4.0455967287503142e+02,
                            0., 0., 1.);
        assert(pixel_cord.size() == 4 && world_cord.size() == 4);
    }
    void Solve()
    {
        assert(pixel_cord.size() == 4 && world_cord.size() == 4);
        cv::solvePnP(world_cord, pixel_cord, camera_i, dist_coeff, rvec, tvec);
        std::cout
            << "tvec:\n"
            << tvec << std::endl;
        return;
    }
    cv::Point3d clac(cv::Point2d center)
    {
        assert(pixel_cord.size() == 4 && world_cord.size() == 4);
        cv::Point3d pixel(center.x, center.y, 1.);
        pixel = pixel * fetch_Zc();
        cv::Mat inv1, inv2;
        cv::invert(camera_i, inv1);
        cv::invert(RotateMat, inv2);
        cv::Mat world = inv2 * (inv1 * cv::Vec3d(pixel) - tvec) - tvec;
        return cv::Point3d(world.at<double>(0, 0), world.at<double>(1, 0), world.at<double>(2, 0));
    }
};

int main()
{
    Location nmsl;
    // nmsl.init_para();
    nmsl.Solve();
    std::vector<cv::Point2d> rect{
        {575.508, 282.175},
        {573.93, 331.819},
        {764.518, 337.652},
        {765.729, 286.741}};
    cv::Point2d center = (rect[0] + rect[1] + rect[2] + rect[3]) / 4;
    cv::Point3d ans = nmsl.clac(center);

    std::cout << "ANS:\n"
              << ans << std::endl;
    return 0;
}