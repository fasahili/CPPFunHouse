#include <iostream>                                  // team lead :-Faris Sahili
#include<fstream>
using namespace std;
struct Car
{
	int id;
	char make[20];
	char modle[20];
	int year;
	char color[20];
	int engine;
	int price;
};
void menuItems()
{
	cout << " 1) " << " Add a car record " << endl;
	cout << " 2) " << " Delete a car record " << endl;
	cout << " 3) " << " Update a car record " << endl;
	cout << " 4) " << " view all car records " << endl;
	cout << " 5) " << " view cars with price less than value " << endl;
	cout << " 6) " << " view cars by car make " << endl;
	cout << " 7) " << " view all cars sorted by price " << endl;
	cout << " 8) " << " view all cars sorted by year " << endl;
	cout << " 9) " << " save " << endl;
	cout << "10) " << " quit " << endl;
	cout << endl;
}
void updateRec(Car arr[], int size)
{
	int idUserInput;
	cout << "please enter ID you want to update = " << endl;
	cin >> idUserInput;
	int choice = 0;
	Car temp;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].id == idUserInput && idUserInput >= 1 && idUserInput <= 5)
		{
			cout << "please enter the information you want update = " << endl;
			cout << "ID = "; cin >> temp.id;
			cout << "Make = "; cin >> temp.make;
			cout << "Modle = "; cin >> temp.modle;
			cout << "Year = "; cin >> temp.year;
			cout << "color = "; cin >> temp.color;
			cout << "engine = "; cin >> temp.engine;
			cout << "price = ";	cin >> temp.price;
			cout << " if you want to confirm this , press 1 ... " << endl;
			cin >> choice;
			if (choice == 1)
			{
				arr[i] = temp;
			}
			else
				cout << " you haven't confirmed it " << endl;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i].id << " " << arr[i].make << " " << arr[i].modle << " " << arr[i].year << " " << arr[i].color << " " << arr[i].engine << " " << arr[i].price;
		cout << endl;
	}
	cout << endl;
}
void addRecord(Car arr[], int& size)
{
	int sizeAddToArray = 0;
	cout << "plz enter size addition to array = " << endl;
	cin >> sizeAddToArray;
	int maxSize = 100;
	if ((size + sizeAddToArray) <= maxSize)
	{
		Car temp[5];
		for (int i = 0; i < 5; i++)
		{
			temp[i].id = arr[i].id;
			strcpy_s(temp[i].make, 20, arr[i].make);
			strcpy_s(temp[i].modle, 20, arr[i].modle);
			temp[i].year = arr[i].year;
			strcpy_s(temp[i].color, 20, arr[i].color);
			temp[i].engine = arr[i].engine;
			temp[i].price = arr[i].price;
		}
		Car* ptr = new Car[size + sizeAddToArray];
		delete[]arr;
		for (int i = 0; i < 5; i++)
		{
			ptr[i].id = temp[i].id;
			strcpy_s(ptr[i].make, 20, temp[i].make);
			strcpy_s(ptr[i].modle, 20, temp[i].modle);
			ptr[i].year = temp[i].year;
			strcpy_s(ptr[i].color, 20, temp[i].color);
			ptr[i].engine = temp[i].engine;
			ptr[i].price = temp[i].price;
		}
		for (int i = 5; i < (size + sizeAddToArray); i++)
		{
			cout << "please enter the information you want the new record = " << endl;
			cout << "ID = "; cin >> ptr[i].id;
			cout << "Make = "; cin >> ptr[i].make;
			cout << "Modle = "; cin >> ptr[i].modle;
			cout << "Year = "; cin >> ptr[i].year;
			cout << "color = "; cin >> ptr[i].color;
			cout << "engine = "; cin >> ptr[i].engine;
			cout << "price = ";	cin >> ptr[i].price;
		}
		int choice;
		cout << " if you want to confirm this ,please press 1 ... " << endl;
		cin >> choice;
		if (choice == 1)
		{
			size += sizeAddToArray;
			Car* arr = new Car[size];
			for (int i = 0; i < size; i++)
			{
				arr[i].id = ptr[i].id;
				strcpy_s(arr[i].make, 20, ptr[i].make);
				strcpy_s(arr[i].modle, 20, ptr[i].modle);
				arr[i].year = ptr[i].year;
				strcpy_s(arr[i].color, 20, ptr[i].color);
				arr[i].engine = ptr[i].engine;
				arr[i].price = ptr[i].price;
			}
			delete[]ptr;
			for (int i = 0; i < size; i++)
			{
				cout << arr[i].id << " " << arr[i].make << " " << arr[i].modle << " " << arr[i].year << " " << arr[i].color << " " << arr[i].engine << " " << arr[i].price;
				cout << endl;
			}
		}
	}
	cout << endl;
}
void deleteRecord(Car arr[], int& size)
{
	int theIdSrc;
	cout << "please enter ID you want to delete = "; cin >> theIdSrc;
	int temp;
	if (theIdSrc <= 5)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i].id == theIdSrc)
			{
				temp = i;
				int choice;
				cout << " if you want to confirm this , press 1 ... " << endl;
				cin >> choice;
				if (choice == 1)
				{
					for (int j = temp; j < size - 1; j++)
					{
						arr[j].id = arr[j + 1].id;
						strcpy_s(arr[j].make, 20, arr[j + 1].make);
						strcpy_s(arr[j].modle, 20, arr[j + 1].modle);
						arr[j].year = arr[j + 1].year;
						strcpy_s(arr[j].color, 20, arr[j + 1].color);
						arr[j].engine = arr[j + 1].engine;
						arr[j].price = arr[j + 1].price;
					}
					size -= 1;

					for (int i = 0; i < size; i++)
					{
						cout << arr[i].id << " " << arr[i].make << " " << arr[i].modle << " " << arr[i].year << " " << arr[i].color << " " << arr[i].engine << " " << arr[i].price;
						cout << endl;
					}
				}
			}
		}
	}
	else
		cout << "the input it is not found ... " << endl;

	cout << endl;
}
void saveInfo(Car arr[], int size)
{
	ofstream out;
	const char fileName[50] = "C:\\Users\\Faris Sahili\\Desktop\\cars.txt";
	out.open(fileName, ios::ate);
	if (out.is_open())
	{
		cout << " Done the saved in file " << endl;
		out << size;
		out << endl;
		for (int i = 0; i < size; i++)
		{
			out << arr[i].id << " " << arr[i].make << " " << arr[i].modle << " " << arr[i].year << " " << arr[i].color << " " << arr[i].engine << " " << arr[i].price;
			out << endl;
		}
	}
	else
		cerr << "Can't open the file ";
	out.close();

	cout << endl;
}
//By meera edwan
void display(Car arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i].id << " " << arr[i].make << " " << arr[i].modle << " " << arr[i].year << " " << arr[i].color << " " << arr[i].engine << " " << arr[i].price;
		cout << endl;
	}
	cout << endl;
}
void displayByPrice(Car arr[], int size)
{
	int priceSrc;
	cout << " please enter Price of car = ";
	cin >> priceSrc;
	cout << endl;
	for (int i = 0; i < 5; ++i)
	{
		if (arr[i].price < priceSrc)
		{
			cout << arr[i].id << " " << arr[i].make << " " << arr[i].modle << " " << arr[i].year << " " << arr[i].color << " " << arr[i].engine << " " << arr[i].price;
			cout << endl;
		}
	}
	cout << endl;
}
void quit()
{
	cout << "Thank you , The program quit ";
	cout << endl;

}
//By ahmad adel
void displayModel(Car arr[], int size)
{
	char markOfCar[20];
	cout << "Please enter the mark of car = " << endl;
	cin >> markOfCar;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(markOfCar, arr[i].make) == 0)
		{
			cout << arr[i].id << " " << arr[i].make << " " << arr[i].modle << " " << arr[i].year << " " << arr[i].color << " " << arr[i].engine << " " << arr[i].price << endl;
		}
	}

	cout << endl;
	//by ahmad adel
}
void displaySortedPrice(Car arr[], int size)
{
	int temp = 0;
	int i, j = 0;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			if (arr[j].price < arr[i].price)
			{
				temp = arr[j].price;
				arr[j].price = arr[i].price;
				arr[i].price = temp;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i].id << " " << arr[i].make << " " << arr[i].modle << " " << arr[i].year << " " << arr[i].color << " " << arr[i].engine << " " << arr[i].price;
		cout << endl;
	}
	cout << endl;
	cout << endl;
}
void displayByYear(Car arr[], int size)
{
	int carYear;
	cout << "please enter the years = ";
	cin >> carYear;
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		if (carYear == arr[i].year)
		{
			cout << arr[i].id << " " << arr[i].make << " " << arr[i].modle << " " << arr[i].year << " " << arr[i].color << " " << arr[i].engine << " " << arr[i].price << endl;
		}
	}
	cout << endl;
	cout << "The sorted = " << endl;
	int temp = 0;
	int i, j = 0;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			if (arr[j].year < arr[i].year)
			{
				temp = arr[j].year;
				arr[j].year = arr[i].year;
				arr[i].year = temp;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i].id << " " << arr[i].make << " " << arr[i].modle << " " << arr[i].year << " " << arr[i].color << " " << arr[i].engine << " " << arr[i].price;
		cout << endl;
	}
	cout << endl;
}
int main()
{
	int size = 5;
	Car* c = new Car[size];
	const char fileName[50] = "C:\\Users\\Faris Sahili\\Desktop\\cars.txt";
	ifstream in;
	in.open(fileName);
	if (in.is_open())
	{
		int numOfCar;
		int i = 0;
		in >> numOfCar;
		while (!(in.eof()) && i < size)
		{
			in >> c[i].id >> c[i].make >> c[i].modle >> c[i].year >> c[i].color >> c[i].engine >> c[i].price;
			i++;
		}
	}
	else
		cerr << "Can't open the file ---";
	int choice;
	do
	{
		menuItems();
		cout << endl;
		cout << "Please enter your choice = "; cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1: addRecord(c, size); break;
		case 2:deleteRecord(c, size); break;
		case 3:updateRec(c, size); break;
		case 4:display(c, size); break;
		case 5:displayByPrice(c, size); break;
		case 6:displayModel(c, size); break;
		case 7:displaySortedPrice(c, size); break;
		case 8:displayByYear(c, size); break;
		case 9:saveInfo(c, size); break;
		case 10:quit(); break;
		default:
			cout << "Error! The operator is not correct , please try again " << endl;
		}
	} while (choice != 10);
}