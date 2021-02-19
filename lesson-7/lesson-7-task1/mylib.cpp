#include <iostream>
#include <cstdlib> // для rand
#include <ctime> // для time

namespace MyLib // инициализация собственного namespace
{
	float randNumb(float min, float max) // функция радномных чисел
	{
		return (float)(rand()) / RAND_MAX * (max - min) + min;
	}
	void initArray(float* array, unsigned size)
	{
		srand(time(NULL));

		for (int i = 0; i < size; i++)
		{
			array[i] = randNumb(-10.0f, 10.0f);
		}
	}

	void printArray(const float array[], unsigned size)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;
	}
	int negative(float* array, unsigned size)
	{
		int neg = 0;
		for (int i = 0; i < size; i++)
		{
			if (array[i] < 0)
			{
				neg++;
			}
		}
		std::cout << "Negative numbers: " << neg;
		return neg;
	}
}