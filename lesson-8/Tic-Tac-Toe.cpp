//Программа Крестики - нолики
//Компьютер играет в "Крестики-нолики" против пользователя
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//глобальные константы
const char X = 'X';
const char O = '0';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_WON = 'N';

//прототипы функций

void instructions()
{
	cout << "Welcome to the game: Tic-Tac-Toe." << endl;
	cout << "Make your move known by entering a number 0 - 8. The number" << endl;
	cout << "corresponds to the desired board position as illustrated:" << endl;
	cout << " O | 1 | 2" << endl;
	cout << " ---------" << endl;
	cout << " 3 | 4 | 5" << endl;
	cout << " ---------" << endl;
	cout << " 6 | 7 | 8" << endl;
	cout << "Good luck in the game." << endl;
}
char askYesNo(string question)
{
	char response;
	do
	{
		cout << question << "(y/n):";
		cin >> response;
	} while (response != 'y' && response != 'n');
	return response;
}
int askNumber(string question, int high, int low)
{
	int number;
	do
	{
		cout << question << " (" << low << " - " << high << "): ";
		cin >> number;
	} while (number > high || number < low);
	return number;
}
char humanPiece()
{
	char go_first = askYesNo("Do you require the first move?");
	if (go_first == 'y')
	{
		cout << endl << "Then take the first move. You will need it." << endl;

		return X;
	}
	else
	{
		cout << endl << "Good ... I will go first." << endl;

		return O;
	}
}
char opponent(char piece)
{
	if (piece == X)
	{
		return O;
	}
	else
	{
		return X;
	}
}
void displayBoard(const vector<char>& board)
{
	cout << endl << board[0] << " | " << board[1] << " | " << board[2];
	cout << endl << "---------";
	cout << endl << board[3] << " | " << board[4] << " | " << board[5];
	cout << endl << "---------";
	cout << endl << board[6] << " | " << board[7] << " | " << board[8];
	cout << endl << endl;
}
char winner(const vector<char>& board)
{
	// все возможные выигрышные ряды
	const int WINNING_ROWS[8][3] =
	{ {0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},
		{0, 4, 8},
		{2, 4, 6}
	};
	const int TOTAL_ROWS = 8;
	// если в одном из выигрышных рядов уже присутствуют три одинаковых значения
	// (причем они не равны EMPTY), то победитель определился

	for (size_t row = 0; row < TOTAL_ROWS; row++)
	{
		if ((board[WINNING_ROWS[row][0]] != EMPTY) && (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) && (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
		{
			return board[WINNING_ROWS[row][0]];
		}
	}
	if (count(board.begin(), board.end(), EMPTY) == 0)
	{
		return TIE;
	}
	return NO_WON;
}
inline bool isLegal(int move, const vector<char>& board)
{
	return (board[move] == EMPTY);
}
int humanMove(const vector<char>& board, char human)
{
	int move = askNumber("Where will you move?", (board.size() - 1), 0);
	while (!isLegal(move, board))
	{
		cout << endl << "That square is already occupied, foolish human." << endl;
		move = askNumber("Where will you move?", (board.size() - 1), 0);
	}
	cout << "Fine..." << endl;
	return move;
}
int computerMove(vector<char> board, char computer)
{
	unsigned int move = 0;
	bool found = false;
	//если компьютер может выиграть следующим ходом, то он делает этот ход
	while (!found && move < board.size())
	{
		if (isLegal(move, board))
		{
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}
		if (!found)
		{
			move++;
		}
	}
	// иначе, если человек может победить следующим ходом, блокировать этот ход
	if (!found)
	{
		move = 0;
		char human = opponent(computer);
		while (!found && move < board.size())
		{
			if (isLegal(move, board))
			{
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}
			if (!found)
			{
				move++;
			}
		}
	}
	//иначе занять следующим ходом оптимальную свободную клетку
	if (!found)
	{
		move = 0;
		unsigned int i = 0;
		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
		// выбрать оптимальную свободную клетку
		while (!found && i < board.size())
		{
			move = BEST_MOVES[i];
			if (isLegal(move, board))
			{
				found = true;
			}
			i++;
		}
	}
	cout << "I shall take square number " << move << endl;
	return move;
}
void announceWinner(char winner, char computer, char human)
{
	if (winner == computer)
	{
		cout << winner << " - computer 's won!" << endl;
		cout << "Computer got the better of you" << endl;
	}
	else if (winner == human)
	{
		cout << winner << " - human 's won!" << endl;
		cout << "No. по! It cannot Ье! Somehow you tricked me." << endl;
	}
	else
	{
		cout << "It's a tie." << endl;
	}
}

int main()
{
	int move;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);
	instructions();
	char human = humanPiece();
	char computer = opponent(human);
	char turn = X;
	displayBoard(board);
	while (winner(board) == NO_WON)
	{
		if (turn == human)
		{
			move = humanMove(board, human);
			board[move] = human;
		}
		else
		{
			move = computerMove(board, computer);
			board[move] = computer;
		}

		displayBoard(board);
		turn = opponent(turn);
	}
	announceWinner(winner(board), computer, human);

	return 0;
}