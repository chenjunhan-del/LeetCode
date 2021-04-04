#pragma once
#include<iostream>

//根据输入的数组确定最多能盛放多少水
class Container {
private:
	int nums[200] = { 0 };//存放输入的数组
	int size;//确定最长为多少
	int width;//确定当前的宽度
	int* begin;//指向开始的数
	int* end;//指向结尾的数
	int result = 0;//最终的结果

public:
	//默认构造函数，所有值均设为零
	Container();

	//构造函数，存储输入的数组
	Container(int arr[], int size_);

	//计算当前方式能存放多少水
	int Calculate();

	//遍历所有的可能性
	void Walk();

	//显示最大值
	void Show();
};

//Container类的实验函数
void ContainerOperate();