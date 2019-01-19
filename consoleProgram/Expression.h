#pragma once
#include <string>
#include "Number.h"
#include <stack>
class Expression
{
private:
	//true 使用^，false 使用 **
	

	//true 使用分数表示 false 使用小数表示。
	static bool fractionSetting;
	
	//最大数字
	static const int maxNumber = 100;
	//运算总数。
	static const int opNumber = 8;
	//题目字符串
	std::string problemExpression;
	//后缀表达式。
	std::string postfixExpression;
	std::stack<Number> stack_opnum;
	std::stack<char> stack_op;
	//标准答案
	Number ans;
	//运算优先级矩阵。
	static const int opcmp[opNumber][opNumber];
	static const char op[opNumber];

	void init();

	int cmp(char first, char second);

	int processChar(char ch);

	int processOperator(char ch);

	int infixToPostfix();

	

	int calculate();

public:
	static bool powerSetting;
	bool compare(Expression obj);

	//随机生成表达式。
	Expression();

	std::string randExpression();
	
	//输入表达式。
	Expression(std::string expression);
	
	std::string getProblemExpression();

	Number getAns();
	//
	~Expression();
};

