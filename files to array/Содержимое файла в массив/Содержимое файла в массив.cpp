#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	HANDLE hFile = CreateFile(L"КостроминВадимИгоревич.rar", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		cout << "Ошибка открытия файла" << endl;
		return 1;
	}
	else
	{
		cout << "Файл открыт" << endl;
	}
	DWORD fileSize = GetFileSize(hFile, NULL);
	cout << "Кол-во байт в файле:\ " << fileSize << endl;
	vector<char> buffer(fileSize);
	{
		cout << "Выделена память под массив" << endl;
	}
	DWORD bytesRead;
	ReadFile(hFile, buffer.data(), fileSize, &bytesRead, NULL);
	if (!ReadFile(hFile, buffer.data(), fileSize, &bytesRead, NULL))
	{
		cout << "Ошибка чтения файла" << endl;
		return 1;
	}
	else
	{
		cout << "Содержимое файла перенесено в массив" << endl;
	}
	CloseHandle(hFile);
	cout << "Файл закрыт" << endl;
}