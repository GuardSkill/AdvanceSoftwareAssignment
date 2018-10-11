#include "GenerateT.h"                              
/****** 不同阈值设置方法的实现  *****/

int SelfSetT::GenerateMethod(vector<int> data)                    //手动设置阈值方法
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
int Average_Tk1(vector<int> data,int TK)  //求新阈值
{
	int sumA=0 ,sumB=0 ,A=0 ,B = 0;           //sumA、sumB为灰度值，A、B统计数量用来求平均灰度值
	for (int i = 0; i<data.size(); i++)
	{
		if (data[i] <= TK)
		{
			A++; sumA = sumA + data[i];
		}
		else 
		{ B++; sumB = sumB + data[i]; }
	}
	return (sumA / A + sumB / B) / 2;
}

int IterateT::GenerateMethod(vector<int> data) 
{
	int Zmax = data[0], Zmin = data[0];
	for (int i = 0; i<data.size(); i++)
	{
		if (Zmax<data[i]) Zmax = data[i];
		if (Zmin>data[i]) Zmin = data[i];

	}
	int T0=(Zmax + Zmin) / 2;
	
	int Tk1 = Average_Tk1(data,T0);
	int e = 1;
	while (1)
	{
		if (T0 == Tk1 || T0 - Tk1<e) return Tk1;
		else
		{
			T0 = Tk1;
			Tk1 == Average_Tk1(data, Tk1);
		}
	}
	
	
};   //迭代生成阈值的方法

int  MaxVarianceT::GenerateMethod(vector<int> data) 
{ 
	float histogram[256] = { 0 };                   //histogram  
	for (int i = 0; i < data.size(); i++)
	{
		histogram[data[i]]++;
	}
	float u = 0;                                    //整幅图像的平均灰度
	for (int i = 0; i < 256; i++)
	{
		histogram[i] = histogram[i] / data.size();
		u += i * histogram[i]; 
	}
	int threshold;
	float maxVariance = 0;
	float w0 = 0, avgValue = 0;
	for (int i = 0; i < 256; i++)
	{
		w0 += histogram[i];  //假设当前灰度i为阈值, 0~i 灰度像素所占整幅图像的比例即前景比例
		avgValue += i * histogram[i]; //avgValue/w0 = u0

		float t = avgValue / w0 - u;  //t=u0-u
		float variance = t * t * w0 / (1 - w0);
		if (variance > maxVariance)
		{
			maxVariance = variance;
			threshold = i;
		}
	}
	return threshold;
};  //最大类间方差法