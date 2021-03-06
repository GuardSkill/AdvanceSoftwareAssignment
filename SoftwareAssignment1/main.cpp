//main.cpp: 定义控制台应用程序的入口点。
//
#include "Data.h"
int main()
{
	//InitSystem() { ...... }      //系统初始化
	Data someData;                 //数据处理存放类
	someData.loadData();            //获取数据
	someData.displayData();
	//Log() { ...... }             //日志记录

	GenerateT *gt;                 //基类指针
	MaxVarianceT T1;                   //手动设置方法子类实例
	gt = &T1;
	int T=gt->GenerateMethod(someData.getData());    //通过手动设置方法得到阈值
	cout << "阈值为:" << T << endl;
	someData.ProcessData(T);       //数据处理
	someData.displayData();        //展示数据
	someData.saveData();
    return 0;
}

