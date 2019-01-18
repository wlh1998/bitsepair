// calculator.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Expression.h"

using namespace std;

void test1() {
	for (int i = 0; i < 10; i++)
	{
		Expression exp;
		cout << exp.getProblemExpression()<<endl;
		cout << exp.getAns()<<endl;

	}
}
void test2() {
	Number n1(1, 1),
		n2(2, 3);
	cout << n1 << " " << n2 << endl;
	cout << n1 + n2 << endl;

}
void test3() {
	Expression exp[10];

	for (int i = 0; i < 10; i++)
	{
		cout << exp[i].getProblemExpression() << endl;
		cout << exp[i].getAns() << endl;
		cout << "exp[" << i << "]==exp[0]" << exp[i].compare(exp[0]) << endl;
	}
	cout << "——————————————————————" << endl;
	Expression exp1("1+2+3+4+5");
	Expression exp2("3+(1+2)+4+5 ");
	cout << exp1.compare(exp2) << endl;

	Expression exp3("1/6 +1/8");
	cout << exp3.getAns()<<endl;
}

void init() {
	srand(5);
}
int main()
{
	init();
	//Expression::powerSetting = false;
	test3();
	
    return 0;
}

