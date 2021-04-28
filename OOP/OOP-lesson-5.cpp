#include <iostream>
#include <string>
#include <vector>

using namespace std;

//##############################################################################################################
//Задание-1
//Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.
template <class T>
class Pair1
{
private:
	T m_a;
	T m_b;
public:
	Pair1(const T& a, const T& b) : m_a(a), m_b(b)
	{
	}
	T& first()
	{
		return m_a;
	}
	const T& first() const
	{
		return m_a;
	}
	T& second()
	{
		return m_b;
	}
	const T& second() const
	{
		return m_b;
	}
};
//##############################################################################################################
//Задание-2
//Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
template <class T, class S>
class Pair
{
private:
	T m_a;
	S m_b;
public:
	Pair(const T& a, const S& b) : m_a(a), m_b(b)
	{
	}
	T& first()
	{
		return m_a;
	}
	const T& first() const
	{
		return m_a;
	}
	S& second()
	{
		return m_b;
	}
	const S& second() const
	{
		return m_b;
	}
};
//##############################################################################################################
//Задание-3
//Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа.
//Этот шаблон класса должен наследовать частично специализированный класс Pair, в котором первый параметр — string, а второй — любого типа данных.
template <class S>
class StringValuePair : public Pair<string, S>
{
public:
	StringValuePair(const string& a, const S& b) : Pair<string, S>(a, b)
	{
	}
};
//##############################################################################################################
//Задание-4
//Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует класс GenericPlayer, который обобщенно представляет игрока, ведь у нас будет два типа игроков - человек и компьютер.
//Создать класс GenericPlayer, в который добавить поле name - имя игрока.Также добавить 3 метода:
//-IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
//-IsBoosted() - возвращает bool значение, есть ли у игрока перебор
//-Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
class Card {
public:
	enum rank {
		АСЕ = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		JACK, QUEEN, KING
	};
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	// перегружаем оператор <<, чтобы можно было отправить объект
	// типа Card в стандартный поток вывода
	friend ostream& operator<<(ostream& os, const Card& aCard);
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
class GenericPlayer : public Hand
{
	friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
public:
	GenericPlayer(const string& name = " ");
	virtual ~GenericPlayer();
	//показывает, хочет ли игрок продолжать брать карты
	virtual bool IsHitting() const = 0;
	//возвращает значение, если игрок имеет перебор - сумму очков, большую 21
	bool IsBusted() const;
	//объявляет, что игрок имеет перебор
	void Bust() const;
protected:
	string m_Name;
};
GenericPlayer::GenericPlayer(const string& name) : m_Name(name)
{
}
GenericPlayer::~GenericPlayer()
{
}
bool GenericPlayer::IsBusted() const
{
	return (GetTotal() > 21);
}
void GenericPlayer::Bust() const
{
	cout << m_Name << " busts" << endl;
}
//##############################################################################################################

int main()
{
	//Задание-1
	cout << "Task-1" << endl;
	Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.first() << " " << p1.second() << endl;
	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << " " << p2.second() << endl;

	//Задание-2
	cout << endl << "Task-2" << endl;
	Pair<int, double> p_1(6, 7.8);
	cout << "Pair: " << p_1.first() << " " << p_1.second() << endl;
	const Pair<double, int> p_2(3.4, 5);
	cout << "Pair: " << p_2.first() << " " << p_2.second() << endl;

	//Заданеие-3
	cout << endl << "Task-3" << endl;
	StringValuePair<int> svp("Amazing", 7);
	cout << "Pair: " << svp.first() << " " << svp.second() << endl;

	return 0;
}