#include "Median.h"
#include<iostream>

Median::Median() {
	p = new int[1];
	p[0] = 0;
	size = 1;
	median = 0.0;
}

Median::Median(int arr[], int size_) {
	size = size_;
	p = new int[size];
	for (int i = 0; i < size; i++) {
		p[i] = arr[i];
	}
	Sorted();
}

Median::~Median() {
	delete[] p;
}

void Median::Absorb(const Median& m1) {
	int* temp = nullptr;//将使用new分配内存
	int merged_size = size + m1.size;//合并的总长度
	int* p1;//指向要填入的值
	temp = new int[merged_size];
	p1 = temp;


	//先把当前对象的值填进去
	for (int i = 0; i < size; i++) {
		*p1 = p[i];
		p1++;
	}
	//再把m1对象的值填进去
	for (int i = 0; i < m1.size; i++) {
		*p1 = m1.p[i];
		p1++;
	}

	//把当前对象之前存储的数据清空
	delete[] p;
	size = merged_size;

	//temp也是由new创建的
	p = temp;
	Sorted();
}

void Median::Sorted() {
	int* begin = p;//控制开端
	int* end = begin + 1;//控制结尾
	int temp;//交换

	//当begin指针没有走到末尾
	while (begin < p + size - 1) {
		//end指针遍历一遍，找到最小值
		while (end <= p + size - 1) {
			if (*end < *begin) {
				temp = *end;
				*end = *begin;
				*begin = temp;
			}
			//小于则交换这两个的值

			end++;
		}
		//跳出循环则进行下一轮

		begin++;
		end = begin + 1;
	}
	//排序完成

	//设置中位数的值
	if (size % 2 != 0) {
		median = double(p[(size - 1) / 2]);
	}
	else {
		median = (double(p[size / 2 - 1]) + double(p[size / 2])) / 2.0;
	}
}

void Median::Show() {
	std::cout << "中位数为：" << median << std::endl;
}

void MedianOperate() {
	using std::cin;
	using std::cout;
	using std::endl;

	int* p;//将使用new分配内存
	int size;//决定长度
	cout << "请决定长度：";
	cin >> size;
	p = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "请输入第" << i + 1 << "个数：";
		cin >> p[i];
	}
	Median m1(p, size);
	delete[] p;
	
	cout << "请决定长度：";
	cin >> size;
	p = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "请输入第" << i + 1 << "个数：";
		cin >> p[i];
	}
	Median m2(p, size);

	m1.Absorb(m2);
	m1.Show();
}
