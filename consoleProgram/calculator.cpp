
// calculator.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include<time.h>
#include "Expression.h"

using namespace std;
//一些自测代码
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
//		cout << exp[i].getAns() << endl;
//		cout << "exp[" << i << "]==exp[0]" << exp[i].compare(exp[0]) << endl;
	}
	//cout << "——————————————————————" << endl;
	Expression exp1("1+2+3+4+5");
	Expression exp2("3+(1+2)+4+5 ");
	//cout << exp1.compare(exp2) << endl;

	Expression exp3("1/6 +1/8");
	//cout << exp3.getAns()<<endl;
}
//程序初始化。
void init() {
//	srand(1);
	srand((unsigned)time(0));
}
//生成num个不重复的题目，并将题目，答案保存至path中
int generateEpression(int num, string path) {

	FILE * file = fopen(path.c_str(), "w");

	Expression exp[1000];
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (exp[i].compare(exp[j]))
			{
				exp[i] = Expression();
				i--;
				break;
			}
		}
		//cout << i << endl;
	}
	for (int i = 0; i < num; i++)
	{
		fputs(exp[i].getProblemExpression().c_str(), file);
		if (exp[i].getAns().getDenominator() == 1)
		{
			fprintf(file, "\n%d\n", exp[i].getAns().getNumerator());
		}
		else
		{
			fprintf(file, "\n%d/%d\n", exp[i].getAns().getNumerator(), exp[i].getAns().getDenominator());

		}
	}
	fclose(file);
	return 1;
}
//主函数
int main(int argc,char ** argv)
{
	init();
	for (int i = 0; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			switch (argv[i][1])
			{
				
			case 'g':
				int num;
				sscanf(argv[i+1],"%d",&num);
				generateEpression(num,argv[i+2]);
				i += 2;
				break;
			case 's':
				Expression::powerSetting = false;
			default:
				break;
			}
		}
	}
	//Expression::powerSetting = false;
	//test3();
	
    return 0;
}

