#include <opencv2\opencv.hpp>
#include <string>
#include <iostream>
#include "../include/calibration.h"
#include "../include/undistort.h"

using namespace std;
using namespace cv;

/*
patternImgPath----�궨��ͼ�����ļ���·�����궨��ͼ���ļ�������0.jpg, 1.jpg...�����������
calibResultPath----������궨�ڲ������ļ�����·����fx, fy, cx,cy, �Լ�����ϵ��(k1,k2,p1,p2,k3 ���� k1,k2,k3,k4);
srcImgPath----����������ͼƬ����·�����������Ա궨�ͻ���У�������
boardSize----�궨���ڽǵ��к��и�����
CCalibration��ʵ��������궨���ܣ�calibration.run()ִ�ж�ȡ�궨��ͼƬ���ǵ��⡢�����ؾ�ȷ����������궨��������ͶӰ������궨�������ܣ�
CUndistort��ʵ�ֻ���У�����ܣ�undistort.run()ִ�ж�ȡ�ڲ���������ȡ����ͼ�񡢻���У������ʾУ��������ܡ�

*calibration.h, calibration.cpp��ʵ��������궨������CVģ�ͺ�Fisheyeģ�͡�Ĭ��ΪCVģ�ͣ��������ΪFisheyeģ�ͣ�
�뽫calibration.h�ļ��е�( #define CV )�滻Ϊ�� #define FISHEYE �����ɣ��ڲ��������ݺ궨����ִ�ж�Ӧ�ı궨�ͻ���У��ģ�ʹ��롣

*undistort.h, undistort.cpp��ʵ�ֻ���У��������CVģ�ͺ�Fisheyeģ�͡�
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