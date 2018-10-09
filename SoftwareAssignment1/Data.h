#pragma once
#include "GenerateT.h"
#include "fstream"
#include <windows.h>
#include "opencv2\core.hpp"

#include "opencv2\highgui\highgui.hpp"

using namespace cv;
typedef unsigned char PixelType;
class Data
{
public:
	void ProcessData(int T) {         //通过阈值对图片进行二值化
		for (int i = 0; i <data.size(); i++) {
			if (data.at(i) > T)       //vector<int> data
				data.at(i) = 255;
			else
				data.at(i) = 0;
		}
	}
	void displayData()               //显示数据
	{
		int t = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				for (int k = 0; k < img.channels(); k++)
				{
					img.at<Vec3b>(i, j)[k]=data.at(t);
					t++;
				}
			}
		}
		imshow("Display", img);
		waitKey(500);
	};           
	void getData()                   //获取数据集
	{
		char name[256] = "123.jpg";
		//cout << "请输入文件名（默认请输入123.jpg）";
		//cin >> name;
		img = imread(name);
		if(img.empty())
		{
			cout << "图像加载失败！"<< endl;
			system("pause");
			exit(-1);
		}
		row = img.rows;
		col = img.cols;
		cout <<"图片高："<< row <<"图片宽："<< col <<"图片通道："<<img.channels()<< endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				for (int k = 0; k < img.channels(); k++)
				{
					data.push_back(img.at<cv::Vec3b>(i, j)[k] - 0);
				}
			}
		}

		if(data.size() / img.channels() ==col*row)
		cout << "data was loaded successfully"<<endl;
	};
	void saveData()                  //保存数据
	{
		Mat img(row, col, CV_8UC3);
		int t = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				for (int k = 0; k < img.channels(); k++)
				{
					img.at<Vec3b>(i, j)[k] = data.at(t);
					t++;
				}
			}
		}
		imwrite("save.jpg", img);
		img.release();
	};
	~Data() 
	{
		if (!img.empty())
		{
			img.release();
		}
	}
private:
	Mat img;
	vector<int> data;
	int row;
	int col;
};
 

