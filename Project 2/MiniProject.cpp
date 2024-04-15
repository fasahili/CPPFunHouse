#include <iostream>                                  // programmer : Faris Sahili - University ID(12115935)
using namespace std;
//These functions are for operations
void funInsert (char a[100])
{
	//The function has entered different polynomial
	cout << "please insert polynomial = " << endl;
	cin >> a;
}
void funPrint(char a[100])
{
	//The function has printed a polynomial
	cout << a << endl;
}
void funFirstDrv(char poly[100], int coDrv[100], int exDrv[100])
{
	//This function is for the first derivative 
	int j = 0;
	int k = 0;
	int i = 0;
	int stgDrv[100] = { 0 };

	for (i = 0; poly[i]; i++)
	{
		//one coefficient and one exponent .
		if ((poly[i] == 'x') && (i == 1) && (poly[i + 3] == '+' || poly[i + 3] == '-' || poly[i + 3] == NULL))
		{
			stgDrv[k] = (poly[i - 1] - '0') * 1;
			k++;
		}
	
		if ((poly[i] == 'x') && (poly[i - 2] == '+' || poly[i - 2] == '-') && (poly[i + 3] == '+' || poly[i + 3] == '-' || poly[i + 3] == NULL))
		{
			stgDrv[k] = (poly[i - 1] - '0') * 1;
			k++;
		}
		//Two coefficient and one exponent .
	
		if ((poly[i] == 'x') && (i == 2) && (poly[i + 3] == '+' || poly[i + 3] == '-' || poly[i + 3] == NULL))
		{
			stgDrv[k] = (poly[i - 2] - '0') * 10 + (poly[i - 1] - '0') * 1;
			k++;
		}
		
		if ((poly[i] == 'x') && ((poly[i - 3] == '+') || (poly[i - 3] == '-')) && (poly[i + 3] == '+' || poly[i + 3] == '-' || poly[i + 3] == NULL))
		{
			stgDrv[k] = (poly[i - 2] - '0') * 10 + (poly[i - 1] - '0') * 1;
			k++;
		}
		//Three coefficient and one exponent .
		
		if ((poly[i] == 'x') && (i == 3) && (poly[i + 3] == '+' || poly[i + 3] == '-' || poly[i + 3] == NULL))
		{
			stgDrv[k] = (poly[i - 3] - '0') * 100 + (poly[i - 2] - '0') * 10 + (poly[i - 1] - '0') * 1;
			k++;

		}
		
		if ((poly[i] == 'x') && ((poly[i - 4] == '+') || (poly[i - 4] == '-')) && (poly[i + 3] == '+' || poly[i + 3] == '-' || poly[i + 3] == NULL))
		{
			stgDrv[k] = (poly[i - 3] - '0') * 100 + (poly[i - 2] - '0') * 10 + (poly[i - 1] - '0') * 1;
			k++;
		}
	}
	//This for loop is for printing the first derivative
	for (int y = 0, p = 0; y < k; y++,p++)
	{
		cout << stgDrv[p] * exDrv[p] << "x" << "^" << exDrv[p] - 1 << endl;
	}
	cout << endl;
}
void funTerms(char a[100], int coeff[100], int exp[100])
{
	//This function is for the terms
	int j = 0;
	int k = 0;
	for (int i = 0; a[i]; i++)
	{
		//one coefficient and one exponent . 
		//Here the exponents are stored in an array and the cofficients in an array .

		if ((a[i] == 'x') && (a[i + 3] == '+' || a[i + 3] == '-' || a[i + 3] == NULL) && (i == 1))
		{
			coeff[j] = a[i - 1] - '0';
			exp[k] = a[i + 2] - '0';
			cout << "(" << coeff[j] << "," << exp[k] << ")" << " ";
			j++;
			k++;
		}

	
		if ((a[i] == 'x') && (a[i - 2] == '+' || a[i - 2] == '-') && (a[i + 3] == '+' || a[i + 3] == '-' || a[i + 3] == NULL))
		{
			coeff[j] = a[i - 1] - '0';
			exp[k] = a[i + 2] - '0';

			cout << "(" << coeff[j] << "," << exp[k] << ")" << " ";
			j++;
			k++;
		}

		//Two coefficient and one exponent . 
		//Here the exponents are stored in an array and the cofficients in an array .

		if ((a[i] == 'x') && (a[i + 3] == '+' || a[i + 3] == '-' || a[i + 3] == NULL) && (i == 2))
		{
			coeff[j] = a[i - 2] - '0';
			coeff[j + 1] = a[i - 1] - '0';
			exp[k] = a[i + 2] - '0';

			cout << "(" << coeff[j] << coeff[j + 1] << "," << exp[k] << ")" << " ";
			j++;
			k++;
		}

		if ((a[i] == 'x') && (a[i - 3] == '+' || a[i - 3] == '-') && (a[i + 3] == '+' || a[i + 3] == '-' || a[i + 3] == NULL))
		{
			coeff[j] = a[i - 2] - '0';
			coeff[j + 1] = a[i - 1] - '0';
			exp[k] = a[i + 2] - '0';

			cout << "(" << coeff[j] << coeff[j + 1] << "," << exp[k] << ")" << " ";
			j++;
			k++;
		}
		//Three coefficient and one exponent . 
		//Here the exponents are stored in an array and the cofficients in an array .

		if ((a[i] == 'x') && (a[i + 3] == '+' || a[i + 3] == '-' || a[i + 3] == NULL) && (i == 3))
		{
			coeff[j] = a[i - 3] - '0';
			coeff[j + 1] = a[i - 2] - '0';
			coeff[j + 2] = a[i - 1] - '0';
			exp[k] = a[i + 2] - '0';

			cout << "(" << coeff[j] << coeff[j + 1] << coeff[j + 2] << "," << exp[k] << ")" << " ";
			j++;
			k++;

		}

		if ((a[i] == 'x') && (a[i - 4] == '+' || a[i - 4] == '-') && (a[i + 3] == '+' || a[i + 3] == '-' || a[i + 3] == NULL))
		{
			coeff[j] = a[i - 3] - '0';
			coeff[j + 1] = a[i - 2] - '0';
			coeff[j + 2] = a[i - 1] - '0';
			exp[k] = a[i + 2] - '0';

			cout << "(" << coeff[j] << coeff[j + 1] << coeff[j + 2] << "," << exp[k] << ")" << " ";
			j++;
			k++;
		}
	}
	cout << endl;
}
void funTermsStorage(char a[100], int coeff[100], int exp[100])
{
	//This function stores the terms 
	//To be passed on to other functions
	int j = 0;
	int k = 0;
	for (int i = 0; a[i]; i++)
	{
		//one coefficient and one exponent . 
		//Here the exponents are stored in an array and the cofficients in an array .

		if ((a[i] == 'x') && (a[i + 3] == '+' || a[i + 3] == '-' || a[i + 3] == NULL) && (i == 1))
		{
			coeff[j] = a[i - 1] - '0';
			exp[k] = a[i + 2] - '0';
			j++;
			k++;
		}


		if ((a[i] == 'x') && (a[i - 2] == '+' || a[i - 2] == '-') && (a[i + 3] == '+' || a[i + 3] == '-' || a[i + 3] == NULL))
		{
			coeff[j] = a[i - 1] - '0';
			exp[k] = a[i + 2] - '0';

			j++;
			k++;
		}

		//Two coefficient and one exponent . 
		//Here the exponents are stored in an array and the cofficients in an array .

		if ((a[i] == 'x') && (a[i + 3] == '+' || a[i + 3] == '-' || a[i + 3] == NULL) && (i == 2))
		{
			coeff[j] = a[i - 2] - '0';
			coeff[j + 1] = a[i - 1] - '0';
			exp[k] = a[i + 2] - '0';

			j++;
			k++;
		}

		if ((a[i] == 'x') && (a[i - 3] == '+' || a[i - 3] == '-') && (a[i + 3] == '+' || a[i + 3] == '-' || a[i + 3] == NULL))
		{
			coeff[j] = a[i - 2] - '0';
			coeff[j + 1] = a[i - 1] - '0';
			exp[k] = a[i + 2] - '0';

			j++;
			k++;
		}
		//Three coefficient and one exponent . 
		//Here the exponents are stored in an array and the cofficients in an array .

		if ((a[i] == 'x') && (a[i + 3] == '+' || a[i + 3] == '-' || a[i + 3] == NULL) && (i == 3))
		{
			coeff[j] = a[i - 3] - '0';
			coeff[j + 1] = a[i - 2] - '0';
			coeff[j + 2] = a[i - 1] - '0';
			exp[k] = a[i + 2] - '0';

			j++;
			k++;

		}

		if ((a[i] == 'x') && (a[i - 4] == '+' || a[i - 4] == '-') && (a[i + 3] == '+' || a[i + 3] == '-' || a[i + 3] == NULL))
		{
			coeff[j] = a[i - 3] - '0';
			coeff[j + 1] = a[i - 2] - '0';
			coeff[j + 2] = a[i - 1] - '0';
			exp[k] = a[i + 2] - '0';

			j++;
			k++;
		}
	}
}
void funSecondDrv(char poly[100], int coDrv[100], int exDrv[100])
{
	//This function is for the second derivative 
	int j = 0;
	int k = 0;
	int i = 0;
	int stgDrv[100] = { 0 };

	for (i = 0; poly[i]; i++)
	{
		//one coefficient and one exponent .
		if ((poly[i] == 'x') && (i == 1) && (poly[i + 3] == '+' || poly[i + 3] == '-' || poly[i + 3] == NULL))
		{
			stgDrv[k] = (poly[i - 1] - '0') * 1;
			k++;
		}

		if ((poly[i] == 'x') && (poly[i - 2] == '+' || poly[i - 2] == '-') && (poly[i + 3] == '+' || poly[i + 3] == '-' || poly[i + 3] == NULL))
		{
			stgDrv[k] = (poly[i - 1] - '0') * 1;
			k++;
		}
		//Two coefficient and one exponent .

		if ((poly[i] == 'x') && (i == 2) && (poly[i + 3] == '+' || poly[i + 3] == '-' || poly[i + 3] == NULL))
		{
			stgDrv[k] = (poly[i - 2] - '0') * 10 + (poly[i - 1] - '0') * 1;
			k++;
		}

		if ((poly[i] == 'x') && ((poly[i - 3] == '+') || (poly[i - 3] == '-')) && (poly[i + 3] == '+' || poly[i + 3] == '-' || poly[i + 3] == NULL))
		{
			stgDrv[k] = (poly[i - 2] - '0') * 10 + (poly[i - 1] - '0') * 1;
			k++;
		}
		//Three coefficient and one exponent .

		if ((poly[i] == 'x') && (i == 3) && (poly[i + 3] == '+' || poly[i + 3] == '-' || poly[i + 3] == NULL))
		{
			stgDrv[k] = (poly[i - 3] - '0') * 100 + (poly[i - 2] - '0') * 10 + (poly[i - 1] - '0') * 1;
			k++;

		}

		if ((poly[i] == 'x') && ((poly[i - 4] == '+') || (poly[i - 4] == '-')) && (poly[i + 3] == '+' || poly[i + 3] == '-' || poly[i + 3] == NULL))
		{
			stgDrv[k] = (poly[i - 3] - '0') * 100 + (poly[i - 2] - '0') * 10 + (poly[i - 1] - '0') * 1;
			k++;
		}
	}
	//This for loop is for printing the second derivative
	for (int y = 0, p = 0; y < k; y++, p++)
	{
		cout << stgDrv[p] * exDrv[p] + stgDrv[p] * exDrv[p] << "x" << "^" << exDrv[p] - 2 << endl;
	}
	cout << endl;
}
int main()
{
	// a --> The array in which we will enter the polynomial 
	// a2 --> The array in which we will enter the different polynomial 
	int coeffMain[100];
	int expMain[100];
	char a2[100] = { NULL };
	int choice;
	char a[100] = { NULL };
	cout << "Please enter polynomial = " << endl;
	cin >> a;
	//This function stores coefficient and exponent
	funTermsStorage(a, coeffMain, expMain);
	cout << "      main menu :-    " << endl;
	cout << "(1) Insert a new polynomial" << endl;
	cout << "(2) Print the polynomial   " << endl;
	cout << "(3) compute the first derivative of polynomial" << endl;
	cout << "(4) compute the second derivative of polynomial" << endl;
	cout << "(5) Find the terms of polynomial" << endl;
	for (;;)
	{
		cout << "Choose a operation number from above = " << endl;
		cin >> choice;
		if (choice == 1)funInsert(a2);
		if (choice == 2)funPrint(a);
		if (choice == 3)funFirstDrv(a,coeffMain, expMain);
		if (choice == 4)funSecondDrv(a, coeffMain, expMain);
		if (choice == 5) funTerms(a, coeffMain, expMain);
	}
}