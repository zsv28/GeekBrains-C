//Задание-4*
//Объявить структуру Сотрудник с различными полями.
//Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack.
//Выделите динамически переменную этого типа. Инициализируйте ее.
//Выведите ее на экран и ее размер с помощью sizeof.
//Сохраните эту структуру в текстовый файл.

#include <iostream>
#include <fstream>

using namespace std;

struct Employee1  //структура Сотрудник
{
	long id; // ID сотрудника
	unsigned short age; // его возраст
	double salary; // его зарплата
};

#pragma pack(push, 1)
struct Employee2
{
	long id;
	unsigned short age;
	double salary;
};
#pragma pack(pop)

int main()
{
	Employee1 emp1;
	emp1.id = 12;
	emp1.age = 35;
	emp1.salary = 120'000;
	Employee2 emp2;
	emp2.id = 14;
	emp2.age = 30;
	emp2.salary = 100'000;
	cout << sizeof(emp1) << endl; // 16
	cout << sizeof(emp2) << endl; // 14

	ofstream file("struct.txt");
	file << "emp2.id = " << emp2.id << " emp2.age = " << emp2.age << " emp2.salary = " << emp2.salary << endl;
	file.close();
	cout << "File struct.txt recorded successfully.";

	//Через указатель по 4 байта в любом случае (экономичнее так выделять память под структуру?)

	/*Employee1* emp3 = new Employee1;
	emp3->id = 12;
	emp3->age = 35;
	emp3->salary = 120'000;
	delete emp3;

	Employee2* emp4 = new Employee2;
	emp4->id = 14;
	emp4->age = 30;
	emp4->salary = 100'000;
	delete emp4;

	cout << sizeof(emp3) << endl;
	cout << sizeof(emp4) << endl;*/

	return 0;
}