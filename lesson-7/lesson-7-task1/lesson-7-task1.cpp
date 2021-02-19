//Задание 1(5*)
//Создайте проект из 2х cpp файлов и заголовочного(main.cpp, mylib.cpp, mylib.h)
//во втором модуле mylib объявить 3 функции для инициализации массива(типа float),
//печати его на экран(так же передавайте размер массива параметром функций) и подсчета количества отрицательных элементов.
//Вызывайте эти 3 - и функции из main для работы с массивом.
//* Сделайте задание 1 добавив свой неймспейс во втором модуле.

#include <iostream>
#include "mylib.h"

int main()
{
	const unsigned size = 10;
	float arr[size];

	std::cout << "Task-1" << std::endl;
	MyLib::initArray(arr, size);
	MyLib::printArray(arr, size);
	MyLib::negative(arr, size);

	return 0;
}