#include <iostream>
#include <cstdlib>

using namespace std;

const int SIZE = 10;

bool PrintArray(double arr[], int SIZE) // Задание - 1. Функция печати массива рандомными числами.
{
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = (double)rand() / (double)RAND_MAX * (20 - 0); // заполнение массива псевдорандомными числами
		cout << arr[i] << " ";
	}
	cout << endl;
	return true;
}
void swap(int* arrI, int SIZE) // Задание-2. Функция замены элементов массива
{
	for (size_t j = 0; j < SIZE; j++)
	{
		arrI[j] = arrI[j] == 1 ? 0 : 1;
		cout << arrI[j] << " ";
	}
	cout << endl;
}
void fill(int* arrC, int step, int shift) // Задание-3. Функция заполнения массива, где int step - шаг заполнения, int shift - смещение по массиву.
{
	for (size_t k = 0; k < 8; k++) 
	{
		arrC[k] = shift + k * step;
		cout << arrC[k] << " ";
	}
	cout << endl;
}

int main()
{
	cout << "Task-1" << endl; // Задание-1
	
	double myArr[SIZE];

	if (PrintArray(myArr, SIZE))
	{
		cout << "Array initialization completed!" << endl;
	}
	
	cout << endl << "Task-2" << endl; //Задание-2
	int sArr[SIZE] = { 1,0,0,0,1,1,0,1,0,0 };

	for (size_t f = 0; f < SIZE; f++)
	{
		cout << sArr[f] << " ";

	}
	cout << endl << "swap Array" << endl;
	swap(sArr, SIZE);
	
	cout << endl << "Task-3" << endl; //Задание-3
	int cArr[8];
	fill(cArr,3,1);

	return 0;
}