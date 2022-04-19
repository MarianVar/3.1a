
#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#include <Windows.h> 

using namespace std;


struct Student
{
	string prizv;
	string cours;
	string spec;
	int physic;
	int math;
	int informatic;
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
double Excellent(Student* s, const int N);
void Count(Student* s, const int N);


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть N: "; cin >> N;

	Student* s = new Student[N];

	int menuItem;

	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - Обчислити процент студентів,  " << endl;
		cout << " у яких середній бал більший за 4,5" << endl;
		cout << " [4] - Вивести прізвища студентів, які вчаться на “відмінно”" << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;


		switch (menuItem)
		{
		case 1:
			Create(s, N);
			break;
		case 2:
			Print(s, N);
			break;
		case 3:
			cout << "Процент студентів що має середній бал >4.5 ="
				<< Excellent(s, N) << " % " << endl;
			break;
		case 4:
			Count(s, N);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}

void Create(Student* s, const int N)
{

	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " Прізвище: "; cin >> s[i].prizv;
		cout << " Курс: "; cin >> s[i].cours;
		cout << " Спеціальність: "; cin >> s[i].spec;
		cout << " Оцінка з фізики: "; cin >> s[i].physic;
		cout << " Оцінка з математики: "; cin >> s[i].math;
		cout << " Оцінка з інформатики: "; cin >> s[i].informatic;
		cout << endl;
	}
}
void Print(Student* s, const int N)
{

	cout << "========================================================================="
		<< endl;
	cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Інформатика | "
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << s[i].prizv
			<< "| " << setw(4) << right << s[i].cours << " "
			<< "| " << setw(11) << left << s[i].spec << " "
			<< "| " << setw(6) << right << s[i].physic << " "
			<< "| " << setw(6) << left << s[i].math << " "
			<< "| " << setw(7) << right << s[i].informatic << endl;
	}
	cout << "========================================================================="
		<< endl;
	cout << endl;
}

double Excellent(Student* s, const int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (((double)(s[i].informatic + s[i].math + s[i].physic) / 3) >= (double)4.5)
			count++;
	}
	if (count != (int)0)
		return (double)(N * count) / 100;
	else
		return 0;
}

void Count(Student* s, const int N)
{
	for (int i = 0; i < N; i++)
	{
		if ((s[i].informatic == 5) && (s[i].math == 5) && (s[i].physic == 5))
		{
			cout << "# " << s[i].prizv << endl;
		}
	}
}