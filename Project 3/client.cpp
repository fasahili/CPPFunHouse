#include <iostream>
#include"Rational.h"
using namespace std;
int main()
{
	
	Rational r1;
	Rational r2;
	Rational r3Add;
	Rational r3Mult;
	Rational r3Sub;
	Rational r3Div;

	cout << "The first frction = "; r1.read();
	cout << "The second frction = "; r2.read();
	r3Add = r1 + r2;
	r3Mult = r1 * r2;
	r3Sub = r1 - r2;
	r3Div = r1 / r2;
	cout << endl;
	cout << "The final answer (Add , + ) = "; r3Add.write();
	cout << "The final answer (Multiply , * ) = "; r3Mult.write();
	cout << "The final answer (subtract , - ) = "; r3Sub.write();
	cout << "The final answer (divide , / ) = "; r3Div.write();
}