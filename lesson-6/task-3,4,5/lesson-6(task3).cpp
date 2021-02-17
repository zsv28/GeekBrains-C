#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void file() //Задание-3(заполнение 2-х файлов)
{
	cout << "Enter name file-1: ";
	string name1;
	cin >> name1;
	ofstream f1;
	f1.open(name1 + ".txt");
	f1 << "Test version of the file for checking the operation of this function.";
	f1.close();
	cout << "File-1: " << name1 + ".txt" << " successfully created" << endl;
}
void file2()
{
	cout << "Enter name file-2: ";
	string name2;
	cin >> name2;
	ofstream f2;
	f2.open(name2 + ".txt");
	f2 << "Trial text for writing the second file using the function.";
	f2.close();
	cout << "File-2: " << name2 + ".txt" << " successfully created" << endl;
}
int gluing() //Задание-4(склеивание 2- файлов)
{
	string name1, name2, name3;
	cout << "Enter name file-1:";
	cin >> name1;
	cout << "Enter name file-2:";
	cin >> name2;
	cout << "Enter new name file-3:";
	cin >> name3;
	ifstream file1(name1);
	ifstream file2(name2);
	ofstream out(name3 + ".txt");

	if (!file1.is_open() || !file2.is_open() || !out.is_open())
	{
		cout << "File not find" << endl;
		cout << "exit";
		cin.get();
		return -1;
	}
	else
	{
		cout << name1 << " and " << name2 << " successfully copied to a file " << name3 + ".txt";
	}

	string str;

	while (getline(file1, str))
	{
		out << str;
	}
	while (getline(file2, str))
	{
		out << str;
	}
}
void findWord() //Задание-5(поиск слова в файле)
{
	string filename, word, buf;
	char c;

	cout << "Enter the path and name of your file: ";
	cin >> filename;
	cout << "Enter the word you want to find: ";
	cin >> word;
	ifstream file(filename);

	while (file.peek() >= 0 && !file.eof())
	{
		file >> c;
		buf += c;
	}

	file.close();

	size_t pos = 0;

	if ((pos = buf.find(word, 0)) != string::npos)
	{
		cout << "word = " << word << " on " << pos << " position" << endl;
	}
	else
	{
		cout << "word not found!";
	}
}

int main()
{
	/*cout << "Task-3" << endl;
	file();
	file2();*/

	/*cout << "Task-4" << endl;
	gluing();*/

	/*cout << "Task-5" << endl;
	findWord();*/

	return 0;
}