#include "stdafx.h"
#include "Expression.h"
#include <stack>
#include "Number.h"

#include <cstdlib>
#include <ctime>
using namespace std;
//
//#开始结束标记
bool Expression::powerSetting = true;
const char Expression::op[Expression::opNumber] = 
	{ '+','-','*','/','(',')','#','^' };
const int Expression::opcmp[Expression::opNumber][Expression::opNumber]
= {
{ 1, 1,-1,-1,-1, 1, 1,-1 },
{ 1, 1,-1,-1,-1, 1, 1,-1 },
{ 1, 1, 1, 1,-1, 1, 1,-1 },
{ 1, 1, 1, 1,-1, 1, 1,-1 },
{ -1,-1,-1,-1,-1, 0, 2,-1 },
{ 1, 1, 1, 1, 2, 1, 1, 1 },
{ -1,-1,-1,-1,-1, 2, 0,-1 },
{ 1, 1, 1, 1,-1, 1, 1,-1 }
};
void Expression::init() {
	while (!stack_opnum.empty()) {
		stack_opnum.pop();
	}
	while (!stack_op.empty()) {
		stack_op.pop();
	}
	postfixExpression = "";
	infixToPostfix();
	calculate();
}
//1 first > second
//2 first = second
//-1 first < second
//获取两个操作符的优先级。
int Expression::cmp(char first, char second) {
	int int_first = 0,
		int_second = 0;
	while (op[int_first] != first)
	{
		int_first++;
	}
	while (op[int_second] != second)
	{
		int_second++;
	}
	return opcmp[int_first][int_second];
}

int Expression::processChar(char ch) {
	return processOperator(ch);
}
int Expression::processOperator(char ch) {
	char topOperator = stack_op.top();
	int cmpans = cmp(topOperator, ch);
	if (cmpans == -1) {
		//新运算符优先级高
		stack_op.push(ch);
		return 0;
	}
	if (cmpans == 0)
	{
		stack_op.pop();
		return 0;
	}
	//先将栈顶元素弹出，再次尝试
	if (cmpans == 1)
	{
		postfixExpression.append(1,topOperator);
		stack_op.pop();
		if (processOperator(ch))
		{
			return 1;
		}
		return 0;
	}
	return 1;
}

int Expression::infixToPostfix(){
	//运算符，调用processOperator。
	//数字，扔入结果。
	stack_op.push('#');
	for (int i = 0; i < problemExpression.length(); i++)
	{
		if (problemExpression[i] != ' ')
		{
			bool flag = false;
			for (int j = 0; j < opNumber; j++)
			{
				if (problemExpression[i] == op[j])
				{
					flag = true;
					processOperator(problemExpression[i]);
					break;
				}
			}
			if (!flag)
			{
				do
				{
					postfixExpression.append(1, problemExpression[i]);
					i++;
				} while (problemExpression[i] >= '0' && problemExpression[i] <= '9');
				i--;
				postfixExpression.append(1, ' ');
			}
		}
	}
	processChar('#');
	return 0;
}
void tem(Expression obj) {

}
// true 相同
bool Expression::compare(Expression obj) {

	if (!(ans == obj.ans))
	{
		return false;
	}
	if (obj.postfixExpression == postfixExpression)
	{
		return true;
	}
	//查看符号序列是否相同

	int i = 0,
		j = 0;
	int postLength = postfixExpression.length();
	int postLength2 = obj.postfixExpression.length();
	while (i < postLength && j < postLength2) {
		while (postfixExpression[i] == ' ' || (postfixExpression[i] <= '9'
			&&postfixExpression[i] >= '0'))
		{
			i++;
		}
		while (obj.postfixExpression[j] == ' ' || (obj.postfixExpression[j] <= '9'
			&& obj.postfixExpression[j] >= '0'))
		{
			j++;
		}
		if (postfixExpression[i] != obj.postfixExpression[j])
		{
			return false;
		}
		i++;
		j++;
	}
	if (i != postLength || j != postLength2)
	{
		return false;
	}
	i = 0;
	j = 0;

	while (!stack_opnum.empty())
	{
		stack_opnum.pop();
	}
	while (!obj.stack_opnum.empty())
	{
		obj.stack_opnum.pop();
	}
	Number num1, num2, num3;
	Number num21, num22;
	i = 0;
	j = 0;
	while (i < postLength && j < postLength2 )
	{
		while (postfixExpression[i] <= '9' && postfixExpression[i] >= '0')
		{
			num1 = postfixExpression[i] - '0';
			while (postfixExpression[i + 1] <= '9' && postfixExpression[i + 1] >= '0')
			{
				i++;
				num1 = num1 * 10;
				num1 = num1 + (postfixExpression[i] - '0');
			}
			stack_opnum.push(num1);
			i++;
			while (postfixExpression[i] == ' ')
			{
				i++;
			}
		}

		while (obj.postfixExpression[j] <= '9' && obj.postfixExpression[j] >= '0')
		{
			num1 = obj.postfixExpression[j] - '0';
			while (obj.postfixExpression[j + 1] <= '9' && obj.postfixExpression[j + 1] >= '0')
			{
				j++;
				num1 = num1 * 10;
				num1 = num1 + (obj.postfixExpression[j] - '0');
			}
			obj.stack_opnum.push(num1);
			j++;
			while (obj.postfixExpression[j] == ' ')
			{
				j++;
			}
		}

		num2 = stack_opnum.top();
		stack_opnum.pop();
		num22 = obj.stack_opnum.top();
		obj.stack_opnum.pop();

		num1 = stack_opnum.top();
		stack_opnum.pop();

		num21 = obj.stack_opnum.top();
		obj.stack_opnum.pop();


		if (num1 == num21 && num2 == num22)
		{
			switch (postfixExpression[i])
			{
			case '+':
				stack_opnum.push(num1 + num2);
				obj.stack_opnum.push(num1 + num2);
				break;
			case '-':
				stack_opnum.push(num1 - num2);
				obj.stack_opnum.push(num1 - num2);
				break;
			case '*':
				stack_opnum.push(num1 * num2);
				obj.stack_opnum.push(num1 * num2);
				break;
			case '/':
				stack_opnum.push(num1 / num2);
				obj.stack_opnum.push(num1 / num2);
				break;
			case '^':
				num3 = 1;
				for (int j = 0; j < num2.getNumerator(); j++)
				{
					num3 = num3 * num1;
				}
				stack_opnum.push(num3);
				obj.stack_opnum.push(num3);
				break;

			default:
				break;
			}

		}
		else if (num1 == num22 && num2 == num21)
		{
			switch (postfixExpression[i])
			{
			case '+':
				stack_opnum.push(num1 + num2);
				obj.stack_opnum.push(num1 + num2);
				break;
			case '*':
				stack_opnum.push(num1 * num2);
				obj.stack_opnum.push(num1 * num2);
				break;
			case '-':
			case '/':
			case '^':
				return false;
				break;

			default:
				break;
			}

		}
		i++;
		j++;
	}
	if (i != postLength || j != postLength2)
	{
		return false;
	}
	return true;
}
//根据后缀，计算结果
int Expression::calculate()
{
	Number num1, num2, num3;

	for (int i = 0; i < postfixExpression.length(); i++)
	{
		if (postfixExpression[i] == ' ')
		{
			continue;
		}
		if (postfixExpression[i] <='9' && postfixExpression[i] >='0')
		{
			num1 = postfixExpression[i] - '0';
			while (postfixExpression[i+1] <= '9' && postfixExpression[i+1] >= '0')
			{
				i++;
				num1 = num1 * 10;
				num1 = num1 + (postfixExpression[i] - '0');
			}
			stack_opnum.push(num1);
			continue;
		}
		if (stack_opnum.empty())
		{
			return 2;
		}
		num2 = stack_opnum.top();
		stack_opnum.pop();
		if (stack_opnum.empty())
		{
			return 2;
		}
		num1 = stack_opnum.top();
		stack_opnum.pop();

		switch (postfixExpression[i])
		{
		case '+':
			stack_opnum.push(num1 + num2);
			break;
		case '-':
			stack_opnum.push(num1 - num2);
			break;
		case '*':
			stack_opnum.push(num1 * num2);
			break;
		case '/':
			stack_opnum.push(num1 / num2);
			break;
		case '^':
			num3 = 1;
			for (int j = 0; j < num2.getNumerator(); j++)
			{
				num3 = num3 * num1;
			}
			stack_opnum.push(num3);
			break;
		
		default:
			break;
		}
	}
	ans = stack_opnum.top();	
}
Expression::Expression()
{
	randExpression();
	init();
}
std::string Expression::randExpression()
{
	//srand(int(time(0)));
	
	problemExpression = to_string(rand()%maxNumber);	
	int n = rand() % 10 + 1;

	for (int i = 0; i < n; i++)
	{
		int m = rand() % opNumber;
		while (m == 4 || m == 5 || m == 6)
		{
			m = rand() % opNumber;
		}
		problemExpression.append(1,op[m]);
		//限制乘方的指数
		if (m == 7)
		{
			problemExpression.append(to_string(rand() % 3));
		}
		else
		problemExpression.append(to_string(rand()%maxNumber));
	}

	return problemExpression;
}
Expression::Expression(std::string expression)
{
	problemExpression = expression;
	init();
}

std::string Expression::getProblemExpression()
{
	/*
	string exp;
	exp = problemExpression;
	exp.append(" = ?");
	
	std::cout <<"后缀" << postfixExpression << endl;
	return exp;
	*/
	if (powerSetting)
	{
		return problemExpression;
	}
	string newExpression = problemExpression;
	int length = newExpression.length();
	for (int i = 0; i < length; i++)
	{
		if (newExpression[i] == '^')
		{
			newExpression[i] = '*';
			newExpression.insert(i,1,'*');
			length++;
		}
	}
	return newExpression;
}

Number Expression::getAns()
{
	return ans;
}


Expression::~Expression()
{
}
