#pragma once
#include<iostream>

//����λ��Ϊ������������
class Median {
private:
	int* p;//ʹ��new����������
	int size;//����ĳ���
	double median;//��λ��

	//�Ե�ǰ�������������򣬲�������λ����ֵ
	void Sorted();

public:
	//Ĭ�Ϲ��캯����������ֵ��Ϊ0
	Median();

	//���캯�������ݴ������������
	Median(int arr[], int size_);

	//�����������ͷ������ڴ�
	~Median();

	//�ϲ���һ��Median���󣬴˲�����ı䵱ǰ�����ֵ
	void Absorb(const Median& m1);

	//չʾ��λ��
	void Show();
};

//Median��Ĳ�������
void MedianOperate();