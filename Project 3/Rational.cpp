#include<iostream>
#include"Rational.h"
using namespace std;

bool Rational::read()
{
	char temp;
	cin >> this->num1 >> temp >> this->num2;
	return true;
}
void Rational::write()
{
	{
		int n1 = this->num1, n2 = this->num2, dcf = 0;
		for (int i = 1; i <= n2; ++i) {
			if (n1 % i == 0 && n2 % i == 0) {
				dcf = i;
			}
		}
		this->num1 = this->num1 / dcf;
		this->num2 = this->num2 / dcf;
		cout << this->num1 << '/' << this->num2 << endl;
	}
}

//constractor
Rational::Rational()
{

	this->num1 = 0;
	this->num2 = 0;

}
Rational::Rational(int num1, int num2)
{
	this->num1 = num1;
	this->num2 = num2;

}
Rational::Rational(const Rational& rhs)
{
	this->num1 = rhs.num1;
	this->num2= rhs.num2;
}

//Methods
Rational Rational::add(const Rational& rhs)const
{
	Rational temp;
	temp.num1 = (this->num1 * rhs.num2) + (this->num2 * rhs.num1);
	temp.num2 = this->num2 * rhs.num2;
	return temp;
}
Rational Rational::subtract(const Rational& rhs)const
{
	Rational temp;
	temp.num1 = (this->num1 * rhs.num2) - (rhs.num1 * this->num2);
	temp.num2 = this->num2 * rhs.num2;
	return temp;
}
Rational Rational::multiply(const Rational& rhs)const
{
	Rational temp;
	temp.num1 = this->num1 * rhs.num1;
	temp.num2 = this->num2 * rhs.num2;

	return temp;
}
Rational Rational::divide(const Rational& rhs)const
{
	Rational temp;
	temp.num1 = this->num1 * rhs.num2;
	temp.num2 = this->num2 * rhs.num1;
	return temp;
}

//opertor overloed
Rational Rational:: operator+(const Rational& rhs)
{
	Rational temp = this->add(rhs);
	return temp;
}
Rational Rational:: operator-(const Rational& rhs)
{
	Rational temp = this->subtract(rhs);
	return temp;
}
Rational Rational:: operator*(const Rational& rhs)
{
	Rational temp = this->multiply(rhs);
	return temp;
}
Rational Rational:: operator/(const Rational& rhs)
{
	Rational temp = this->divide(rhs);
	return temp;
}//12115935 Faris Sahili