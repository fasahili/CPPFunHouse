#pragma once
#include <iostream>
using namespace std;
class Rational{
 public:
	 //constructors
	Rational();
	Rational(int num1, int num2);
	Rational(const Rational& obj);
	//setter,getter
	void setDenominator(int Denominator);
	int getDenominator(); 
	void setNumerator(int Numerator);
	int getNumerator();
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

protected:
	int Numerator;
	int Denominator;
};

class MixedNum : public Rational{
public:
	//constructors
	MixedNum(int h = 0, int n = 0, int d = 1) : Rational(n, d), whole(h) {
	}
	MixedNum(const Rational& r,int h) :Rational(r),whole(h) {
	}
	//setter,getter
	void setWhole(int whole);
	int getWhole();
	//methods
	MixedNum add(const MixedNum& rhs)const;
	MixedNum subtract(const MixedNum& rhs)const;
	MixedNum multiply(const MixedNum& rhs)const;
	MixedNum divide(const MixedNum& rhs)const;
	void simplify();
	Rational toRational() const;
	void display() const;
	//operator overloaded
	MixedNum operator+(const MixedNum& rhs) const;
	MixedNum operator-(const MixedNum& rhs) const;
	MixedNum operator*(const MixedNum& rhs) const;
	MixedNum operator/(const MixedNum& rhs) const;
	//read,write
	void read();
	void write();
	
protected:
	int whole;
};
