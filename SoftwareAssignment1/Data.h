#pragma once
#include "GenerateT.h"

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
	void displayData() { };          //��ʾ����
	void getData() { };              //��ȡ���ݼ�
	void saveData() { };             //��������
private:
	vector<int> data;
};


