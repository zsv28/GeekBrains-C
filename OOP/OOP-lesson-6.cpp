#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
//################################################################################
//Задание-1
//Создать программу, которая считывает целое число типа int.
//И поставить «защиту от дурака» : если пользователь вводит что - то кроме одного целочисленного значения,
//нужно вывести сообщение об ошибке и предложить ввести число еще раз.Пример неправильных введенных строк :
//-rbtrb
//-nj34njkn
//-1n
void input()
{
	int a;
	bool b = true;
	while (b)
	{
		cin >> a;
		if (cin.fail() || cin.get() != '\n')
		{
			cout << "Not an int number. Repeat input: " << endl;
			cin.clear();
			cin.ignore(32727, '\n');

			b = true;
		}
		else b = false;
	}
	cout << "int = " << a << endl;
}
//################################################################################
//Задание-2
//Создать собственный манипулятор endll для стандартного потока вывода,
//который выводит два перевода строки и сбрасывает буфер.

ostream& endll(ostream& os)
{
	os.put(os.widen('\n'));
	os.flush();
	return (os << '\n');
}
//##################--------------Blackjack----------------#################################################
class Card {
public:
	enum rank {
		АСЕ = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		JACK, QUEEN, KING
	};
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	// перегружаем оператор <<, чтобы можно было отправить объект
	// типа Card в стандартный поток вывода
	friend ostream& operator<< (ostream& os, const Card& aCard); // задание-5
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
	friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer); // задание -5
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

//Задание-3
//Реализовать класс Player, который наследует от класса GenericPlayer.У этого класса будет 4 метода:
//virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса.
//Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
//void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
//void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
//void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.

class Player : public GenericPlayer
{
public:
	Player(const string& name = " ");
	virtual ~Player();
	//показывает, хочет ли игрок продолжать брать карты
	virtual bool IsHitting() const;
	//объявляет, что игрок победил
	void Win() const;
	//объявляет, что игрок проиграл
	void Lose() const;
	//объявляет ничью
	void Push() const;
};
Player::Player(const string& name) : GenericPlayer(name)
{
}
Player::~Player()
{
}
bool Player::IsHitting() const
{
	cout << m_Name << " , do you want a hit? (Y/N): ";
	char response;
	cin >> response;
	return (response == 'y' || response == 'Y');
}
void Player::Win() const
{
	cout << m_Name << " wins. \n";
}
void Player::Lose() const
{
	cout << m_Name << " loses. \n";
}
void Player::Push() const
{
	cout << m_Name << " pushes. \n";
}

//Задание-4
//Реализовать класс House, который представляет дилера.Этот класс наследует от класса GenericPlayer.
//У него есть 2 метода:
//-virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта.
//Если у дилера не больше 16 очков, то он берет еще одну карту.
//-void FlipFirstCard() - метод переворачивает первую карту дилера.

class House : public GenericPlayer
{
public:
	House(const string& name = "House");
	virtual ~House();
	//показывает, хочет ли игрок продолжать брать карты
	virtual bool IsHitting() const;
	//переворачивает первую карту
	void FlipFirstCard();
};
House::House(const string& name) : GenericPlayer(name)
{
}
House::~House()
{
}
bool House::IsHitting() const
{
	return (GetTotal() <= 16);
}
void House::FlipFirstCard()
{
	if (!(m_Cards.empty()))
	{
		m_Cards[0]->Flip();
	}
	else
	{
		cout << "No card to flip!\n";
	}
}

//Задание-5
//Написать перегрузку оператора вывода для класса Card. Если карта перевернута рубашкой вверх(мы ее не видим),
//вывести ХХ, если мы ее видим, вывести масть и номинал карты. Также для класса GenericPlayer написать перегрузку оператора вывода,
//который должен отображать имя игрока и его карты, а также общую сумму очков его карт.

//перегружает оператор <<, чтобы получить возможность отправить объект типа Card в поток cout
ostream& operator<< (ostream& os, const Card& aCard)
{
	const string RANKS[] = { "0","A","2","3","4","5","6","7","8","9","10",
	"J","Q","K" };
	const string SUITS[] = { "c","d","h","s" };
	if (aCard.m_IsFaceUp)
	{
		os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
	}
	else
	{
		os << "XX";
	}
	return os;
}
//перегружает оператор <<, чтобы получить возможность отправить объект типа GenericPlayer в поток cout
ostream& operator<< (ostream& os, const GenericPlayer& aGenericPlayer)
{
	os << aGenericPlayer.m_Name << ":\t";
	vector<Card*>::const_iterator pCard;
	if (!aGenericPlayer.m_Cards.empty())
	{
		for (pCard = aGenericPlayer.m_Cards.begin();
			pCard != aGenericPlayer.m_Cards.end(); ++pCard)
		{
			os << *(*pCard) << "\t";
		}
		if (aGenericPlayer.GetTotal() != 0)
		{
			cout << "(" << aGenericPlayer.GetTotal() << ")";
		}
	}
	else
	{
		os << "<empty>";
	}
	return os;
}
//################################################################################
int main()
{
	//Задание-1
	cout << "Task-1" << endl;
	cout << "Enter number(int): " << endl;
	input();

	//Задания-2
	cout << endll << "Task-2" << endll;
	cout << "test - endll" << endll;

	return 0;
}