#include"MixedNumber.h, Rational.h"
using namespace std;
int main()
{
	int numeratorInput, denominatorInput, wholeInput;
	char tempChar;
	MixedNum m1;
	MixedNum m2;
	MixedNum m3;

	cout << "Please Enter First Friction = " << endl;
	cin >> wholeInput >> numeratorInput >> tempChar >> denominatorInput;
	m1.setWhole(wholeInput);
	m1.setNumerator(numeratorInput);
	m1.setDenominator(denominatorInput);

	cout << "Please Enter Second Friction = " << endl;
	cin >> wholeInput >> numeratorInput >> tempChar >> denominatorInput;
	m2.setWhole(wholeInput);
	m2.setNumerator(numeratorInput);
	m2.setDenominator(denominatorInput);
	cout << "- If you want to add, press 1" << endl;
	cout << "- If you want to subtract, press 2" << endl;
	cout << "- If you want to multiply, press 3" << endl;
	cout << "- If you want to divide, press 4" << endl;
	cout << "- If you want to simplify, press 5" << endl;
	cout << "- If you want to toRational, press 6" << endl;
	cout << "- If you want to display, press 7" << endl;
	cout << "- If you want exit, press 8" << endl;
	int choice;
	while (true)
	{
		cout << "Please enter your choice = " << endl;
		cin >> choice;
		if (choice == 1)
		{
			m3 = m1 + m2;
			m3.display();
		}
		else if (choice == 2)
		{
			m3 = m1 - m2;
			m3.display();
		}
		else if (choice == 3)
		{
			m3 = m1 * m2;
			m3.display();
		}
		else if (choice == 4)
		{
			m3 = m1 / m2;
			m3.display();

		}
		else if (choice == 5)
		{
			m3.simplify();
			cout << m3.getWhole() << " " << m3.getNumerator() << "/" << m3.getDenominator() << endl;
		}
		else if (choice == 6)
		{
			Rational r1;
			r1 = m3.toRational();
			cout << r1.getNumerator() << "/" << r1.getDenominator() << endl;
		}
		else if (choice == 7)
		{
			m3.display();
		}
		else if (choice == 8)
		{
			cout << "Thank you ----" << endl;
			break;
		}
	}
}//Faris Abdulkarim Sahili (12115935)