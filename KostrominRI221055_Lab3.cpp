#include <iostream>
#include<string>
#include<fstream>
#include <filesystem>
#include<Windows.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	
	string path = "D:\\newfolder\\MyFile.txt";
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Файл не открыт!" << endl;
	}
	else
	{
		string msg;
		int value;
		cout << "Файл открыт!" << endl;
		cout << "Введите 1 для записи сообщения в файл:" << endl;
		cout << "Введите 2 для считывания всех сообщений с файла" << endl;
		cout << "Введите 3 для записи сообщения в новый файл:" << endl;
		cin >> value;
		if (value > 3)
		{
			cout << "Ошибка" << endl;
		}
		if (value < 1)
		{
			cout << "Ошибка" << endl;
		}
		if (value == 1)
		{
			cout << "Введите сообщение" << endl;
			SetConsoleCP(1251);
			cin >> msg;
			fs << msg << "\n";
			SetConsoleCP(866);
		}
		if (value == 2)
		{
			cout << "Сообщения с файла" << endl;
			while (!fs.eof())
			{
				msg = "";
				fs >> msg;
				cout << msg << endl;
			}
		}
		if (value == 3)
		{
			string fsName;
			string msg1;

			cout << "Введите имя файла: ";
			cin >> fsName;

			ofstream fs1(fsName.c_str());

			if (!fs1.is_open())
			{
				cout << "Ошибка" << endl;
			}
			if (fs1.is_open())
			{
				cout << "Введите данные для записи в файл:\n";
				cin >> msg1;
				fs1 << msg1 << "\n";
				getline(cin, msg1);
				cout << "Данные успешно записаны";
			}
			fs1.close();

		}
	}
	fs.close();
}