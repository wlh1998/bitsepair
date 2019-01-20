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
	//操作数栈，用于求解
	std::stack<Number> stack_opnum;
	//操作符栈，用于转换为后缀表达式
	std::stack<char> stack_op;
	//标准答案
	Number ans;
	//运算优先级矩阵。
	static const int opcmp[opNumber][opNumber];
	//运算符表。
	static const char op[opNumber];
	//初始化
	void init();
	//比较两个操作符，确定运算顺序
	int cmp(char first, char second);
	//输入一个字符，执行相应操作，弃用
	int processChar(char ch);
	//输入操作符，进行相应处理。
	int processOperator(char ch);
	//中缀转后缀
	int infixToPostfix();
	//计算结果
	int calculate();

public:
	//指数的表示方法。
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

