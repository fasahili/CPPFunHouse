#include"MixedNumber.h, Rational.h"
//read write
void Rational::write()
{
	int n1 = this->Numerator, n2 = this->Denominator, dcf = 0;
	for (int i = 1; i <= n2; ++i)
	{
		if (n1 % i == 0 && n2 % i == 0)
		{
			dcf = i;
		}
	}
	this->Numerator = this->Numerator / dcf;
	this->Denominator = this->Denominator / dcf;
	cout << this->getNumerator() << '/' << this->getDenominator() << endl;
}
bool Rational::read()
{ 
	return true;
}
//setter , getter Numerator
void Rational::setNumerator(int Numerator)
{
	this->Numerator = Numerator;
}
int Rational::getNumerator()
{
	return this->Numerator;
}
//setter , getter Denominator
void Rational::setDenominator(int Denominator)
{
	this->Denominator = Denominator;
}
int Rational::getDenominator()
{
	return this->Denominator;
}
//Constractors
Rational::Rational()
{

	this->Numerator = 0;
	this->Denominator = 1;

}
Rational :: Rational (int num1, int num2)
{
	if (num2 != 0)
	{
		this->Numerator = num1;
		this->Denominator = num2;
	}
	else 
	{
		this->Numerator = 0;
		this->Denominator = 1;
	}
}
Rational::Rational(const Rational& rhs)
{
	this->Numerator = rhs.Numerator;
	this->Denominator= rhs.Denominator;
}
//Methods
Rational Rational::add(const Rational& rhs)const
{
	Rational temp;
	temp.Numerator = (this->Numerator * rhs.Denominator) + (this->Denominator * rhs.Numerator);
	temp.Denominator = this->Denominator * rhs.Denominator;
	return temp;
}
Rational Rational::subtract(const Rational& rhs)const
{
	Rational temp;
	temp.Numerator = (this->Numerator * rhs.Denominator) - (rhs.Numerator * this->Denominator);
	temp.Denominator = this->Denominator * rhs.Denominator;
	return temp;
}
Rational Rational::multiply(const Rational& rhs)const
{
	Rational temp;
	temp.Numerator = this->Numerator * rhs.Numerator;
	temp.Denominator = this->Denominator * rhs.Denominator;

	return temp;
}
Rational Rational::divide(const Rational& rhs)const
{
	Rational temp;
	temp.Numerator = this->Numerator * rhs.Denominator;
	temp.Denominator = this->Denominator * rhs.Numerator;
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
}

//------ Class MixedNumber -------

//setter and getter
void MixedNum::setWhole(int whole)
{
	this->whole = whole;
}
int MixedNum::getWhole()
{
	return this->whole;
}
//read write 
void  MixedNum::read()
{
}
void  MixedNum::write() 
{
	this->display();
}
//Methods 
MixedNum MixedNum::add(const MixedNum& rhs)const
{
	MixedNum temp;
	Rational temp1;
	Rational temp2(this->Numerator, this->Denominator);
	Rational temp3(rhs.Numerator,rhs.Denominator);
	int wholeStg;
	temp1 = temp2.add(temp3);
	wholeStg = this->whole + rhs.whole;
	temp.Numerator = temp1.getNumerator();
	temp.Denominator = temp1.getDenominator();
	temp.whole = wholeStg;
	return temp;
}
MixedNum MixedNum::subtract(const MixedNum& rhs)const
{
	MixedNum temp;
	Rational temp1;
	Rational temp2(this->Numerator, this->Denominator);
	Rational temp3(rhs.Numerator, rhs.Denominator);
	int wholeStg;
	temp1 = temp2.subtract(temp3);
	wholeStg = this->whole - rhs.whole;
	temp.Numerator = temp1.getNumerator();
	temp.Denominator = temp1.getDenominator();
	temp.whole = wholeStg;
	return temp;
}
MixedNum MixedNum::multiply(const MixedNum& rhs)const
{
	MixedNum temp;
	Rational temp1;
	int newNumerator_1;
	int newNumerator_2;
	newNumerator_1 = (this->whole * this->Denominator) + this->Numerator;
	newNumerator_2 = (rhs.whole * rhs.Denominator) + rhs.Numerator;
	Rational temp2(newNumerator_1, this->Denominator);
	Rational temp3(newNumerator_2, rhs.Denominator);
	temp1 = temp2.multiply(temp3);
	temp.Numerator = temp1.getNumerator();
	temp.Denominator = temp1.getDenominator();
	//temp.whole = 0;
	int dividend; 
	for (dividend = temp.Numerator - 1; dividend > 1; dividend--) 
	{
		if ((dividend % temp.Denominator) == 0) {

			temp.Numerator = temp.Numerator - dividend;
			temp.whole = dividend / temp.Denominator;
			break;
		}
	}
	return temp;
}
MixedNum MixedNum::divide(const MixedNum& rhs)const
{
	MixedNum temp;
	Rational temp1;
	int newNumerator_1;
	int newNumerator_2;
	newNumerator_1 = (this->whole * this->Denominator) + this->Numerator;
	newNumerator_2 = (rhs.whole * rhs.Denominator) + rhs.Numerator;
	Rational temp2(newNumerator_1, this->Denominator);
	Rational temp3(newNumerator_2, rhs.Denominator);
	temp1 = temp2.divide(temp3);
	temp.Numerator = temp1.getNumerator();
	temp.Denominator = temp1.getDenominator();
	int dividend;
	for (dividend = temp.Numerator - 1; dividend > 1; dividend--)
	{
		if ((dividend % temp.Denominator) == 0)
		{
			temp.Numerator = temp.Numerator - dividend;
			temp.whole = dividend / temp.Denominator;

			int n1 = temp.Numerator, n2 = temp.Denominator, dcf = 0;
			for (int i = 1; i <= n2; ++i)
			{
				if (n1 % i == 0 && n2 % i == 0)
				{
					dcf = i;
				}
			}
			temp.Numerator = temp.Numerator / dcf;
			temp.Denominator = temp.Denominator / dcf;

			break;
		}
	}
	return temp;
}
void MixedNum:: simplify()
{
	int dividend;
	for (dividend = this->Numerator - 1; dividend > 1; dividend--)
	{
		if ((dividend % this->Denominator) == 0)
		{
			this->Numerator = this->Numerator - dividend;
			this->whole++;
			int n1 = this->Numerator, n2 = this->Denominator, dcf = 0;
			for (int i = 1; i <= n2; ++i)
			{
				if (n1 % i == 0 && n2 % i == 0)
				{
					dcf = i;
				}
			}
			this->Numerator = this->Numerator / dcf;
			this->Denominator = this->Denominator / dcf;
			break;
		}
	}

}
void MixedNum::display() const
{
	cout << this->whole << " " << this->Numerator << "/" << this->Denominator << endl;
}
Rational MixedNum::toRational() const
{
	Rational temp;
	int temp1 = (this->whole * this->Denominator) + this->Numerator;
	temp.setNumerator(temp1);
	temp.setDenominator(this->Denominator);
	return temp;
}
//opertor overloed
MixedNum MixedNum::operator+(const MixedNum& rhs)const
{
	MixedNum temp = this->add(rhs);
	return temp;
}
MixedNum MixedNum::operator-(const MixedNum& rhs)const
{
	MixedNum temp = this->subtract(rhs);
	return temp;
}
MixedNum MixedNum::operator*(const MixedNum& rhs)const
{
	MixedNum temp = this->multiply(rhs);
	return temp;
}
MixedNum MixedNum::operator/(const MixedNum& rhs)const
{
	MixedNum temp = this->divide(rhs);
	return temp;
}
//12115935 Faris Sahili