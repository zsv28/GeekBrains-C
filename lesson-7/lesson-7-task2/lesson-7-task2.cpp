//Задание 2
//Задайте 2-а массива для типов int и double.
//Пусть их размер будет 5 и 10.
//Задайте их размер через директиву препроцессора #define.
//Инициализируйте их через ввод с клавиатуры. И выведите на экран.

#include <iostream>
#define ARRAY_SIZE_INT 5 //Макрос для размера массива типа int
#define ARRAY_SIZE_DOUBLE 10 //Макрос для размера массива типа double

using namespace std;

void initArray_Int(int* array) //Функция ручного ввода массива типа int
{
	for (size_t i = 0; i < ARRAY_SIZE_INT; i++)
	{
		cin >> array[i];
		cout << "array[" << i << "] = " << array[i] << endl;
	}
}
void initArray_Double(double* array) //Функция ручного ввода массива типа double
{
	for (size_t i = 0; i < ARRAY_SIZE_DOUBLE; i++)
	{
		cin >> array[i];
		cout << "array[" << i << "] = " << array[i] << endl;
	}
}
//2 функции печати массивов
void printArray_Int(const int array[])
{
	cout << "You Int Array = ";
	for (size_t i = 0; i < ARRAY_SIZE_INT; i++)
	{
		cout << "array[" << i << "] = " << array[i] << " ";
	}
	cout << endl;
}
void printArray_Double(const double array[])
{
	cout << "You Double Array = ";
	for (size_t i = 0; i < ARRAY_SIZE_DOUBLE; i++)
	{
		cout << "array[" << i << "] = " << array[i] << " ";
	}
	cout << endl;
}

int main()
{
	cout << "Task-2" << endl;

	int arr_Int[ARRAY_SIZE_INT];
	cout << "Fill in an Int array of 5 numbers: " << endl;
	initArray_Int(arr_Int);
	printArray_Int(arr_Int);
	cout << endl;

	double arr_Double[ARRAY_SIZE_DOUBLE];
	cout << "Fill in an Double array of 10 numbers: " << endl;
	initArray_Double(arr_Double);
	printArray_Double(arr_Double);

	return 0;
}