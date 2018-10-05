#pragma once
#include "GenerateT.h"

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
	void displayData() { };          //显示数据
	void getData() { };              //获取数据集
	void saveData() { };             //保存数据
private:
	vector<int> data;
};


