#include "GenerateT.h"                              
/****** ��ͬ��ֵ���÷�����ʵ��  *****/

int SelfSetT::GenerateMethod()                    //�ֶ�������ֵ����
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

int IterateT::GenerateMethod(vector<int> data) { return -1; };   //����������ֵ�ķ���
int  MaxVarianceT::GenerateMethod() { return -1; };  //�����䷽�