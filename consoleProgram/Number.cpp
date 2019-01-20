#include "stdafx.h"
#include "Number.h"


int Number::maxFactor(int nr, int dr)
{
	//շת��������������
	int th = nr, tl = dr;
	if (nr < dr)
	{
		th = dr;
		tl = nr;
	}
	if (th%tl == 0)
	{
		return tl;
	}
	else
		return maxFactor(tl, th%tl);
	return 0;
}

void Number::normal()
{
	if (denominator > 0)
	{
		return;
	}
	else {
		denominator = -denominator;
		numerator = -numerator;
	}
}

Number::Number()
{
	this->numerator = 0;
	this->denominator = 1;

}

Number::Number(int numerator)
{
	this->numerator = numerator;
	this->denominator = 1;
}

Number::Number(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;

}

Number Number::operator+(const Number & rv) const
{
	Number ans = Number(numerator*rv.denominator + rv.numerator*denominator, denominator*rv.denominator);
	ans.fractionReduction();
	return ans;
}

Number Number::operator-(const Number & rv) const
{
	Number a = Number(numerator*rv.denominator - rv.numerator*denominator, denominator*rv.denominator);

	a.fractionReduction();

	return a;
}

Number Number::operator*(const Number & rv) const
{
	Number a = Number(numerator * rv.numerator, denominator * rv.denominator);

	a.fractionReduction();

	return a;
	return Number();
}

Number Number::operator/(const Number & rv) const
{
	Number a = Number(numerator * rv.denominator, denominator * rv.numerator);

	a.fractionReduction();

	return a;
}

Number & Number::operator=(const Number & rv)
{
	numerator = rv.numerator;

	denominator = rv.denominator;

	return *this;
}

bool Number::operator==(const Number & rv) const
{
	if (numerator*rv.denominator == rv.numerator * denominator)
	{
		return true;
	}
	return false;
}
bool Number::operator!=(const Number & rv) const
{
	if (numerator*rv.denominator != rv.numerator * denominator)
	{
		return true;
	}
	return false;
}
int Number::getNumerator()
{
	return numerator;
}

int Number::getDenominator()
{
	return denominator;
}

void Number::fractionReduction()
{
	//����Ϊ�㣬ֱ�ӽ���ĸ��һ��
	if (numerator == 0)
	{
		denominator = 1;
		return;
	}
	int a = maxFactor(denominator>0?denominator:-denominator,
		numerator>0?numerator:-numerator);
	numerator /= a;
	denominator /= a;
}


Number::~Number()
{
}

std::ostream & operator<<(std::ostream & out, const Number & obj)
{
	//���ʱ������ĸΪ1������ʾ
	if (obj.denominator == 1)
	{
		out << obj.numerator;
		return out;
	}
	out << obj.numerator << '/' << obj.denominator;
	return out;
	
}

std::istream & operator>>(std::istream & in, Number & obj)
{
	in >> obj.numerator >> obj.denominator;
	return in;
}
