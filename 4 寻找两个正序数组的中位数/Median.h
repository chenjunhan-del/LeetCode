#pragma once
#include<iostream>

//以中位数为特征的数组类
class Median {
private:
	int* p;//使用new来保存数据
	int size;//数组的长度
	double median;//中位数

	//对当前的所有内容排序，并设置中位数的值
	void Sorted();

public:
	//默认构造函数，将所有值设为0
	Median();

	//构造函数，根据传入的数组设置
	Median(int arr[], int size_);

	//析构函数，释放所有内存
	~Median();

	//合并另一个Median对象，此操作会改变当前对象的值
	void Absorb(const Median& m1);

	//展示中位数
	void Show();
};

//Median类的操作函数
void MedianOperate();