#include <iostream>
#include <cmath> // для pow
#include <cstdint>
#include <cassert> //для assert

using namespace std;

//Задание-1
//Создать класс Power, который содержит два вещественных числа. 
//Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел. 
//Еще создать два метода: один с именем set, который позволит присваивать значения переменным, второй — calculate, который будет выводить результат возведения первого числа в степень второго числа. 
//Задать значения этих двух чисел по умолчанию.

class Power 
{
private:
    int numb1 = 5;
    int numb2 = 2;
public:
    void setNumb1(int n1)
    {
        numb1 = n1;
    }
    void setNumb2(int n2)
    {
        numb2 = n2;
    }
    void calculate()
    {
        cout << numb1 << "^" << numb2 << " = " << pow(numb1, numb2) << endl;
    }

};

//Задание-2.
//Написать класс с именем RGBA, который содержит 4 переменные - члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу).
//Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
//Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha.
//Написать функцию print(), которая будет выводить значения переменных - членов.

class RGBA
{
private:
    uint8_t m_red = 0;
    uint8_t m_green = 0;
    uint8_t m_blue = 0;
    uint8_t m_alpha = 255;
public:
    RGBA()
    {

    }
    RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha):m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
    {

    }
    void print()
    {
        cout << "red: " << static_cast <int> (m_red) << " green: " << static_cast <int> (m_green) << " blue: " << static_cast <int> (m_blue) << " alpha: " << static_cast <int> (m_alpha) << endl;
    }
    
};

//Задание-3.
//Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
//private - массив целых чисел длиной 10;
//private целочисленное значение для отслеживания длины стека;
//public - метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
//public - метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
//public - метод с именем pop() для вытягивания и возврата значения из стека.Если в стеке нет значений, то должно выводиться предупреждение;
//public - метод с именем print(), который будет выводить все значения стека.

class Stack
{
private:
    int array[10]; // это будут данные нашего стека 
    int next; // это будет индексом следующего свободного элемента стека

public:

    void reset()
    {
        next = 0;
        for (int i = 0; i < 10; ++i)
            array[i] = 0;
    }

    bool push(int value)
    {
        // Если стек уже заполнен, то возвращаем false
        if (next == 10)
        {
            return false;
        }

        array[next++] = value; // присваиваем следующему свободному элементу значение value, а затем увеличиваем next
        return true;
    }

    int pop()
    {
        // Если элементов в стеке нет, то выводим стейтмент assert
        assert(next > 0);

        // next указывает на следующий свободный элемент, поэтому последний элемент со значением - это m_next-1.
        // Мы хотим сделать следующее:
        // int val = m_array[m_next-1]; // получаем последний элемент со значением
        // --m_next; // m_next теперь на единицу меньше, так как мы только что вытянули верхний элемент стека
        // return val; // возвращаем элемент
        // Весь вышеприведенный код можно заменить следующей (одной) строкой кода
        return array[--next];
    }

    void print()
    {
        cout << "( ";
        for (int i = 0; i < next; ++i)
        {
            cout << array[i] << ' ';
        }
        cout << ")" << endl;
    }
};


int main()
{
    //Задание-1
    cout << "Task-1" << endl;
    Power power;
    power.calculate();
    power.setNumb1(2);
    power.setNumb2(4);
    power.calculate();

    //Задание-2
    cout << "Task-2" << endl;
    RGBA color;
    color.print();
    RGBA color2(0, 32, 45, 255);
    color2.print();

    //Задание-3
    cout << "Task-3" << endl;
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();






}

