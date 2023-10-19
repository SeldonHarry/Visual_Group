#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <vector>
#include <assert.h>

int main()
{
    // 0.994363i + -0.0676645j + -0.00122528k + -0.0816168

    // cv::Vec4d q(0.994363, -0.0676645, -0.00122528, -0.0816168);

    // cv::Rodrigues(q, rotateMat);

    Eigen::Quaterniond Eq(-0.0816168, 0.994363, -0.0676645, -0.00122528);
    Eigen::Matrix3d Rotate = Eq.toRotationMatrix().transpose();
    // std::cout << "CV std:\n"
    //           << rotateMat << std::endl;
    std::cout << "Eigen std:\n"
              << Rotate << std::endl;
    cv::Mat rotateMat(Rotate.rows(), Rotate.cols(), CV_64F, Rotate.data());
    std::cout << "Copy:\n"
              << rotateMat << std::endl;

    std::vector<cv::Point2d> pixel_cord{
        {575.508, 282.175},
        {573.93, 331.819},
        {764.518, 337.652},
        {765.729, 286.741}}; // Grammer of intialize
    // pixel_cord.push_back(cv::Point2f(575.508, 282.175));
    // pixel_cord.push_back(cv::Point2f(573.93, 331.819));
    // pixel_cord.push_back(cv::Point2f(764.518, 337.652));
    // pixel_cord.push_back(cv::Point2f(765.729, 286.741));
    // pixel_cord.insert(pixel_cord.end(),{{575.508, 282.175},
    //                   {573.93, 331.819},
    //                   {764.518, 337.652},
    //                   {765.729, 286.741}});
    assert(pixel_cord.size() == 4);
    const std::vector<cv::Point3d> world_cord{
        {-0.115, 0.0265, 0.},
        {-0.115, -0.0265, 0.},
        {0.115, -0.0265, 0.},
        {0.115, 0.0265, 0.}};

    // Eigen::Matrix<double, 3, 3> Camera_I;
    // Camera_I << 1.4142055480888289e+03, 0., 6.5792667877101735e+02, 0., 1.4137212634286254e+03, 4.0455967287503142e+02, 0., 0., 1.; // 注意储存顺序

    // cv::Mat camera_i(Camera_I.rows(), Camera_I.cols(), CV_64F, Camera_I.data());
    cv::Mat camera_i = (cv::Mat_<double>(3, 3) << 1.4142055480888289e+03, 0., 6.5792667877101735e+02,
                        0., 1.4137212634286254e+03, 4.0455967287503142e+02,
                        0., 0., 1.); // 这样的初始化则是符合知觉的
    // cv::transpose(camera_i, camera_i);
    cv::Mat dist_coeff = (cv::Mat_<double>(5, 1) << -1.5713532786218060e-01,
                          3.3883933349759310e-01,
                          7.0103028435554145e-04,
                          -2.9035486504482461e-04,
                          -4.2372708010388316e-01); // Note the std grammer here
    std::cout << "dist_coeff:\n"
              << dist_coeff << std::endl;
    cv::Mat rvec, tvec; // wait for solving
    cv::solvePnP(world_cord, pixel_cord, camera_i, dist_coeff, rvec, tvec);
    std::cout << "tvec:\n"
              << tvec << std::endl;
    std::cout << "rvec:\n"
              << rvec << std::endl;
    cv::Mat RR; // to verify
    cv::Rodrigues(rvec, RR);
    std::cout << "q:\n"
              << RR << std::endl; // 正确的获取四元数的办法
    cv::Mat camera_cord = rotateMat * cv::Vec3d(world_cord[0]) + tvec;
    std::cout << "cameracord:\n"
              << camera_cord << "\n"
              << camera_cord.cols << std::endl;
    cv::Mat pixel = camera_i * camera_cord;
    std::cout << "check:\n"
              << camera_i << std::endl;
    std::cout << "pixel:\t" << pixel.at<double>(0, 0) << "\t" << pixel.at<double>(1, 0) << "\t" << pixel.at<double>(2, 0) << std::endl;

    cv::Point2d center = (pixel_cord[0] + pixel_cord[1] + pixel_cord[2] + pixel_cord[3]) / 4;
    cv::Point3d p(center.x, center.y, 1.);
    p = p * pixel.at<double>(2, 0);
    cv::Mat inv1, inv2;
    cv::invert(camera_i, inv1);
    cv::invert(rotateMat, inv2);
    cv::Mat world = inv2 * (inv1 * cv::Vec3d(p) - tvec) - tvec;
    std::cout << "project:\n"
              << world << std::endl;
    return 0;
}