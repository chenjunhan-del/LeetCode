#pragma once
//无重复字符最长子串
class SubString {
private:
	char string[200];//存储的字符串
	char* begin;//决定开始
	char* end;//决定结尾
	int length;//存储的字符串的长度
	int sublength;//无重复最长子串的长度
	int much;//操作的可能次数

public:
	//默认构造函数，所有的均设为0
	SubString();

	//构造函数，为对应成员赋值
	SubString(char* string_);

	//确定当前子字符是否不重复
	bool IfUnique();

	//遍历整个字符串，并得到sublength的值
	void Walk();

	//重新设置回初始状态
	void Reset();

	//最长子字符串的值
	int Get_sublength();
};

//操作函数
void SubStringOperate();