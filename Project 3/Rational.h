#pragma once

class Rational 
{

 public:

	Rational();
	Rational(const Rational& obj);
	Rational(int num1, int num2);

	//Methods
	Rational add(const Rational& rhs)const;
	Rational subtract(const Rational& rhs)const;
	Rational multiply(const Rational& rhs)const;
	Rational divide(const Rational& rhs)const;

	//opertor overloed
	Rational operator+(const Rational& rhs);
	Rational operator-(const Rational& rhs);
	Rational operator*(const Rational& rhs);
	Rational operator/(const Rational& rhs);

	//read,write
	bool read();
	void write();

private:
	int num1;
	int num2;
};
