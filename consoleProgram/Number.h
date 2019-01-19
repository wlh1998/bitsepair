#pragma once
#include<iostream>
class Number
{
private:
	int numerator;
	int denominator;
	int maxFactor(int nr, int dr);
	void normal();
public:
	friend std::ostream & operator<<(std::ostream &out, const Number &obj);
	friend std::istream & operator>> (std::istream &in, Number &obj);

	Number();
	Number(int numerator);
	Number(int numerator, int denominator);
	Number operator+(const Number& rv) const;
	Number operator-(const Number& rv) const;
	Number operator*(const Number& rv) const;
	Number operator/(const Number& rv) const;
	Number& operator=(const Number& rv);
	bool operator==(const Number& rv) const;

	bool operator!=(const Number & rv) const;

	int getNumerator();
	int getDenominator();

	void fractionReduction();

	~Number();
};

