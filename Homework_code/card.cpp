#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>
#include <assert.h>

int open_size = 5;
int close_size = 3;

cv::Mat Color_Flux(cv::Mat &src, cv::Scalar arr[], int len)
{
    //@brief len is the number of selected HSV colors
    cv::Mat *masks = new cv::Mat[len]; // unkown size?
    assert(src.channels() == 3);
    cv::Mat ult_mask = cv::Mat::zeros(cv::Size(src.cols, src.rows), CV_8UC1);
    for (int i = 0; i < len; i++)
    {
        cv::inRange(src, arr[2 * i], arr[2 * i + 1], masks[i]);
        // assert(ult_mask.size() == masks[i].size());
        ult_mask = ult_mask + masks[i] - ult_mask.mul(masks[i] / 255);
    }

    // printf("%d\n", len);
    return ult_mask;
}

int get_contour_idx(const std::vector<std::vector<cv::Point>> &ctr)
{
    int *ctr_size = new int[ctr.size()];
    for (int i = 0; i < ctr.size(); i++)
    {
        ctr_size[i] = cv::contourArea(ctr[i]);
    }
    int idx = std::max_element(ctr_size, ctr_size + ctr.size()) - ctr_size;
    return idx;
}

int main()
{
    cv::Mat img = cv::imread("../image/005.jpg");
    cv::Mat HSV_img;
    cv::cvtColor(img, HSV_img, cv::COLOR_BGR2HSV);
    cv::Scalar arr[2] = {cv::Scalar(107, 100, 100), cv::Scalar(120, 255, 255)};

    cv::Mat flux = Color_Flux(HSV_img, arr, sizeof(arr) / sizeof(arr[0]));

    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2 * open_size + 1, 2 * open_size + 1));

    cv::morphologyEx(flux, flux, cv::MORPH_CLOSE, element);

    element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2 * close_size + 1, 2 * close_size + 1));

    cv::morphologyEx(flux, flux, cv::MORPH_OPEN, element);

    std::vector<std::vector<cv::Point>> contour;
    std::vector<cv::Point> poly;
    cv::findContours(flux, contour, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    int id = get_contour_idx(contour);
    double cnt_len = cv::arcLength(contour[id], true);

    cv::Mat drawer = cv::Mat::zeros(cv::Size(img.cols, img.rows), CV_8UC3);
    cv::approxPolyDP(contour[id], poly, 0.02 * cnt_len, true);
    cv::drawContours(drawer, std::vector<std::vector<cv::Point>>{poly}, 0, cv::Scalar(255, 255, 255), 2);

    cv::imwrite("../image/car license5.png", img + drawer);
    cv::imshow("aa", drawer + img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}