#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>

using namespace std;

template <int height = 1080, int width = 1920>
class Camera
{
private:
    int n;                         // points
    Eigen::Matrix<double, 3, 4> I; // Inner parameters
    Eigen::Quaterniond q;
    Eigen::Matrix3d R; // Rotation
    Eigen::Vector3d T; // Transition
    Eigen::Matrix4d O; // outer parameter
    cv::Mat img;

    // vector<Eigen::Vector3d> world_cord;
    vector<Eigen::Vector2d> pixel_cord;
    vector<Eigen::Vector4d> ex_world_cord; // extended word cordinate
    vector<Eigen::Vector3d> ex_pixel_cord;

public:
    Camera()
    {
        I << 400., 0., 190., 0.,
            0., 400., 160., 0.,
            0., 0., 1., 0.;
        T << 2., 2., 2.;
        q = Eigen::Quaterniond(-0.5, 0.5, 0.5, -0.5); // mind the input order
        R = q.toRotationMatrix().transpose();         //  need to transpose
        O = Eigen::Matrix4d::Zero();

        O.block(0, 0, 3, 3) = R;
        O.block(0, 3, 3, 1) = -R * T; //
        O(3, 3) = 1;
    }
    void fetch_cord()
    {
        string file_name = "../points.txt";
        ifstream ifile(file_name);
        if (!ifile)
        {
            cerr << "No input!" << endl;
            return;
        }
        ifile >> n; // number of cords
        for (int i = 0; i < n; i++)
        {
            // Eigen::Vector3d vec;
            Eigen::Vector4d ex_vec;
            double a, b, c;
            ifile >> a >> b >> c;
            // vec << a, b, c;
            ex_vec << a, b, c, 1.;
            // world_cord.push_back(vec);//actually useless
            ex_world_cord.push_back(ex_vec);
        }
        ifile.close();
        return;
    }
    void shutter()
    {
        assert(n == ex_world_cord.size());
        for (int i = 0; i < ex_world_cord.size(); i++)
        {
            Eigen::Vector2d vec;
            Eigen::Vector3d ex_vec;
            ex_vec = I * O * ex_world_cord[i];
            double ratio = ex_vec[2];
            vec = ex_vec.block(0, 0, 2, 1) / ratio; // broadcast
            pixel_cord.push_back(vec);
        }
        return;
    }
    void printer()
    {
        assert(pixel_cord.size() == n);
        img = cv::Mat(cv::Size(width, height), CV_8UC3);
        for (int i = 0; i < pixel_cord.size(); i++)
        {
            cv::circle(img, cv::Point2d(pixel_cord[i][0], pixel_cord[i][1]), 1, cv::Scalar(40, 40, 255), 1);
        }
        cv::imwrite("../result.jpg", img);
        cv::imshow("picture", img);
        cv::waitKey(0);
        return;
    }
};

int main()
{
    Camera<900, 1300> art;
    art.fetch_cord();
    art.shutter();
    art.printer();
    return 0;
}