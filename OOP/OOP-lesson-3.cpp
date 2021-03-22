#include <iostream>
#include <string>

using namespace std;

//Задание-1
//Создать абстрактный класс Figure(фигура).
//Его наследниками являются классы Parallelogram(параллелограмм) и Circle(круг).
//Класс Parallelogram — базовый для классов Rectangle(прямоугольник), Square(квадрат), Rhombus(ромб).
//Для всех классов создать конструкторы.Для класса Figure добавить чисто виртуальную функцию area() (площадь).
//Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.

class Figure {
public:
	virtual void area() = 0;
	virtual ~Figure() { }
};
class Parallelogram : public Figure {
protected:
	int length;
	int height;
public:
	Parallelogram(int l, int h) : length(l), height(h) {}
	void area() override {
		cout << "The parallelogram area is " << length * height << endl;
	}
};
class Circle : public Figure {
private:
	double radius;
	double P = 3.1415;
public:
	Circle(double r) : radius(r) { }
	void area() override {
		cout << "The area of the circle is " << P * (radius * radius) << endl;
	}
};
class Rectangle : public Parallelogram {
public:
	Rectangle(int l, int h) : Parallelogram(l, h) { }
	void area() override {
		cout << "The rectangle area is " << length * height << endl;
	}
};
class Square : public Parallelogram {
public:
	Square(int l, int h) : Parallelogram(l, h) { }
	void area() override {
		cout << "The square area is " << length * height << endl;
	}
};
class Rhombus : public Parallelogram {
public:
	Rhombus(int l, int h) : Parallelogram(l, h) { }
	void area() override {
		cout << "The area rhombus is " << length * height << endl;
	}
};

//#######################################################################################
//Задание-2
//Создать класс Car(автомобиль) с полями company(компания) и model(модель).
//Классы - наследники: PassengerCar(легковой автомобиль) и Bus(автобус).
//От этих классов наследует класс Minivan(минивэн).
//Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
//Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.
//Обратить внимание на проблему «алмаз смерти».

class Car {
protected:
	string company;
	string model;
public:
	Car(string c, string m) : company(c), model(m) {
		cout << c << endl << m << endl;
	}
	~Car() { }
};
class PassenerCar : virtual public Car {
public:
	PassenerCar(string c, string m, string p) : Car(c, m) {
		cout << "Passener car: " << p << endl;
	}
};
class Bus : virtual public Car {
public:
	Bus(string c, string m, string b) : Car(c, m) {
		cout << "Bus: " << b << endl;
	}
};
class Minivan : public PassenerCar, public Bus {
public:
	Minivan(string c, string m, string p, string b) : PassenerCar(c, m, p), Bus(c, m, b), Car(c, m) {
	}
};

//#######################################################################################
//Задание-3
//Создать класс : Fraction(дробь).Дробь имеет числитель и знаменатель(например, 3 / 7 или 9 / 2).
//Предусмотреть, чтобы знаменатель не был равен 0.
//Перегрузить :
//-математические бинарные операторы(+, -, *, / ) для выполнения действий с дробями
//-унарный оператор(-)
//-логические операторы сравнения двух дробей(== , != , <, >, <= , >= ).

class Fraction
{
private:
	int numerator;
	int denominator;

public:
	Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) { }
	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator+(const Fraction& f1, const Fraction& f2);
	friend Fraction operator-(const Fraction& f1, const Fraction& f2);
	friend Fraction operator/(const Fraction& f1, const Fraction& f2);
	friend bool operator>=(const Fraction& f1, const Fraction& f2);
	Fraction operator-() const; // Унарный минус

	int get_num() const {
		return numerator;
	}
	int get_denom() const {
		return denominator;
	}

	void print() const {
		cout << numerator << "/" << denominator << endl;
	}
	void lowterms() // сокращение дроби(ф-ция позаимствована)
	{
		long tnum, tden, temp, gcd;
		tnum = labs(numerator);
		tden = labs(denominator);

		while (tnum != 0)
		{
			if (tnum < tden)
			{
				temp = tnum; tnum = tden; tden = temp;
			}
			tnum = tnum - tden;
		}
		gcd = tden;
		numerator = numerator / gcd;
		denominator = denominator / gcd;
	}
};
Fraction operator*(const Fraction& f1, const Fraction& f2) {
	return Fraction(f1.numerator * f2.numerator, f1.denominator * f2.denominator);
}
Fraction operator+(const Fraction& f1, const Fraction& f2) {
	return Fraction(f1.numerator * f2.denominator + f1.denominator * f2.numerator, f1.denominator * f2.denominator);
}
Fraction operator-(const Fraction& f1, const Fraction& f2) {
	return Fraction(f1.numerator * f2.denominator - f1.denominator * f2.numerator, f1.denominator * f2.denominator);
}
Fraction operator/(const Fraction& f1, const Fraction& f2) {
	return Fraction(f1.numerator * f2.denominator, f1.denominator * f2.numerator);
}
Fraction Fraction::operator-() const // Унарный минус
{
	return Fraction(-numerator, denominator);
}
bool operator>=(const Fraction& f1, const Fraction& f2) {
	return !(f1.numerator * f2.denominator < f2.numerator* f1.denominator);
}

//#######################################################################################
//Задание-4
//Создать класс Card, описывающий карту в игре БлэкДжек.
//У этого класса должно быть три поля : масть, значение карты и положение карты(вверх лицом или рубашкой).
//Сделать поля масть и значение карты типом перечисления(enum).
//Положение карты - тип bool.Также в этом классе должно быть два метода :
//метод Flip(), который переворачивает карту, т.е.если она была рубашкой вверх,
//то он ее поворачивает лицом вверх, и наоборот.
//метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.

class Card {
public:
	enum rank {
		АСЕ = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		JACK, QUEEN, KING
	};
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	// перегружаем оператор <<, чтобы можно было отправить объект
	// типа Card в стандартный поток вывода
//friend ostream& operator<<(ostream& os, const Card& aCard);
	Card(rank r = АСЕ, suit s = SPADES, bool ifu = true);
	// возвращает значение карты, от 1 до 11
	int GetValue() const;
	//переворачивает карту : карта.лежащая лицом вверх.
	//переворачивается лицом вниз и наоборот
	void Flip();
private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};
Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) { }
int Card::GetValue() const {
	//если карта перевернута лицом вниз.ее значение равно О
	int value = 0;
	if (m_IsFaceUp) {
		// значение - это число.указанное на карте
		value = m_Rank;
		// значение равно 10 для открытых карт
		if (value > 10)
		{
			value = 10;
		}
		return value;
	}
}
void Card::Flip() {
	m_IsFaceUp = !(m_IsFaceUp);
}
//#######################################################################################

int main()
{
	//Задание-1
	cout << "Task-1" << endl;
	Figure* circle = new Circle(15);
	circle->area();
	delete circle;
	Parallelogram* rhombus = new Rhombus(14, 12);
	rhombus->area();
	delete rhombus;

	//Задание-2
	cout << endl << "Task-2" << endl;
	Minivan* Minivan1 = new Minivan("Company : Mercedes", "Model: ", "S-200", "Tourism");
	delete Minivan1;

	//Задание-3
	cout << endl << "Task-3" << endl;

	cout << "binary operator" << endl;
	Fraction f1(3, 7);
	f1.print();
	Fraction f2(2, 14);
	f2.print();
	Fraction f3 = operator*(f1, f2);
	f3.lowterms();
	cout << "3/7 * 2/14 = ";
	f3.print();

	cout << "unary operator" << endl;
	Fraction f4(3, 7);
	cout << (-f4).get_num() << "/" << f4.get_denom() << endl;

	cout << "logical operator" << endl;
	if (f1 >= f2) {
		cout << "f1 > f2" << endl;
	}
	else
		cout << "No! f1 < f2";
}