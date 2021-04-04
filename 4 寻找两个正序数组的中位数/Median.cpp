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
	int* temp = nullptr;//��ʹ��new�����ڴ�
	int merged_size = size + m1.size;//�ϲ����ܳ���
	int* p1;//ָ��Ҫ�����ֵ
	temp = new int[merged_size];
	p1 = temp;


	//�Ȱѵ�ǰ�����ֵ���ȥ
	for (int i = 0; i < size; i++) {
		*p1 = p[i];
		p1++;
	}
	//�ٰ�m1�����ֵ���ȥ
	for (int i = 0; i < m1.size; i++) {
		*p1 = m1.p[i];
		p1++;
	}

	//�ѵ�ǰ����֮ǰ�洢���������
	delete[] p;
	size = merged_size;

	//tempҲ����new������
	p = temp;
	Sorted();
}

void Median::Sorted() {
	int* begin = p;//���ƿ���
	int* end = begin + 1;//���ƽ�β
	int temp;//����

	//��beginָ��û���ߵ�ĩβ
	while (begin < p + size - 1) {
		//endָ�����һ�飬�ҵ���Сֵ
		while (end <= p + size - 1) {
			if (*end < *begin) {
				temp = *end;
				*end = *begin;
				*begin = temp;
			}
			//С���򽻻���������ֵ

			end++;
		}
		//����ѭ���������һ��

		begin++;
		end = begin + 1;
	}
	//�������

	//������λ����ֵ
	if (size % 2 != 0) {
		median = double(p[(size - 1) / 2]);
	}
	else {
		median = (double(p[size / 2 - 1]) + double(p[size / 2])) / 2.0;
	}
}

void Median::Show() {
	std::cout << "��λ��Ϊ��" << median << std::endl;
}

void MedianOperate() {
	using std::cin;
	using std::cout;
	using std::endl;

	int* p;//��ʹ��new�����ڴ�
	int size;//��������
	cout << "��������ȣ�";
	cin >> size;
	p = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "�������" << i + 1 << "������";
		cin >> p[i];
	}
	Median m1(p, size);
	delete[] p;
	
	cout << "��������ȣ�";
	cin >> size;
	p = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "�������" << i + 1 << "������";
		cin >> p[i];
	}
	Median m2(p, size);

	m1.Absorb(m2);
	m1.Show();
}
