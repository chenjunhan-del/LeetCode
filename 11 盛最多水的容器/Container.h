#pragma once
#include<iostream>

//�������������ȷ�������ʢ�Ŷ���ˮ
class Container {
private:
	int nums[200] = { 0 };//������������
	int size;//ȷ���Ϊ����
	int width;//ȷ����ǰ�Ŀ��
	int* begin;//ָ��ʼ����
	int* end;//ָ���β����
	int result = 0;//���յĽ��

public:
	//Ĭ�Ϲ��캯��������ֵ����Ϊ��
	Container();

	//���캯�����洢���������
	Container(int arr[], int size_);

	//���㵱ǰ��ʽ�ܴ�Ŷ���ˮ
	int Calculate();

	//�������еĿ�����
	void Walk();

	//��ʾ���ֵ
	void Show();
};

//Container���ʵ�麯��
void ContainerOperate();