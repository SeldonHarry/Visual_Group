// This is about ascertain the position and contour of the apple. However, Using trackbar to modify the parameters is yet to accomplished.
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>
#include <assert.h>

int open_size = 3;
int close_size = 6;

cv::Mat color_flux(cv::Mat &src, cv::Scalar arr[], int len)
{
    // input an arbitrary number of scalars in hsv
    cv::Mat *masks = new cv::Mat[len];
    assert(src.channels() == 3);
    cv::Mat ult_mask = cv::Mat::zeros(cv::Size(src.cols, src.rows), CV_8UC1);
    for (int i = 0; i < len; i++)
    {
        cv::inRange(src, arr[2 * i], arr[2 * i + 1], masks[i]);
        ult_mask = ult_mask + masks[i] - ult_mask.mul(masks[i] / 255);
    }

    return ult_mask;
}

int get_ctr_idx(const std::vector<std::vector<cv::Point>> &ctr)
{
    int *ctr_size = new int[ctr.size()];
    for (int i = 0; i < ctr.size(); i++)
        ctr_size[i] = cv::contourArea(ctr[i]);

    int idx = std::max_element(ctr_size, ctr_size + ctr.size()) - ctr_size;

    return idx;
}

int main()
{
    cv::Mat img = cv::imread("../image/apple.png");
    cv::Mat HSV_img;
    assert(img.channels() == 3);

    cv::cvtColor(img, HSV_img, cv::COLOR_BGR2HSV);
    cv::Scalar arr[4] = {cv::Scalar(0, 150, 100), cv::Scalar(28, 255, 255),
                         cv::Scalar(156, 43, 46), cv::Scalar(180, 255, 255)}; // the scalar of red
                                                                              // These are the paras
    cv::Mat flux = color_flux(HSV_img, arr, sizeof(arr) / sizeof(arr[0]));
    cv::Mat open_element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2 * open_size + 1, 2 * open_size + 1));
    cv::Mat close_element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2 * close_size + 1, 2 * close_size + 1));

    // close and open
    cv::morphologyEx(flux, flux, cv::MORPH_OPEN, open_element);
    cv::morphologyEx(flux, flux, cv::MORPH_CLOSE, close_element);

    std::vector<std::vector<cv::Point>> contour;
    cv::Mat drawer = cv::Mat::zeros(cv::Size(flux.cols, flux.rows), CV_8UC3);

    cv::findContours(flux, contour, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
    int id = get_ctr_idx(contour);
    cv::drawContours(drawer, contour, id, cv::Scalar(125, 71, 0), 2);
    cv::rectangle(drawer, cv::boundingRect(contour[id]), cv::Scalar(255, 255, 255), 3);

    cv::imwrite("../image/processed_apple.png", img + drawer);
    cv::imshow("result", img + drawer);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}