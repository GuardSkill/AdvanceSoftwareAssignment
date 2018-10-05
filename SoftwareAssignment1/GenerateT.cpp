#include "GenerateT.h"                              
/****** 不同阈值设置方法的实现  *****/

int SelfSetT::GenerateMethod()                    //手动设置阈值方法
{
	cout << "Please input The T(Threashold)" << endl;
	int x;
	cin >> x;
	if (x > 255 || x < 0)
	{
		cout << "error Input" << endl;
		exit(-1);
	}
	return x;
};                 

int IterateT::GenerateMethod(vector<int> data) { return -1; };   //迭代生成阈值的方法
int  MaxVarianceT::GenerateMethod() { return -1; };  //最大类间方差法