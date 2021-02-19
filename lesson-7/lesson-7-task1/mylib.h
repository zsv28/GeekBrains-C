#pragma once
namespace MyLib //Заголовочный файл с прототипом функций
{
	void initArray(float* array, unsigned size); //инициализация
	void printArray(const float array[], unsigned size); // печать
	int negative(float* array, unsigned size); // подсчет отрицательных чисел
}