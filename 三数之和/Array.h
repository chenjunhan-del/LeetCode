#pragma once
#include<iostream>
//����һ������n������������nums��
//�ж�nums���Ƿ��������Ԫ��a,b,c
//ʹ��a+b+c=0?���ҵ����в��ظ�����Ԫ��

//������Array
class Array {
private:
	int nums[200] = { 0 };//��������������
	int size;//�����ĳ���
	int* begin;//ָ����ǰ�������
	int* mid;//ָ���м������
	int* end;//ָ����������
	int store[200][3] = { {100,101,102} };//������
	int much;//ָ���ж����ֿ���

public:
	//Ĭ�Ϲ��캯��������ֵ��Ϊ0
	Array();

	//���캯�������ݴ�����������ֵ
	Array(int arr[], int size_);

	//�����������飬������п��ܲ�����store���ݳ�Ա��
	void Walk();

	//�жϵ�ǰָ������Ƿ��Ϊ��
	bool IfZero();

	//����ǰ�����ִ���store������
	void Restore();

	//�ж��Ƿ���֮ǰ����ظ�
	bool IfUnique();

	//չʾ���е�����
	void Show();
};

//Array���ʵ�麯��
void ArrayOperate();