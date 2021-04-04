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
	//��beginָ��Ϊ��׼��û��������������������ʱ
	while (begin <= nums + size - 3) {
		//����endָ��Ϊ����
		while (end <= nums + size - 1) {
			//�ƶ��м��ָ��
			while (mid < end) {
				//�жϴ�ʱ���������Ƿ�Ϊ0���Ҳ��ظ�
				if (IfZero() && IfUnique()) {
					Restore();
				}
				mid++;
			}
			//����ѭ�����begin�ߵ�end

			mid = begin + 1;
			end++;
		}
		//����ѭ������������Ϊ�����������ڴ�

		begin++;
		mid = begin + 1;
		end = mid + 1;
	}
	//ȫ����������
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

	//���Ʊ���һ��һ��
	for (int i = 0; i <= much; i++) {
		//������Ԫ��֮�以��Ƚ�
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
		//����ѭ�����ظ������Ƿ���ڵ���3
		if (check >= 3) {
			return false;
		}
		check = 0;//��check����
	}
	//��������˵��û���ظ�

	return true;
}

void Array::Show() {
	if (much == 0) {
		std::cout << "û�з��ϵ������\n";
	}
	else {
		for (int i = 0; i < much; i++) {
			std::cout << "��" << i + 1 << "����ϣ�";
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
	cout << "�����Ҫ������ٸ�����";
	cin >> size;
	p = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "�������" << i + 1 << "������";
		cin >> p[i];
	}

	Array a1(p, size);
	a1.Walk();
	a1.Show();
}
