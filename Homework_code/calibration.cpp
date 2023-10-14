#include <iostream>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

using namespace std;

template <int board_w, int board_h, int sample_num> // 9,6
class Calibrate
{
private:
    cv::Size img_Size, square_Size, board_size;
    int is_found = 0, num_samples, cnt = 0;
    double calibratedata;
    cv::Mat src, drawer, gray_img;
    vector<cv::Point2f> temp4pixel_cord;
    vector<vector<cv::Point2f>> pixel_cord;
    cv::Mat camera_mat;
    cv::Mat dist_coeff;
    vector<cv::Point3f> temp_grid_cord;
    vector<vector<cv::Point3f>> grid_cord;
    vector<cv::Mat> rvecs, tvecs; // rotation vectors? and transition vectors

public:
    Calibrate()
    {
        num_samples = sample_num;
        board_size = cv::Size(board_w, board_h);
        camera_mat = cv::Mat(3, 3, CV_32FC1, cv::Scalar::all(0));
        dist_coeff = cv::Mat(1, 5, CV_32FC1, cv::Scalar::all(0));
        square_Size = cv::Size(10, 10);
    }
    void fetch_process_pic(const string &path)
    {
        for (int i = 0; i < num_samples; i++)
        {
            string p = path + "/" + to_string(i) + ".jpg"; //
            src = cv::imread(path + "/" + to_string(i) + ".jpg");
            cout << p << endl; //
            if (i == 0)
                img_Size = cv::Size(src.cols, src.rows);

            is_found = cv::findChessboardCorners(src, board_size, temp4pixel_cord);
            if (!is_found)
                continue;
            else
                cnt++;
            cv::cvtColor(src, gray_img, cv::COLOR_BGR2GRAY);
            cv::find4QuadCornerSubpix(gray_img, temp4pixel_cord, cv::Size(5, 5));
            pixel_cord.push_back(temp4pixel_cord);
            temp4pixel_cord.clear();
        }
        printf("Successfully loaded: %d\n", cnt);
    }
    void calibration()
    {
        for (int j = 0; j < board_h; j++)
        {
            for (int k = 0; k < board_w; k++)
            {
                cv::Point3f pt;
                pt.x = k * square_Size.width;
                pt.y = j * square_Size.height;
                pt.z = 0;
                temp_grid_cord.push_back(pt);
            }
        }
        for (int i = 0; i < cnt; i++)
            grid_cord.push_back(temp_grid_cord); // to push n times in order to align
        // printf("Num%d\n", cnt);//
        cout << img_Size << endl;
        assert(grid_cord.size() == pixel_cord.size());
        calibratedata = cv::calibrateCamera(grid_cord, pixel_cord, img_Size, camera_mat, dist_coeff, rvecs, tvecs);
        printf("rvecsSize:\t%d\n", rvecs.size());
        cout << camera_mat << endl;//
    }
    void save_data()
    {
        ofstream ofile("info.txt");
        if (!ofile.is_open())
        {
            cerr << "Fail to open file!" << endl;
            return;
        }
        ofile.close();
        FILE *file = fopen("../info.txt", "w");
        fprintf(file, "Calibratedata:\t%.5lf\n", calibratedata);
        fprintf(file, "cameraMat:\n");
        for (int i = 0; i < camera_mat.rows; i++)
        {
            for (int j = 0; j < camera_mat.cols;j++)
                fprintf(file, "%.4lf , ", camera_mat.at<double>(i,j));
            fprintf(file, "\n");
        }
        fprintf(file, "distcoeffs:\n");
        for (int i = 0; i < dist_coeff.cols;i++){
            fprintf(file, "%.4lf,\n", dist_coeff.at<double>(i));
        }
            fclose(file);
    }
};

int main()
{
    Calibrate<9, 6, 41> nmsl;
    nmsl.fetch_process_pic("../chess");
    nmsl.calibration();
    nmsl.save_data();
    return 0;
}