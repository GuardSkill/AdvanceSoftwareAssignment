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
	void ProcessData(int T) {         //ͨ����ֵ��ͼƬ���ж�ֵ��
		for (int i = 0; i <data.size(); i++) {
			if (data.at(i) > T)       //vector<int> data
				data.at(i) = 255;
			else
				data.at(i) = 0;
		}
	}
	void displayData()               //��ʾ����
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
	void getData()                   //��ȡ���ݼ�
	{
		char name[256] = "123.jpg";
		//cout << "�������ļ�����Ĭ��������123.jpg��";
		//cin >> name;
		img = imread(name);
		if(img.empty())
		{
			cout << "ͼ�����ʧ�ܣ�"<< endl;
			system("pause");
			exit(-1);
		}
		row = img.rows;
		col = img.cols;
		cout <<"ͼƬ�ߣ�"<< row <<"ͼƬ��"<< col <<"ͼƬͨ����"<<img.channels()<< endl;
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
	void saveData()                  //��������
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
 

