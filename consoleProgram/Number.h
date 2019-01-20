#pragma once
#include<iostream>
class Number
{
private:
	//����
	int numerator;
	//��ĸ
	int denominator;
	//������
	int maxFactor(int nr, int dr);
	//�������淶�����������ڷ�����
	void normal();
public:

	//io����
	friend std::ostream & operator<<(std::ostream &out, const Number &obj);
	friend std::istream & operator>> (std::istream &in, Number &obj);
	//���캯��������Ϊ0����ĸΪ1
	Number();
	//������ӣ���ĸΪ1
	Number(int numerator);
	//������ӣ���ĸ
	Number(int numerator, int denominator);
	//���������
	Number operator+(const Number& rv) const;
	Number operator-(const Number& rv) const;
	Number operator*(const Number& rv) const;
	Number operator/(const Number& rv) const;
	Number& operator=(const Number& rv);
	bool operator==(const Number& rv) const;
	bool operator!=(const Number & rv) const;
	
	//��ȡ����
	int getNumerator();
	//��ȡ��ĸ
	int getDenominator();
	//����Լ��
	void fractionReduction();

	~Number();
};

