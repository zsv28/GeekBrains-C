#include <iostream>
#include <cassert>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;
//#########################################################################################################################################
//Задание-1
//Добавить в контейнерный класс, который был написан в этом уроке, методы:
//-для удаления последнего элемента массива(аналог функции pop_back() в векторах)
//-для удаления первого элемента массива(аналог pop_front() в векторах)
//-для сортировки массива
//-для вывода на экран элементов.

class ArrayInt
{
private:
	int m_length;
	int* m_data;

public:
	ArrayInt() : m_length(0), m_data(nullptr) { }
	ArrayInt(int length) : m_length(length)
	{
		assert(length >= 0);

		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
		set();
	}
	~ArrayInt()
	{
		delete[] m_data;
	}
	void erase() {
		delete[] m_data;

		// Здесь нам нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
		m_data = nullptr;
		m_length = 0;
	}
	int getLength()
	{
		return m_length;
	}
	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}
	// Функция resize изменяет размер массива. Все существующие элементы сохраняются. Процесс медленный
	void resize(int newLength)
	{
		// Если массив уже нужной длины — return
		if (newLength == m_length)
			return;

		// Если нужно сделать массив пустым — делаем это и затем return
		if (newLength <= 0)
		{
			erase();
			return;
		}

		// Теперь знаем, что newLength >0
		// Выделяем новый массив
		int* data = new int[newLength];

		// Затем нужно разобраться с количеством копируемых элементов в новый массив
		// Нужно скопировать столько элементов, сколько их есть в меньшем из массивов
		if (m_length > 0)
		{
			int elementsToCopy = (newLength > m_length) ? m_length : newLength;

			// Поочередно копируем элементы
			for (int index = 0; index < elementsToCopy; ++index)
				data[index] = m_data[index];
		}

		// Удаляем старый массив, так как он нам уже не нужен
		delete[] m_data;

		// И используем вместо старого массива новый! Обратите внимание, m_data указывает
		// на тот же адрес, на который указывает наш новый динамически выделенный массив. Поскольку
		// данные были динамически выделенные — они не будут уничтожены, когда выйдут из области видимости
		m_data = data;
		m_length = newLength;
	}
	void insertBefore(int value, int index)
	{
		// Проверка корректности передаваемого индекса
		assert(index >= 0 && index <= m_length);

		// Создаем новый массив на один элемент больше старого массива
		int* data = new int[m_length + 1];

		// Копируем все элементы до index-а
		for (int before = 0; before < index; ++before)
			data[before] = m_data[before];

		// Вставляем новый элемент в новый массив
		data[index] = value;

		// Копируем все значения после вставляемого элемента
		for (int after = index; after < m_length; ++after)
			data[after + 1] = m_data[after];

		// Удаляем старый массив и используем вместо него новый
		delete[] m_data;
		m_data = data;
		++m_length;
	}
	void push_back(int value)
	{
		insertBefore(value, m_length);
	}
	void removeAt(int index) //удаление элемента по индексу
	{
		assert(index >= 0 && index <= m_length);

		int* data = new int[m_length - 1];

		for (int i = 0; i < index; i++)
			data[i] = m_data[i];

		for (int i = index + 1; i < m_length; i++)
			data[i - 1] = m_data[i];
		delete[] m_data;
		m_data = data;
		--m_length;
	}
	void pop_front() //удаление первого элемента
	{
		removeAt(0);
	}
	void pop_back() //удаление последнего элемента
	{
		removeAt(m_length - 1);
	}
	void sort() //сортировка массива по возрастанию
	{
		int temp; // переменные для хранения мин-ного значения и индекса массива
		for (int i = 0; i < m_length; i++)
		{
			temp = m_data[i]; //инициализируем врем. переменную
			for (int j = i; j < m_length; j++)
				if (temp > m_data[j])//находим минимальный элемент
				{
					temp = m_data[j]; //делаем перестановку
					m_data[j] = m_data[i];
					m_data[i] = temp;
				}
		}
	}
	void set() //ввод случайных элементов массива
	{
		srand(time(0));
		for (int i = 0; i < m_length; i++)
			m_data[i] = rand() % 100;
	}
	void print() //показать массив
	{
		for (int i = 0; i < m_length; i++)
			cout << m_data[i] << "  ";
		cout << endl;
	}
};
//#########################################################################################################################################
//Задание-2
//Дан вектор чисел, требуется выяснить, сколько среди них различных.
//Постараться использовать максимально быстрый алгоритм.
void printV(vector<int>& v)
{
	vector<int>::iterator it;
	for (it = v.begin(); it != unique(v.begin(), v.end()); it++)
	{
		cout << *it << " ";
	}
}
//#########################################################################################################################################

//Задание-3
//Реализовать класс Hand, который представляет собой коллекцию карт.
//В классе будет одно поле : вектор указателей карт(удобно использовать вектор,
//т.к.это по сути динамический массив, а тип его элементов должен быть - указатель на объекты класса Card).
//Также в классе Hand должно быть 3 метода :
//-метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
//-метод Clear, который очищает руку от карт
//-метод GetValue, который возвращает сумму очков карт руки(здесь предусмотреть возможность того, что туз может быть равен 11).
//#########################################################################################################################################
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
//#########################################################################################################################################
class Hand
{
public:
	Hand();
	virtual ~Hand();
	//добавляет карту в руку
	void Add(Card* pcard);
	//очищает руку от карт
	void Clear();
	//получает сумму очков карт в руке, присваивая тузу
	//значение 1 или 11 в зависимости от ситуации
	int GetTotal() const;
protected:
	vector<Card*> m_Cards;
};
Hand::Hand()
{
	m_Cards.reserve(7);
}
Hand::~Hand()
{
	Clear();
}
void Hand::Add(Card* pCard)
{
	m_Cards.push_back(pCard);
}
void Hand::Clear()
{
	//проходит по вектору, освобождая всю память в куче
	vector<Card*>::iterator iter = m_Cards.begin();
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		delete* iter;
		*iter = 0;
	}
	//очищает вектор указателей
	m_Cards.clear();
}
int Hand::GetTotal() const
{
	//если карт нет в руке, возвращает значение 0
	if (m_Cards.empty())
	{
		return 0;
	}
	//если первая карта имеет значение 0, то она лежит рубашкой вверх:
	//вернуть значение 0
	if (m_Cards[0]->GetValue() == 0)
	{
		return 0;
	}
	//находит сумму очков всех карт, каждый туз дает 1 очко
	int total = 0;
	vector<Card*>::const_iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		total += (*iter)->GetValue();
	}
	//определяет, дрежит ли рука туз
	bool containsAce = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		containsAce = true;
	}
	//если рука держит туз и сумма довольно маленькая, туз дает 11 очков
	if (containsAce && total <= 11)
	{
		//добавляем только 10 очков, поскольку мы уже добавили
		//за каждый туз по 1 очку
		total += 10;
	}
	return total;
}
//#########################################################################################################################################

int main()
{
	//Задание-1
	cout << "Task-1" << endl;
	ArrayInt array(5);
	array.print();
	array.sort();
	array.removeAt(3);
	array.print();
	array.pop_front();
	array.print();
	array.pop_back();
	array.print();

	//Задание-2
	cout << endl << "Task-2" << endl;
	vector<int> v{ 1,5,3,4,6,3,7,4,4,3,6,7 };
	printV(v);
	cout << endl;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	printV(v);
	cout << endl << "Different numbers: " << v.size() << endl;
	
	return 0;
}
