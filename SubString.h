#pragma once
//���ظ��ַ���Ӵ�
class SubString {
private:
	char string[200];//�洢���ַ���
	char* begin;//������ʼ
	char* end;//������β
	int length;//�洢���ַ����ĳ���
	int sublength;//���ظ���Ӵ��ĳ���
	int much;//�����Ŀ��ܴ���

public:
	//Ĭ�Ϲ��캯�������еľ���Ϊ0
	SubString();

	//���캯����Ϊ��Ӧ��Ա��ֵ
	SubString(char* string_);

	//ȷ����ǰ���ַ��Ƿ��ظ�
	bool IfUnique();

	//���������ַ��������õ�sublength��ֵ
	void Walk();

	//�������ûس�ʼ״̬
	void Reset();

	//����ַ�����ֵ
	int Get_sublength();
};

//��������
void SubStringOperate();