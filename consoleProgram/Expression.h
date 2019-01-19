#pragma once
#include <string>
#include "Number.h"
#include <stack>
class Expression
{
private:
	//true ʹ��^��false ʹ�� **
	

	//true ʹ�÷�����ʾ false ʹ��С����ʾ��
	static bool fractionSetting;
	
	//�������
	static const int maxNumber = 100;
	//����������
	static const int opNumber = 8;
	//��Ŀ�ַ���
	std::string problemExpression;
	//��׺���ʽ��
	std::string postfixExpression;
	std::stack<Number> stack_opnum;
	std::stack<char> stack_op;
	//��׼��
	Number ans;
	//�������ȼ�����
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

	//������ɱ��ʽ��
	Expression();

	std::string randExpression();
	
	//������ʽ��
	Expression(std::string expression);
	
	std::string getProblemExpression();

	Number getAns();
	//
	~Expression();
};

