#include <iostream>
#include <cmath> // библиотека для функции pow

using namespace std;

void printArray(int arr[], unsigned size) // печать массива
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void initArray(int* arr, int n) // Задание-1 (инициализация массива стеменями 2-ки)
{
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = pow(2, i);
	}
}

int main()
{
	cout << "Task-1" << endl;
	int* ptrArr;
	int n;
	cout << "Enter size array: ";
	cin >> n;

	if (n > 0)
	{
		ptrArr = new int[n];

		if (ptrArr != nullptr)
		{
			cout << "Your array: ";
			initArray(ptrArr, n);
			printArray(ptrArr, n);
			delete[] ptrArr;
			ptrArr = nullptr;
		}
	}
	else
	{
		cout << "Error!";
	}

	return 0;
}