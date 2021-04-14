#include <opencv2\opencv.hpp>
#include <string>
#include <iostream>
#include "../include/calibration.h"
#include "../include/undistort.h"

using namespace std;
using namespace cv;

/*
patternImgPath----标定板图像存放文件夹路径（标定板图像文件名按照0.jpg, 1.jpg...如此命名）；
calibResultPath----摄像机标定内部参数文件保存路径，fx, fy, cx,cy, 以及畸变系数(k1,k2,p1,p2,k3 或者 k1,k2,k3,k4);
srcImgPath----相机拍摄测试图片保存路径，用来测试标定和畸变校正结果；
boardSize----标定板内角点行和列个数；
CCalibration类实现摄像机标定功能，calibration.run()执行读取标定板图片、角点检测、亚像素精确化、摄像机标定、计算重投影误差、保存标定参数功能；
CUndistort类实现畸变校正功能，undistort.run()执行读取内部参数、读取畸变图像、畸变校正、显示校正结果功能。

*calibration.h, calibration.cpp：实现摄像机标定，包含CV模型和Fisheye模型。默认为CV模型，如需更换为Fisheye模型，
请将calibration.h文件中的( #define CV )替换为（ #define FISHEYE ）即可，内部代码会根据宏定义来执行对应的标定和畸变校正模型代码。

*undistort.h, undistort.cpp：实现畸变校正，包含CV模型和Fisheye模型。
*/

int main()
{
   
    string patternImgPath="data/pattern/";
    string calibResultPath="data/results/";
    string srcImgPath="data/srcImg/img_right.JPG";
    Size boardSize=Size(9, 6);
    CCalibration calibration(patternImgPath, calibResultPath, boardSize);
    calibration.run();
    CUndistort undistort(srcImgPath, calibResultPath);
    undistort.run();
}