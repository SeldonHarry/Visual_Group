#include<Eigen/Dense>
#include<Eigen/Core>
#include<iostream>
#include<fstream>

using namespace std;
string filename="dollar.txt";

const int x_n = 2, z_n = 1;
double *price;
class KF
{
private:
    int num_sample;
    double final_speed;
    Eigen::Matrix<double, x_n, x_n> A;
    Eigen::Matrix<double, x_n, 1> X;
    Eigen::Matrix<double, x_n, x_n> P;
    Eigen::Matrix<double, x_n, x_n> R;
    Eigen::Matrix<double, z_n, x_n> C; // guance
    Eigen::Matrix<double, z_n, z_n> Q;
    Eigen::Matrix<double, x_n, z_n> K;

public:
    KF(int num)
    {
        num_sample = num;
        ifstream ifile(filename);
        if (!ifile)
        {
            cerr << "No file !" << endl;
            return;
        }
        price = new double[num_sample];
        for (int i = 0; i < num_sample; i++)
            ifile >> price[i];
        ifile.close();

        A << 1, 1, 0, 1;
        X << price[0], 0;//days start from 0
        C << 1, 0;
        R << 2, 0, 0, 2;
        Q << 5;
    }
    void predict(){
        for (int i = 1; i < num_sample;i++){
            Eigen::Matrix<double, x_n, 1> X_k = A * X;
            P = A * P * A.transpose() + R;

            K = P * C.transpose() * (C * P * C.transpose() + Q).inverse();
            Eigen::Matrix<double, z_n, 1> Z;
            Z << price[i];
            X = X_k + K * (Z - C * X_k);
            P = (Eigen::Matrix<double, x_n, x_n>::Identity() - K * C) * P;

            printf("Price of Day%d: %.3lf\n", i, X[0]);
        }
        final_speed = X[1];
        
        //printf("Final Price: %.3lf", (date - num_sample) * final_speed + X[0]);
    }
    void printer(int days){
        //will output a series of predicted prices in the days given
        ofstream prediction("predict.txt");
        if (!prediction.is_open())
        {
            cerr << "Fail to open file!" << endl;
            return;
        }
        prediction.close();
        
        FILE *file = fopen("predict.txt", "w");
        for (int i = 0; i < days;i++){
            fprintf(file,"%.3lf\n", X[1] * (i + 1) + X[0]);
            printf("%.3lf\n", X[1] * (i + 1) + X[0]);
        }
        fclose(file);

    }
};

//suppose that the price of stock is fetched by a txt
int main(){
    int num = 30;
    KF nmsl(num);
    nmsl.predict();
    nmsl.printer(10);
    return 0;
}