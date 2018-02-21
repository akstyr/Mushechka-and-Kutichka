// MySudocu.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "fstream"
#include"ctime"
#include "string"
#include "iostream"
using namespace std;

const int n = 9;
char table[n][n];

void dsdjl(char(*tab)[n][n]) //функция для вывода таблицы
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << (*tab)[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void transpose() //транспонирование матрицы
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			swap(table[i][j], table[j][i]);
		}
	}
}
void permutation_str() //поменять две строки в пределах одной тройки
{
	int swap_str, j, i = rand() % 9; //рандомим строку, которую будем менять
	if ((i == 0) || (i == 3) || (i == 6)) swap_str = rand() % 2 + 1; //рандомим строку, с которой будем менять, в пределах этой тройки
	if ((i == 1) || (i == 4) || (i == 7)) swap_str = 1;
	if ((i == 2) || (i == 5) || (i == 8)) swap_str = -(rand() % 2 + 1);
	for (j = 0; j < n; j++)
	{
		swap(table[i][j], table[i + swap_str][j]);
	}
}
void permutation_3_str() //поменять две тройки строк
{
	int swap_str, j, i;
	do // рандомим номера троек, так чтобы они не повторялись 
	{
		i = rand() % 3;
		swap_str = rand() % 3;
	} while (i >= swap_str);
	if (swap_str == 1) swap_str = 3; //если 0 и 1 тройка
	if (swap_str == 2) swap_str = 6; //если 0 и 2 тройка
	if (i == 1) i = 3;// если 1 и 2 тройка
	for (j = 0; j < n; j++) //меняем
	{
		swap(table[i][j], table[swap_str][j]);
		swap(table[i + 1][j], table[swap_str + 1][j]);
		swap(table[i + 2][j], table[swap_str + 2][j]);
	}
}
void permutation_column() //поменять местами 2 солбца в предалах одной тройки
{
	int swap_column, j, i = rand() % 9; // рандомим столбец
	if ((i == 0) || (i == 3) || (i == 6)) swap_column = rand() % 2 + 1;	//рандомим столбец внутри этой тройки
	if ((i == 1) || (i == 4) || (i == 7)) swap_column = 1;
	if ((i == 2) || (i == 5) || (i == 8)) swap_column = -(rand() % 2 + 1);
	for (j = 0; j < n; j++)
	{
		swap(table[j][i], table[j][i + swap_column]);
	}
}
void permutation_3_column() // поменять местами 2 тройки столбцов
{
	int swap_column, j, i;
	do // рандомим номера троек, так чтобы они не повторялись 
	{
		i = rand() % 3;
		swap_column = rand() % 3;
	} while (i > swap_column);
	if (swap_column == 1) swap_column = 3;//если 0 и 1 тройка
	if (swap_column == 2) swap_column = 6;//если 0 и 2 тройка
	if (i == 1) i = 3; //если 1 и 2 тройка
	for (j = 0; j < n; j++) //меняем
	{
		swap(table[j][i], table[j][swap_column]);
		swap(table[j][i + 1], table[j][swap_column + 1]);
		swap(table[j][i + 2], table[j][swap_column + 2]);
	}
}
bool base() // создаем базовую таблицу
{
	int i, j;
	ifstream b_t;
	
	b_t.open("base table.txt");
	if (b_t)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				b_t >> table[i][j]; //записываем из файла
			}
		}
		return true;
	}
	else
	{
		cout << "Файл не найден. Переустановите программу.\n";
		return false;
	}
	b_t.close();
}
void delet(char(*sudocu)[n][n]) //удаляем элементы из строки, чтобы получить судоку
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			(*sudocu)[i][j] = table[i][j];
		}
	}
	int m = 0, number = 81;
	do
	{
		m++;
		(*sudocu)[rand() % n][rand() % n] = 0;
		if (m > 50)
		{
			number = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if ((*sudocu)[i][j] != 0) number++;
				}
			}
		}
	} while (number > 30);
}
bool generation()
{
	if (base() == false) return false;
	int random = rand() % 17 + 3; //подбирала так, чтобы при выпадении верхней границы таблица генерировалась не более 2-х секунд
	for (int i = 0; i < random; i++)
	{
		int m = rand() % 9 + 2; //типа рандомный вызов функций для генерации таблицы
		if (m % 11 == 0) transpose();
		if (m % 3 == 0) permutation_str();
		if (m % 2 == 0) permutation_column();
		if (m % 7 == 0) permutation_3_str();
		if (m % 5 == 0) permutation_3_column();
	}
	return true;
}

bool input_proverka(char(*input_sudocu)[n][n])
{
	int i, j;
	int kol1 = 0, kol2 = 0;
	for (i = 0; i < n; i++)
	{
		char mas[2][n] = { '1','2','3','4','5','6','7','8','9','1','2','3','4','5','6','7','8','9' };
		for (j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if ((*input_sudocu)[i][j] == mas[0][k])
				{
					mas[0][k] = 0;
					kol1++;
				}
				if ((*input_sudocu)[j][i] == mas[1][k])
				{
					mas[1][k] = 0;
					kol2++;
				}
			}
		}
	}
	if ((kol1 == n * n) && (kol2 == n * n))
	{
		cout << "Вы выиграли \n";
		return true;
	}
	else
	{
		cout << "Неверное решение\n";
		return false;
	}
}
bool validaciya(char(*input)[n][n])
{
	string str;
	int i = 0, j, number, kolichestvo = 0;
	ifstream file;
	file.open("Ansver.txt");
	if (file)
	{
		while (true)
		{
			i++;
			getline(file, str);
			number = 0;
			try
			{
				if ((!file.eof()) && (str.length() == 0)) {i--; continue;}
				if ((i == 1) && (file.eof()) && (str.length() == 0)) throw 0;
				if (!(str.length() == 0))
				{
					for (j = 0; j < str.length(); j++)
					{
						if ((str)[j] == ' ') continue;
						if (!((str[j] >= '0') && (str[j] <= '9'))) throw 2;
						if (str[j] == '0') throw 1;
						number++;
						(*input)[i - 1][number - 1] = str[j];
					}
					if (number < n) throw 3;
					if (number > n) throw 4;
				}
				if (file.eof())
				{ 
					if (str.length() == 0) i--;
					if (i == n) return true;
					if (i < n) throw 6;
					if (i > n) throw 5;
				}
			}
			catch (int b)
			{
				if (b == 0) { cout << "Вы ничего не ввели/ не сохранили файл \n"; return false; }
				if (b == 1) { cout << "Нельзя вводить 0\n"; return false; }
				if (b == 2) { cout << "Нельзя вводить буквы (символы) \n"; return false; }
				if (b == 3) { cout << "Вы ввели меньше 9 цифр\n"; return false; }
				if (b == 4) { cout << "Вы ввели больше 9 цифр\n"; return false; }
				if (b == 5) { cout << "Вы ввели больше 9 строк\n"; return false; }
				if (b == 6) { cout << "Вы ввели меньше 9 строк\n"; return false; }
			}
		}
	}
	else
	{
		cout << "Ошибка. Файл с решением не найден. Введите еще раз";
		return false;
	}
	file.close();
}
bool validachiya_vvoda(string *str)
{
	try
	{
		if ((*str).length() == 0) throw 0;
		if ((*str).length() == 1) throw 2;
		for (int i = 0; i < (*str).length(); i++)
		{
			if ((*str)[i] == ' ') continue;
			if (i != (*str).length() - 1)
				if (!(((*str)[i] == 'o') && ((*str)[i + 1] == 'k'))) throw 2;
		}
		return true;
	}
	catch (int b)
	{
		if (b == 0) { cout << "Вы ничего не ввели. \n"; return false; }
		if (b == 2) { cout << "Вы можете вводить только 'ok'. \n"; return false; }
	}
}

int main()
{
	setlocale(0, "");
	//srand(time(0));
	if (generation() == false) { system("Pause"); return 0;}
	cout << "Сгенерированная таблица(правильный ответ)" << endl;
	dsdjl(&table); // вывод таблицы

	char sudocu[n][n];
	delet(&sudocu);
	cout << "Судоку" << endl;
	dsdjl(&sudocu);
	
	char input_sudocu[n][n];//ввод  и проверка
	string str;
	for (int i = 0; i < 2; i++)
	{
		cout << endl;
		cout << "\n Осталось попыток " << 2 - i << endl;
		do
		{
			cout << endl;
			ofstream file("Ansver.txt"); file.close();
			cout << "Напишите свое решение в открывшимся файле и закройте его. Как закончите напишите 'ok' \n";
			system("Ansver.txt");
			do
			{
				getline(cin, str);
			} while (validachiya_vvoda(&str) == false);
		} while (validaciya(&input_sudocu) == false);
		cout << "\nВаша таблица \n";
		dsdjl(&input_sudocu);
		if (input_proverka(&input_sudocu) == true) break;
		if (i == 1)
		{
			cout << "Вы проиграли\n";
			cout << endl;
			cout << "Правильный ответ\n";
			dsdjl(&table);
		}
	}
	remove("Ansver.txt");
	system("Pause");
	return 0;
}