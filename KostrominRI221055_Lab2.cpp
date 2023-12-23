#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");

	// Задание 1
	const int size = 10;
	int arr[size]{ 1,2,3,4,5,6,7,8,9,10 };

	cout << "Массив 1:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	// Задание 2
	/*
	cout << " " << endl;
	const int size1 = 10;
	int arr1[size1];

	for (int i = 0; i < size1; i++)
	{
		arr1[i] = rand() % 21 - 10;
	}

	cout << "Массив" << endl;

	for (int i = 0; i < size1; i++)
	{
		cout << arr1[i] << " ";
	}
	*/
	// Задание 3 
	cout << " " << endl;
	const int size2 = 5;
	int arr2[size2], vvod;

	for (int i = 0; i < size2; i++)
	{
		cout << "Введите " << i + 1 << " элемент массива" << endl;
		cin >> vvod;
		arr2[i] = vvod;
	}

	cout << "Массив 2: " << endl;
	for (int i = 0; i < size2; i++)
	{
		cout << arr2[i] << " ";
	}

	// Задание 4
	cout << " " << endl;
	const int size3 = 10;
	int arr3[size3];

	srand(time(0));
	for (int i = 0; i < size3; i++)
	{
		arr3[i] = rand() % 21 - 10;
	}

	cout << "Исходный массив 3 со случайными элементами: ";
	for (int i = 0; i < size3; i++) {
		cout << arr3[i] << " ";
	}

	for (int i = 0; i < size3; i++)
	{
		if (arr3[i] % 2 == 0)
			arr3[i] *= 3;
		else
			arr3[i] *= 5;
	}
	cout << " " << endl;
	cout << "Полученный массив 3 со случайными элементами: ";
	for (int i = 0; i < size3; i++)
	{
		cout << arr3[i] << " ";
	}

	// Двумерные массивы
	// Задание 1
	cout << " " << endl;
	const int size4 = 5;
	int arr4[size4][size4];

	srand(time(0));

	cout << "Двумерный массив: " << endl;
	for (int i = 0; i < size4; i++)
	{
		for (int j = 0; j < size4; j++)
		{
			arr4[i][j] = rand() % 21 - 10;
		}
	}

	for (int i = 0; i < size4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << arr4[i][j] << "\t";
		}
		cout << endl;
	}

	// Задание 2
	cout << " " << endl;
	const int size5 = 5;
	int arr5[size5][size5];

	srand(time(0));

	cout << "Двумерный массив" << endl;
	for (int i = 0; i < size5; i++)
	{
		for (int j = 0; j < size5; j++)
		{
			arr5[i][j] = rand() % 21 - 10;
		}
	}

	for (int i = 0; i < size5; i++)
	{
		for (int j = 0; j < size5; j++)
		{
			cout << arr5[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "Сумма элементов в каждой строке:" << endl;
	for (int i = 0; i < size5; i++)
	{
		int sum = 0;
		for (int j = 0; j < size5; j++)
		{
			sum += arr5[i][j];
		}
		cout << "Сумма элементов строки " << i + 1 << ": " << sum << endl;
	}

	// Задание 3
	cout << " " << endl;
	const int size6 = 5;
	int arr6[size6][size6];

	srand(time(0));

	for (int i = 0; i < size6; i++)
	{
		for (int j = 0; j < size6; j++)
		{
			arr6[i][j] = rand() % 21 - 10;
		}
	}

	cout << "Исходный двумерный массив" << endl;
	for (int i = 0; i < size6; i++)
	{
		for (int j = 0; j < size6; j++)
		{
			cout << arr6[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < size6; i++)
	{
		for (int j = 0; j < size6; j++)
		{
			if (arr6[i][j] < 0)
				arr6[i][j] = 0;
		}
	}
	cout << endl;

	cout << "Полученный двумерный массив" << endl;
	for (int i = 0; i < size6; i++)
	{
		for (int j = 0; j < size6; j++)
		{
			cout << arr6[i][j] << "\t";
		}
		cout << endl;
	}
}