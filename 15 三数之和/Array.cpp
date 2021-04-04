#include "Array.h"
#include<iostream>

Array::Array() {
	size = 0;
	begin = mid = end = nums;
	much = 0;
}

Array::Array(int arr[], int size_) {
	for (int i = 0; i < size_; i++) {
		nums[i] = arr[i];
	}
	size = size_;
	begin = nums;
	mid = begin + 1;
	end = mid + 1;
}

void Array::Walk() {
	//以begin指针为基准，没有碰到倒数第三个数字时
	while (begin <= nums + size - 3) {
		//再以end指针为限制
		while (end <= nums + size - 1) {
			//移动中间的指针
			while (mid < end) {
				//判断此时的三个数是否为0，且不重复
				if (IfZero() && IfUnique()) {
					Restore();
				}
				mid++;
			}
			//跳出循环则从begin走到end

			mid = begin + 1;
			end++;
		}
		//跳出循环，重新设置为三个连续的内存

		begin++;
		mid = begin + 1;
		end = mid + 1;
	}
	//全部遍历走完
}

bool Array::IfZero() {
	if (*begin + *mid + *end == 0) {
		return true;
	}
	else {
		return false;
	}
}

void Array::Restore() {
	store[much][0] = *begin;
	store[much][1] = *mid;
	store[much][2] = *end;
	much++;
}

bool Array::IfUnique() {
	int check = 0;

	//控制遍历一行一行
	for (int i = 0; i <= much; i++) {
		//两个三元组之间互相比较
		for (int j = 0; j < 3; j++) {
			if (*begin == store[i][j]) {
				check++;
			}
			if (*mid == store[i][j]) {
				check++;
			}
			if (*end == store[i][j]) {
				check++;
			}
		}
		//跳出循环，重复次数是否大于等于3
		if (check >= 3) {
			return false;
		}
		check = 0;//将check归零
	}
	//遍历走完说明没有重复

	return true;
}

void Array::Show() {
	if (much == 0) {
		std::cout << "没有符合的情况！\n";
	}
	else {
		for (int i = 0; i < much; i++) {
			std::cout << "第" << i + 1 << "种组合：";
			std::cout << store[i][0] << "," << store[i][1] << "," << store[i][2] << std::endl;
		}
	}
}

void ArrayOperate() {
	using std::cout;
	using std::cin;
	using std::endl;

	int* p = nullptr;
	int size = 0;
	cout << "请决定要输入多少个数：";
	cin >> size;
	p = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "请输入第" << i + 1 << "个数：";
		cin >> p[i];
	}

	Array a1(p, size);
	a1.Walk();
	a1.Show();
}
