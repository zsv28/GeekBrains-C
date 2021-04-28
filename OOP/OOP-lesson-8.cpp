#include <iostream>
#include <string>

using namespace std;
//######################################################################################################################################
//Задание-1
//Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров и запускать исключение DivisionByZero,
//если второй параметр равен 0. В функции main выводить результат вызова функции div в консоль, а также ловить исключения.
double div(double x, double y)
{
	if (x == 0 || y == 0)
		throw string("DivisionByZero");
	else
		return (x / y);
}
//######################################################################################################################################
//Задание-2
//Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, инициализирующий x значением параметра.
//Написать класс Bar, хранящий вещественное число y(конструктор по умолчанию инициализирует его нулем) и имеющий метод set с единственным вещественным параметром a.
//Если y + a > 100, возбуждается исключение типа Ex с данными a* y, иначе в y заносится значение a.
//В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.
//Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0.
//В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.
class Ex
{
public:
	double x;
	Ex(const double& x_) : x(x_)
	{
	}
	~Ex()
	{
	}
};

class Bar
{
private:
	double y;

public:
	Bar()
	{
		y = 0;
	}
	~Bar()
	{
	}
	void set(const double& a)
	{
		if (y + a <= 100)
		{
			y = a;
		}
		else throw Ex(y * a);
	}
};
//######################################################################################################################################
//Задание-3
//Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, означающий задание переместиться на соседнюю позицию.
//Эти методы должны запускать классы - исключения OffTheField, если робот должен уйти с сетки, и IllegalCommand, если подана неверная команда(направление не находится в нужном диапазоне).
//Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения.Написать функцию main,
//пользующуюся этим классом и перехватывающую все исключения от его методов, а также выводящую подробную информацию о всех возникающих ошибках.
const int ten = 10;
const int zero = 0;

class Robot;

class Exeptions
{
public:
	static void OffTheField(int x, int y, string command)
	{
		cout << "Exception handled OffTheField" << endl << "Robot coordinates: " << x << ", " << y << endl << "Last command entered: " << command << endl;
	}
	static void IllegalCommand(const Robot& ob, int command);
};

class Robot
{
protected:
	int x, y;
public:
	Robot() { x = 0; y = 0; }

	void up()
	{
		if (y == ten)
		{
			Exeptions::OffTheField(x, y, "Up");
		}
		else y++;
		show();
	}
	void down()
	{
		if (y == zero)
		{
			Exeptions ob;
			ob.OffTheField(x, y, "Down");
		}
		else y--;
		show();
	}
	void left()
	{
		if (x == zero)
		{
			Exeptions ob;
			ob.OffTheField(x, y, "Left");
		}
		else x--;
		show();
	}
	void right()
	{
		if (x == ten)
		{
			Exeptions ob;
			ob.OffTheField(x, y, "Right");
		}
		else x++;
		show();
	}
	void show() const
	{
		cout << "Robot coordinates:" << x << ", " << y << endl;
	}
};

void Exeptions::IllegalCommand(const Robot& ob, int command)
{
	cout << "Exception handled IllegalCommand" << endl;
	ob.show();
	cout << "Last command entered: " << command << endl;
}
//######################################################################################################################################

int main()
{
	//Задание-1
	cout << "Task-1" << endl;
	double x, y;
	try
	{
		cout << "Enter first number: " << endl;
		cin >> x;
		cout << "Enter second number: " << endl;
		cin >> y;
		cout << x << "/" << y << " = " << div(x, y) << endl;
	}
	catch (string)
	{
		cerr << "Error, the number cannot be equal to 0!" << endl;
	}

	//Задание-2
	cout << endl << "Task-2" << endl;
	Bar bar;
	int n{};
	cout << "Enter number: " << endl;
	while (cin >> n && n != 0)
	{
		try
		{
			bar.set(n);
		}
		catch (Ex& err)
		{
			cerr << "Exception: y + a > 100, a * y =  " << err.x << endl;
		}
	}

	//Задание-3
	cout << endl << "Task-3" << endl;
	int command;
	Robot rob;
	while (true)
	{
		cout << "The robot control program. \nEnter: \n1 - to raise the robot one square up. \n2 - on the cell down. \n3 - move the cell to the left. \n4 - move the cell to the right. \n5 - exit the program" << endl;
		cin >> command;
		cout << endl;
		switch (command)
		{
		case 1:
		{
			rob.up();
			break;
		}
		case 2:
		{
			rob.down();
			break;
		}
		case 3:
		{
			rob.left();
			break;
		}
		case 4:
		{
			rob.right();
			break;
		}
		case 5:
		{
			cout << "Exit the program." << endl;
			return 0;
		}
		default:
			Exeptions ob;
			ob.IllegalCommand(rob, command);
			break;
		}
	}
}