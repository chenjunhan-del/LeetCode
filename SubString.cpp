#include "SubString.h"
#include<iostream>

SubString::SubString() {
	begin = nullptr;
	end = nullptr;
	string[0] = '\0';
	length = 0;
	much = 0;
	sublength = 0;
}

SubString::SubString(char* string_) {
	strcpy_s(string, string_);
	length = std::strlen(string_);
	begin = string;
	end = string + length - 1;
	much = 1;
	sublength = 1;
}

bool SubString::IfUnique() {
	char* p1 = begin;
	char* p2 = end;

	//��p1Ϊ��׼
	while (p1 < end) {
		//�ӽ�β��p1����
		while (p2 > p1) {
			if (*p2 == *p1) {
				return false;//��ͬ�򷵻�false
			}
			p2--;
		}
		//һ����������˵����ǰû���ظ�

		p1++;
		p2 = end;//�������ûؽ�β
	}
	//����ѭ������˵��û���ظ�

	return true;
}

void SubString::Walk() {
	int result;//�����м���

	//��������С�ڳ���ʱ
	while (much < length) {
		begin = string;
		end = string + length - much;
		//���úó�ʼ�ͽ�β

		while (end <= string + length - 1) {
			//�����ǰ���ַ����ǲ��ظ���
			if (IfUnique()) {
				result = (end - begin) / sizeof(char) + 1;
				if (result > sublength) {
					sublength = result;
				}
			}

			begin++;
			end++;
		}

		much++;
	}

	Reset();
}

void SubString::Reset() {
	begin = string;
	end = string + length - 1;
	much = 1;
}

int SubString::Get_sublength() {
	return sublength;
}

void SubStringOperate() {
	using std::cout;
	using std::cin;
	using std::endl;

	char string[200];

	cout << "������һ���ַ�����";
	cin.getline(string, 200);

	if (string[0] == '\0') {
		cout << "���ظ��ַ���Ӵ�����Ϊ0��\n";
		return;
	}

	SubString s1(string);
	s1.Walk();
	cout << "���ظ��ַ���Ӵ�����Ϊ��" << s1.Get_sublength() << endl;
}
