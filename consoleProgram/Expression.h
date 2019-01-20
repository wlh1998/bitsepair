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
	//������ջ���������
	std::stack<Number> stack_opnum;
	//������ջ������ת��Ϊ��׺���ʽ
	std::stack<char> stack_op;
	//��׼��
	Number ans;
	//�������ȼ�����
	static const int opcmp[opNumber][opNumber];
	//�������
	static const char op[opNumber];
	//��ʼ��
	void init();
	//�Ƚ�������������ȷ������˳��
	int cmp(char first, char second);
	//����һ���ַ���ִ����Ӧ����������
	int processChar(char ch);
	//�����������������Ӧ����
	int processOperator(char ch);
	//��׺ת��׺
	int infixToPostfix();
	//������
	int calculate();

public:
	//ָ���ı�ʾ������
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

