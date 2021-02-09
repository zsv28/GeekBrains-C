#include <iostream>

using namespace std;

//функция для 1 задания
void Task_1()
{
	cout << "Task-1" << endl;
	int a, b, sum;
	cout << "Enter two numbers" << endl;
	cout << "Enter a: " << endl;
	cin >> a;
	cout << "a = " << a << endl;
	cout << "Enter b: " << endl;
	cin >> b;
	cout << "b = " << b << endl;
	sum = a + b;
	if (sum >= 10 && sum <= 20)
	{

		cout << sum << " true" << endl;
	}
	else
	{
		cout << sum << " false" << endl;
	}
}

//функция для 2 задания
void Task_2()
{
	cout << "Task-2" << endl;
	const int c = 6, d = 4;
	int sum_2 = c + d;
	if (c == 10 && d == 10 || sum_2 == 10)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}

//фукция для 3 задания
void Task_3()
{
	cout << "Task-3" << endl;
	int min = 1;
	int max = 50;
	int i;
	for (i = min; i < max; i+=2)
	{
			cout << i << " ";
	}
}

//функция для 4 задания

void Task_4()
{
	cout << endl <<"Task-4" << endl;
	int j,h;
	bool prime = true;
	cout << "Enter one number: " << endl;
	cin >> h;
	for (j = 2; j * j <= h; j++)
	{
		if (h % j == 0)
		{
			prime = false;
			break;
		}
	}
	if (prime)
	{
		cout << h << " is a prime number";
	}
	else
	{
		cout << h << " is a not prime number";
	}
}

//функция для 5 задания 
void Task_5()
{
	cout << endl <<"Task-5" << endl;
	int year;
	do
	{
		cout << "Enter the year from 1 to 3000:" << endl;
		cin >> year;

	} while (year < 1 || year > 3000);
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		cout << year << " leap";
	}
	else
	{
		cout << year << " no leap";
	}
}

int main()
{
	/* готовые функции каждого задания
	Task_1();
	Task_2();
	Task_3();
	Task_4();
	Task_5();*/

	return 0;
}