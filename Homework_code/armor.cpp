#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>
#include <assert.h>
#include<cmath>
#define HSV_paras // last to do, intent for incubed parameter adjusting

template <int open_size = 1, int close_size = 3, int scalar_num = 2>
class armor_locker
{
private:
    cv::VideoCapture capture;
    cv::VideoWriter writer,checker;
    cv::Size Size;
    cv::Mat frame, layers[3];
    cv::Scalar *scal_arr;
    cv::Mat open_element, close_element;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::RotatedRect> VECREC;
    std::vector<int> index;
    double area_lb=20, area_ub=400, max_angle=15, dist_thres=150, w_hratio=0.7;

    double get_dist2d(cv::Point2f A, cv::Point2f B)
    {
        double distance;
        distance = sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y), 2));
        return distance;
    }

    void masks(cv::Mat &drawer, int a, int b)
    {
        cv::Rect boudingRect = VECREC[index[a]].boundingRect2f() | VECREC[index[b]].boundingRect2f();
        cv::rectangle(drawer, boudingRect, cv::Scalar(255, 40, 40),2);
    } // incubed with step 3

    void color_Flux(cv::Mat &src, cv::Scalar arr[])
    {
        int len = scalar_num / 2;
        cv::Mat *mask = new cv::Mat[len];
        assert(src.channels() == 3);
        cv::Mat ult_mask = cv::Mat::zeros(cv::Size(src.cols, src.rows), CV_8UC1);
        for (int i = 0; i < len; i++)
        {
            cv::inRange(src, scal_arr[2 * i], scal_arr[2 * i + 1], mask[i]);
            ult_mask = ult_mask + mask[i] - ult_mask.mul(mask[i] / 255);
        }

        frame = ult_mask;
        return;
    } // step1

    void morph()
    {
        cv::morphologyEx(frame, frame, cv::MORPH_CLOSE, close_element);
        cv::morphologyEx(frame, frame, cv::MORPH_OPEN, open_element);
        return;
    } // step2

    void find_contour()
    {
        cv::Mat drawer = cv::Mat::zeros(Size, CV_8UC3); // make sure that it is empty
        assert(frame.channels() == 1);
        cv::findContours(frame, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

        for (int i = 0; i < contours.size(); i++)
        {
            cv::RotatedRect rect = cv::minAreaRect(contours[i]);
            VECREC.push_back(rect);
            if (cv::contourArea(contours[i]) < area_lb || cv::contourArea(contours[i]) > area_ub)
                continue;
            // rect.points()
            auto ratio = rect.boundingRect2f().size().aspectRatio(); //<1!
            if (ratio > w_hratio)
                continue;
            // then we pair remaining rects
            index.push_back(i);
        }
        printf("%d\t", index.size());//
        // pair

        //cases that there is no drawer
        assert(!drawer.empty());
        frame = drawer;
        return;
    }

    void operate()
    {
        cv::Mat image = frame.clone();
        cv::cvtColor(frame, frame, cv::COLOR_BGR2HSV);
        contours.clear();
        VECREC.clear();
        index.clear();
        assert(contours.empty() && VECREC.empty()&&index.empty()); // clean the vector first
        color_Flux(frame, scal_arr);                // frame--channels==1

        assert(frame.channels() == 1);
        morph();
        checker << frame;
        find_contour();

        assert(frame.channels() == 3);
        writer << frame + image;
    }

public:
    armor_locker(std::string &load_path, std::string &dst_path)
    {
        // std::cout << load_path;
        capture.open(load_path);
        // cv::Mat abc;
        capture.read(frame);
        assert(!frame.empty());
        assert(frame.channels() == 3);
        Size = cv::Size(frame.cols, frame.rows);
        writer.open(dst_path, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 40, Size, true); // use open function to initalize rather than create
        // This is the final pictures after editon and adding
        checker.open("../checker.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 40, Size, false);
        scal_arr = new cv::Scalar[scalar_num];

        open_element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1 + 2 * open_size, 1 + 2 * open_size));
        close_element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1 + 2 * close_size, 1 + 2 * close_size));
    }
    void hsv_colors(cv::Scalar arr[], int len)
    {
        if (len != scalar_num)
        {
            printf("Error! Inequal number of scalars!\n");
            return;
        }
        for (int i = 0; i < len; i++)
            scal_arr[i] = arr[i];
        return;
    }

    void iteration()
    {
        while (true)
        {
            operate();
            capture >> frame;
            if (frame.empty())
                break;
        }
        writer.release();
        checker.release();
        return;
    }
};

int main()
{
    cv::Scalar arr[2] = {cv::Scalar(7, 75, 100), cv::Scalar(35, 255, 255)};
    int len = sizeof(arr) / sizeof(arr[0]);
    std::string load = "../armor.mp4", dst = "../locker.avi";
    armor_locker<1, 5, 2> nmsl(load, dst); // string type need namespace std;
    nmsl.hsv_colors(arr, len);
    nmsl.iteration();
    return 0;
}