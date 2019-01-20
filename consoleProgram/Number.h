#pragma once
#include<iostream>
class Number
{
private:
	//分子
	int numerator;
	//分母
	int denominator;
	//求公因子
	int maxFactor(int nr, int dr);
	//将分数规范化，即符号在分子上
	void normal();
public:

	//io重载
	friend std::ostream & operator<<(std::ostream &out, const Number &obj);
	friend std::istream & operator>> (std::istream &in, Number &obj);
	//构造函数，分子为0，分母为1
	Number();
	//输入分子，分母为1
	Number(int numerator);
	//输入分子，分母
	Number(int numerator, int denominator);
	//运算符重载
	Number operator+(const Number& rv) const;
	Number operator-(const Number& rv) const;
	Number operator*(const Number& rv) const;
	Number operator/(const Number& rv) const;
	Number& operator=(const Number& rv);
	bool operator==(const Number& rv) const;
	bool operator!=(const Number & rv) const;
	
	//获取分子
	int getNumerator();
	//获取分母
	int getDenominator();
	//分数约分
	void fractionReduction();

	~Number();
};

