#include <iostream>

using namespace std;

//Задание 2

enum TicTakToe { X, O }; // возможные символы для игры в "Крестики - Нолики"

//Задание 4*

struct gameField
{
	unsigned short width; //Высота игрового поля
	unsigned short height; //Ширина игрового поля
	unsigned short cell; // Колличество клеток игрового поля
};

//Задание 5**
struct TypeBit
{
	union Type
	{
		int i; float f; char ch;
		unsigned isInt : 1;
		unsigned isFloat : 1;
		unsigned isChar : 1;
	};
};

int main()
{
	//Задание 1

	short Var = 43;
	int iVar = 2345;
	long long lVar = 4'500'000'000;
	char cVar = 'q';
	bool bVar = false;
	float fVar = 765.42F;
	double dVar = 214.243;

	//Задание 3

	TicTakToe symbolX = X;
	TicTakToe symbolO = O;
	int Arr[2] = { symbolX, symbolO };
	cout << "Arr[0] = " << Arr[0] << "\nArr[1] = " << Arr[1] << endl;

	//Пример задания 4*

	gameField field;
	field = { 3, 3, 9 };

	cout << "Width = " << field.width << endl << "Height = " << field.height << endl
		<< "Cell = " << field.cell << endl;

	//Пример задания 5**

	TypeBit::Type a;
	a.isInt = a.i;
	a.isFloat = a.f;
	a.isChar = a.ch;
	a.i = 1;
	cout << "int = " << a.i << endl;
	cout << "float = " << a.f << endl;
	cout << "char = " << a.ch << endl;
	a.ch = 'b';
	cout << "int = " << a.i << endl;
	cout << "float = " << a.f << endl;
	cout << "char = " << a.ch << endl;

	return 0;
}