#pragma once
#include <stdio.h>
using namespace std;
#include <vector>
#include <iostream>

class GenerateT                                //阈值计算方式的父类
{
public:
	virtual int GenerateMethod() { return -1; };
};

class SelfSetT :public GenerateT                    //手动设置阈值方法
{
public:
	int GenerateMethod();
};
class IterateT:public GenerateT                    //迭代生成阈值的方法
{
public:
	int GenerateMethod(vector<int> data);
};
class MaxVarianceT:public GenerateT                //最大类间方差法
{
public:
	int GenerateMethod();
};