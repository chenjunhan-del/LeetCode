#pragma once
#include<iostream>
//给你一个包含n个整数的数组nums，
//判断nums中是否存在三个元素a,b,c
//使得a+b+c=0?请找到所有不重复的三元组

//数组类Array
class Array {
private:
	int nums[200] = { 0 };//保存整数的数组
	int size;//真正的长度
	int* begin;//指向最前面的整数
	int* mid;//指向中间的整数
	int* end;//指向最后的整数
	int store[200][3] = { {100,101,102} };//保存结果
	int much;//指出有多少种可能

public:
	//默认构造函数，所有值设为0
	Array();

	//构造函数，根据传入的数组分配值
	Array(int arr[], int size_);

	//遍历整个数组，求得所有可能并放入store数据成员内
	void Walk();

	//判断当前指向的数是否和为零
	bool IfZero();

	//将当前的数字存入store数组内
	void Restore();

	//判断是否与之前情况重复
	bool IfUnique();

	//展示所有的内容
	void Show();
};

//Array类的实验函数
void ArrayOperate();