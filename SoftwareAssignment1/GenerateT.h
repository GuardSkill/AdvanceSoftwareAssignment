#pragma once
#include <stdio.h>
using namespace std;
#include <vector>
#include <iostream>

class GenerateT                                //��ֵ���㷽ʽ�ĸ���
{
public:
	virtual int GenerateMethod() { return -1; };
};

class SelfSetT :public GenerateT                    //�ֶ�������ֵ����
{
public:
	int GenerateMethod();
};
class IterateT:public GenerateT                    //����������ֵ�ķ���
{
public:
	int GenerateMethod(vector<int> data);
};
class MaxVarianceT:public GenerateT                //�����䷽�
{
public:
	int GenerateMethod();
};