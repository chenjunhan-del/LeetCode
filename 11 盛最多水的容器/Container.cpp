#include"Container.h"
#include<iostream>

Container::Container() {
	size = 2;
	width = 1;
	begin = nums;
	end = begin + 1;
}

Container::Container(int arr[], int size_) {
	//存储数据
	for (int i = 0; i < size_; i++) {
		nums[i] = arr[i];
	}
	size = size_;
	width = size - 1;
	begin = nums;
	end = nums + size - 1;
}

int Container::Calculate() {
	if (*begin > *end) {
		return ((*end) * width);
	}
	else {
		return ((*begin) * width);
	}
}

void Container::Walk() {
	//当宽度始终大于等于1时
	while (width >= 1) {
		//以结尾指针为基准，当其没有越界时
		while (end <= nums + size - 1) {
			//如果当前的结果比result大
			if (Calculate() >= result) {
				result = Calculate();
			}
			//全部后移一格
			end++;
			begin++;
		}
		//跳出循环，则宽度应减一
		width--;

		//重置回开头状态
		begin = nums;
		end = begin + width;
	}
	//遍历完应该已求得最大值
}

void Container::Show() {
	std::cout << "最大盛水量为：" << result << std::endl;
}

void ContainerOperate() {
	int nums[200] = { 0 };
	int size = 0;

	std::cout << "请决定要输入多少数字：";
	std::cin >> size;
	for (int i = 0; i < size; i++) {
		std::cout << "请输入第" << i + 1 << "个数字：";
		std::cin >> nums[i];
	}

	Container c1(nums, size);
	c1.Walk();
	c1.Show();
}
