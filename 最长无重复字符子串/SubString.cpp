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

	//以p1为基准
	while (p1 < end) {
		//从结尾往p1遍历
		while (p2 > p1) {
			if (*p2 == *p1) {
				return false;//相同则返回false
			}
			p2--;
		}
		//一个遍历走完说明当前没有重复

		p1++;
		p2 = end;//重新设置回结尾
	}
	//整个循环走完说明没有重复

	return true;
}

void SubString::Walk() {
	int result;//保存中间结果

	//当可能性小于长度时
	while (much < length) {
		begin = string;
		end = string + length - much;
		//设置好初始和结尾

		while (end <= string + length - 1) {
			//如果当前子字符串是不重复的
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

	cout << "请输入一个字符串：";
	cin.getline(string, 200);

	if (string[0] == '\0') {
		cout << "无重复字符最长子串长度为0！\n";
		return;
	}

	SubString s1(string);
	s1.Walk();
	cout << "无重复字符最长子串长度为：" << s1.Get_sublength() << endl;
}
