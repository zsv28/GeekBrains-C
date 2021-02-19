//Задание-3
//Описать макрокоманду(через директиву define), проверяющую,
//входит ли переданное ей число в диапазон от нуля(включительно)
//до переданного ей второго аргумента(исключительно)и возвращает true или false.

#include <iostream>
//макрос-функция проверки вхождения числа в диапозон
#define SPAN(x, y, z) (z > x && z < y ? cout << "True "<< z << " it is included in the range of numbers from " << x << " to " << y : cout << "False " << z << " not included in the range of numbers from " << x << " to " << y)

using namespace std;

int main()
{
	int a, b, c;
	cout << "Enter a range of numbers " << "from: ";
	cin >> a;
	cout << "before: ";
	cin >> b;
	cout << "Enter your number: ";
	cin >> c;
	SPAN(a, b, c);

	return 0;
}