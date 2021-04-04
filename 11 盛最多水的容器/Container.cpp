#include"Container.h"
#include<iostream>

Container::Container() {
	size = 2;
	width = 1;
	begin = nums;
	end = begin + 1;
}

Container::Container(int arr[], int size_) {
	//�洢����
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
	//�����ʼ�մ��ڵ���1ʱ
	while (width >= 1) {
		//�Խ�βָ��Ϊ��׼������û��Խ��ʱ
		while (end <= nums + size - 1) {
			//�����ǰ�Ľ����result��
			if (Calculate() >= result) {
				result = Calculate();
			}
			//ȫ������һ��
			end++;
			begin++;
		}
		//����ѭ��������Ӧ��һ
		width--;

		//���ûؿ�ͷ״̬
		begin = nums;
		end = begin + width;
	}
	//������Ӧ����������ֵ
}

void Container::Show() {
	std::cout << "���ʢˮ��Ϊ��" << result << std::endl;
}

void ContainerOperate() {
	int nums[200] = { 0 };
	int size = 0;

	std::cout << "�����Ҫ����������֣�";
	std::cin >> size;
	for (int i = 0; i < size; i++) {
		std::cout << "�������" << i + 1 << "�����֣�";
		std::cin >> nums[i];
	}

	Container c1(nums, size);
	c1.Walk();
	c1.Show();
}
