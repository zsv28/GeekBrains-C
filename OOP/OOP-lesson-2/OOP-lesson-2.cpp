#include <iostream>
#include <string>

using namespace std;

//Задание-1
//Создать класс Person (человек) с полями: имя, возраст, пол и вес.
//Определить методы переназначения имени, изменения возраста и веса.
//Создать производный класс Student (студент), имеющий поле года обучения.
//Определить методы переназначения и увеличения этого значения.
//Создать счетчик количества созданных студентов.
//В функции main() создать несколько студентов. По запросу вывести определенного человека.

class Person {
protected:
	string name;
	int age;
	string gender;
	double weight;
public:
	Person(string n, int a, string g, double w) : name(n), age(a), gender(g), weight(w) {}
	void set_name(string n) {
		name = n;
	}
	void set_age(int a) {
		age = a;
	}
	void set_weight(double w) {
		weight = w;
	}
	string get_name() const {
		return name;
	}
};
class Student : public Person {
private:
	int yearStudy;
	static int count;
public:
	static int get_count() {
		return count;
	}
	Student(string n, int a, string g, double w, int y) : yearStudy(y), Person(n, a, g, w) {
		count++;
	}
	~Student() {
		count--;
	}
	void set_yearStudy(int y) {
		yearStudy = y;
	}
	void print() const {
		cout << "Name: " << name << " " << " age: " << age << " " << " gender: " << gender << " " << " weight(kg): " << weight << " year of study: " << yearStudy << endl;
	}
};

int Student::count = 0;

//Задание-2
//Создать классы Apple(яблоко) и Banana(банан), которые наследуют класс Fruit(фрукт).
//У Fruit есть две переменные - члена: name(имя) и color(цвет).
//Добавить новый класс GrannySmith, который наследует класс Apple.

class Fruit {
private:
	string name;
	string color;
public:
	Fruit(string n, string c) : name(n), color(c) {}
	string getname() const {
		return name;
	}
	string getcolor() const {
		return color;
	}
};
class Apple : public Fruit {
protected:
	Apple(string n, string c) : Fruit(n, c) {}
public:
	Apple(string color = "red") : Fruit("apple", color) {}
};
class Banana : public Fruit {
public:
	Banana() : Fruit("banana", "yellow") {}
};
class GrannySmith : public Apple {
public:
	GrannySmith() : Apple("Granny Smith apple", "green") {}
};

//Задание-3
//Изучить правила игры в Blackjack.
//Подумать, как написать данную игру на С++, используя объектно - ориентированное программирование.
//Сколько будет классов в программе ? Какие классы будут базовыми, а какие производными ?
//Продумать реализацию игры с помощью классов и записать результаты.

class Card { //карта для игры в Blackjack
};
class Hand { //набор карт для игры, коллекция объектов card
};
class Deck : Hand { //тасование и раздача карт
};
class GennericPlayer : Hand { //описание игрока(человека и компьютера)
};
class Player : GennericPlayer { //человек-игрок
};
class Сroupier : GennericPlayer { // диллер(крупье) игрок
};
class Game { //процесс самой игры
};
//P.S. Данную структуру взял из книги Майкла Доусона

int main()
{
	//Задание-1
	cout << "Task-1" << endl;
	Student student1("Sam", 23, "male", 62, 2007);
	Student student2("Alex", 19, "male", 75, 2008);
	Student student3("Ivan", 26, "male", 80, 2001);
	cout << "Create " << Student::get_count() << " students: " << endl;
	cout << student1.get_name() << " " << student2.get_name() << " " << student3.get_name() << endl;
	cout << "Enter the name of the student you are interested in: ";
	string i;
	cin >> i;
	if (i == student1.get_name()) {
		student1.print();
	}
	else if (i == student2.get_name()) {
		student2.print();
	}
	else if (i == student3.get_name()) {
		student3.print();
	}
	else {
		cout << "There is no such student!" << endl;
	}

	//Задание-2
	cout << "Task-2" << endl;
	Apple a("red");
	Banana b;
	GrannySmith c;
	cout << "My " << a.getname() << " is " << a.getcolor() << endl;
	cout << "My " << b.getname() << " is " << b.getcolor() << endl;
	cout << "My " << c.getname() << " is " << c.getcolor() << endl;

	return 0;
}