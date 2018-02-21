// MySudocu.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "fstream"
#include "fstream"
#include"ctime"
#include "string"
#include "iostream"
using namespace std;

const int n = 9;
char table[n][n];

void dsdjl(char(*tab)[n][n]) //ôóíêöèÿ äëÿ âûâîäà òàáëèöû
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

void transpose() //òðàíñïîíèðîâàíèå ìàòðèöû
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
void permutation_str() //ïîìåíÿòü äâå ñòðîêè â ïðåäåëàõ îäíîé òðîéêè
{
	int swap_str, j, i = rand() % 9; //ðàíäîìèì ñòðîêó, êîòîðóþ áóäåì ìåíÿòü
	if ((i == 0) || (i == 3) || (i == 6)) swap_str = rand() % 2 + 1; //ðàíäîìèì ñòðîêó, ñ êîòîðîé áóäåì ìåíÿòü, â ïðåäåëàõ ýòîé òðîéêè
	if ((i == 1) || (i == 4) || (i == 7)) swap_str = 1;
	if ((i == 2) || (i == 5) || (i == 8)) swap_str = -(rand() % 2 + 1);
	for (j = 0; j < n; j++)
	{
		swap(table[i][j], table[i + swap_str][j]);
	}
}
void permutation_3_str() //ïîìåíÿòü äâå òðîéêè ñòðîê
{
	int swap_str, j, i;
	do // ðàíäîìèì íîìåðà òðîåê, òàê ÷òîáû îíè íå ïîâòîðÿëèñü 
	{
		i = rand() % 3;
		swap_str = rand() % 3;
	} while (i >= swap_str);
	if (swap_str == 1) swap_str = 3; //åñëè 0 è 1 òðîéêà
	if (swap_str == 2) swap_str = 6; //åñëè 0 è 2 òðîéêà
	if (i == 1) i = 3;// åñëè 1 è 2 òðîéêà
	for (j = 0; j < n; j++) //ìåíÿåì
	{
		swap(table[i][j], table[swap_str][j]);
		swap(table[i + 1][j], table[swap_str + 1][j]);
		swap(table[i + 2][j], table[swap_str + 2][j]);
	}
}
void permutation_column() //ïîìåíÿòü ìåñòàìè 2 ñîëáöà â ïðåäàëàõ îäíîé òðîéêè
{
	int swap_column, j, i = rand() % 9; // ðàíäîìèì ñòîëáåö
	if ((i == 0) || (i == 3) || (i == 6)) swap_column = rand() % 2 + 1;	//ðàíäîìèì ñòîëáåö âíóòðè ýòîé òðîéêè
	if ((i == 1) || (i == 4) || (i == 7)) swap_column = 1;
	if ((i == 2) || (i == 5) || (i == 8)) swap_column = -(rand() % 2 + 1);
	for (j = 0; j < n; j++)
	{
		swap(table[j][i], table[j][i + swap_column]);
	}
}
void permutation_3_column() // ïîìåíÿòü ìåñòàìè 2 òðîéêè ñòîëáöîâ
{
	int swap_column, j, i;
	do // ðàíäîìèì íîìåðà òðîåê, òàê ÷òîáû îíè íå ïîâòîðÿëèñü 
	{
		i = rand() % 3;
		swap_column = rand() % 3;
	} while (i > swap_column);
	if (swap_column == 1) swap_column = 3;//åñëè 0 è 1 òðîéêà
	if (swap_column == 2) swap_column = 6;//åñëè 0 è 2 òðîéêà
	if (i == 1) i = 3; //åñëè 1 è 2 òðîéêà
	for (j = 0; j < n; j++) //ìåíÿåì
	{
		swap(table[j][i], table[j][swap_column]);
		swap(table[j][i + 1], table[j][swap_column + 1]);
		swap(table[j][i + 2], table[j][swap_column + 2]);
	}
}
bool base() // ñîçäàåì áàçîâóþ òàáëèöó
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
				b_t >> table[i][j]; //çàïèñûâàåì èç ôàéëà
			}
		}
		return true;
	}
	else
	{
		cout << "Ôàéë íå íàéäåí. Ïåðåóñòàíîâèòå ïðîãðàììó.\n";
		return false;
	}
	b_t.close();
}
void delet(char(*sudocu)[n][n]) //óäàëÿåì ýëåìåíòû èç ñòðîêè, ÷òîáû ïîëó÷èòü ñóäîêó
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
	int random = rand() % 17 + 3; //ïîäáèðàëà òàê, ÷òîáû ïðè âûïàäåíèè âåðõíåé ãðàíèöû òàáëèöà ãåíåðèðîâàëàñü íå áîëåå 2-õ ñåêóíä
	for (int i = 0; i < random; i++)
	{
		int m = rand() % 9 + 2; //òèïà ðàíäîìíûé âûçîâ ôóíêöèé äëÿ ãåíåðàöèè òàáëèöû
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
		cout << "Âû âûèãðàëè \n";
		return true;
	}
	else
	{
		cout << "Íåâåðíîå ðåøåíèå\n";
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
				if (b == 0) { cout << "Âû íè÷åãî íå ââåëè/ íå ñîõðàíèëè ôàéë \n"; return false; }
				if (b == 1) { cout << "Íåëüçÿ ââîäèòü 0\n"; return false; }
				if (b == 2) { cout << "Íåëüçÿ ââîäèòü áóêâû (ñèìâîëû) \n"; return false; }
				if (b == 3) { cout << "Âû ââåëè ìåíüøå 9 öèôð\n"; return false; }
				if (b == 4) { cout << "Âû ââåëè áîëüøå 9 öèôð\n"; return false; }
				if (b == 5) { cout << "Âû ââåëè áîëüøå 9 ñòðîê\n"; return false; }
				if (b == 6) { cout << "Âû ââåëè ìåíüøå 9 ñòðîê\n"; return false; }
			}
		}
	}
	else
	{
		cout << "Îøèáêà. Ôàéë ñ ðåøåíèåì íå íàéäåí. Ââåäèòå åùå ðàç";
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
		if (b == 0) { cout << "Âû íè÷åãî íå ââåëè. \n"; return false; }
		if (b == 2) { cout << "Âû ìîæåòå ââîäèòü òîëüêî 'ok'. \n"; return false; }
	}
}

int main()
{
	setlocale(0, "");
	//srand(time(0));
	if (generation() == false) { system("Pause"); return 0;}
	cout << "Ñãåíåðèðîâàííàÿ òàáëèöà(ïðàâèëüíûé îòâåò)" << endl;
	dsdjl(&table); // âûâîä òàáëèöû

	char sudocu[n][n];
	delet(&sudocu);
	cout << "Ñóäîêó" << endl;
	dsdjl(&sudocu);
	
	char input_sudocu[n][n];//ââîä  è ïðîâåðêà
	string str;
	for (int i = 0; i < 2; i++)
	{
		cout << endl;
		cout << "\n Îñòàëîñü ïîïûòîê " << 2 - i << endl;
		do
		{
			cout << endl;
			ofstream file("Ansver.txt"); file.close();
			cout << "Íàïèøèòå ñâîå ðåøåíèå â îòêðûâøèìñÿ ôàéëå è çàêðîéòå åãî. Êàê çàêîí÷èòå íàïèøèòå 'ok' \n";
			system("Ansver.txt");
			do
			{
				getline(cin, str);
			} while (validachiya_vvoda(&str) == false);
		} while (validaciya(&input_sudocu) == false);
		cout << "\nÂàøà òàáëèöà \n";
		dsdjl(&input_sudocu);
		if (input_proverka(&input_sudocu) == true) break;
		if (i == 1)
		{
			cout << "Âû ïðîèãðàëè\n";
			cout << endl;
			cout << "Ïðàâèëüíûé îòâåò\n";
			dsdjl(&table);
		}
	}
	remove("Ansver.txt");
	system("Pause");
	return 0;
}
