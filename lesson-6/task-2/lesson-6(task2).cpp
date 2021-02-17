#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime> // time

using namespace std;

void printArray(int** arr, unsigned n, unsigned m) // печать массива
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
void initArray(int** arr, unsigned n, unsigned m) // Задание-2 (инициализация массива псевдослучайными числами)
{
	srand(time(NULL)); // генератор случайных чисел (постоянно новые числа)
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			arr[i][j] = rand() % 100; // диапозон чисел от 0 до 99
		}
	}
}

void memAlloc(int** ptrArr, unsigned m, unsigned n)
{
	for (size_t i = 0; i < n; i++)
	{
		ptrArr[i] = new int[n];
	}
}
void freeMem(int** ptrArr, unsigned n)
{
	for (size_t i = 0; i < n; i++) {
		delete[] ptrArr[i];
	}
	delete[] ptrArr;
	ptrArr = nullptr;
}

int main()
{
	cout << "Task-2" << endl;
	cout << "Array 4x4(rand): " << endl;
	int** ptrArr;
	const size_t m = 4;
	const size_t n = 4;

	ptrArr = new int* [m];

	memAlloc(ptrArr, m, n);
	initArray(ptrArr, m, n);
	printArray(ptrArr, m, n);
	freeMem(ptrArr, n);
}