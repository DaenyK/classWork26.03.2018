#include<iostream>
#include<locale.h>
#include<time.h>
#include<stdio.h>
#include <stdlib.h>
#include<windows.h>

#define max30 30

struct age {
	int year;
	int month;
	int day;
};

void generateAge(age *t)
{
	t->day = 1 + rand() % 30;
	t->month = 1 + rand() % 11;
	t->year = 1950 + rand() % 60;
}

void generateName(char *name, int type = 0)
{
	if (type == 0)
		strcpy(name, "person #");
	else
		strcpy(name, "kurs #");

	int a = 1 + rand() % 30;

	char t[3];
	itoa(a, t, 10);

	strcat(name, t);
}



struct group
{
	char *name;
	age * Age;
	int * ses;
};

struct  student
{
	int id;
	char * name;
	age * Age;
	int * ses;
	char *kurs;
	double srBal;
};

void sortSES(int* a, int r)
{
	int temp;
	for (int i = 0; i < r; i++)
	{
		for (int j = r - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;

			}
			/*if (*(a+j) < *(a - j))
			{
			temp = *(a-j);
			*(a-j) = *(a + j);
			*(a + j) = temp;
			}*/
		}
	}
}

void sortName(student* a, int r)
{
	student temp;
	for (int i = 0; i < r; i++)
	{
		for (int j = r - 1; j > i; j--)
		{
			if ((a + j - 1)->id > (a + j)->id)
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;

			}
			/*if (*(a+j) < *(a - j))
			{
			temp = *(a-j);
			*(a-j) = *(a + j);
			*(a + j) = temp;
			}*/
		}
	}
}

struct blacknote {
	char *name;
	char*phone;
	age age;
};

void main()
{

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int n, exit;
	int bckr, t;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	do
	{
		printf("please enter exemple: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			/*1. ќписать структуру с именем GROUP, содержащую пол€ :
			a.Name Ц фамили€ и инициалы
			b.DAT Ц дата рождени€(год, мес€ц, число)
			c.SES Ц успеваемость(массив из трех элементов).
			Ќаписать программу, выполн€ющую:
			Х ввод с клавиатуры данных в массив GR5, состо€щий из 10 структур типа GROUP;
			вывод на экран записей, упор€доченных по возрастанию пол€ SES;
			Х вывод списка студентов, возраст которых на 01.12.2010 года не превышает 20 лет;
			Х если таких студентов нет Ц выдать сообщение
			*/
			int a = 1 + rand() % 25;
			printf("кол-во студентов: %d\n", a);

			group *students = NULL;
			students = (group*)malloc(a * sizeof(group));

			if (students == NULL)
			{
				printf("пам€ть не выделена\n");
				system("exit");
				//exit(EXIT_FAILURE);
			}
			else
			{
				for (int i = 0;i < a;i++)
				{
					(students + i)->name = (char*)malloc(12 * sizeof(char));
					generateName((students + i)->name);

					(students + i)->Age = (age*)malloc(1 * sizeof(age));
					generateAge((students + i)->Age);

					int k = (1 + rand() % 10);
					(students + i)->ses = (int*)calloc(k, sizeof(int));

					if ((2018 - (students + i)->Age->year) <= 20)
					{
						printf("# %d \t %s \t %d.%d.%d\n", i + 1, (students + i)->name,
							(students + i)->Age->day, (students + i)->Age->month, (students + i)->Age->year);
						int sum = 0;
						for (int j = 0; j < k; j++)
						{
							(students + i)->ses[j] = 2 + rand() % 4;
							//printf("--> %d\n", (students + i)->ses[j]);
							sum += (students + i)->ses[j];
						}
						printf("после сортировки:\n");
						sortSES((students + i)->ses, k);

						for (int j = 0; j < k; j++)
						{
							printf("--> %d\n", (students + i)->ses[j]);
						}

						if (k != 0)
						{
							printf("----------------------------------------\n");
							printf("средний балл студента составл€ет: %d\n", sum / k);
						}
					}
					else printf("студент %d старше 20 лет\n", i + 1);
				}
			}


		}break;

		case 2:
		{
			int count = 5 + rand() % 30;
			printf("кол-во студентов: %d\n", count);
			int tSum = 0;
			student*students = NULL;
			students = (student*)malloc(count * sizeof(student));
			if (students != NULL)
			{
				for (int i = 0; i < count; i++)
				{
					(students + i)->id = 5 + rand() % 1000;
					(students + i)->name = (char*)malloc(12 * sizeof(char));   //им€
					generateName((students + i)->name);
					//printf("# %d \t %s \n", i + 1, (students + i)->name );

					(students + i)->Age = (age*)malloc(1 * sizeof(age)); //дата рождени€
					generateAge((students + i)->Age);

					(students + i)->kurs = (char*)malloc(6 * sizeof(char));
					generateName((students + i)->kurs, 1);

					(students + i)->ses = (int*)malloc(3 * sizeof(int));

					int sum = 0;
					for (int j = 0; j < 5; j++)
					{
						(students + i)->ses[j] = 1 + rand() % 5;
						sum += (students + i)->ses[j];
					}
					(students + i)->srBal = sum / 5;
					tSum = (students + i)->srBal;
				}

				sortName(students, count);
				tSum = tSum / count;
				for (int i = 0; i < count; i++)
				{
					if ((students)->srBal > tSum)
					{
						SetConsoleTextAttribute(hConsole, (WORD)((21 << 4) | 75));

						printf("#%d \t %s \t %d \t (%s) - \t\t %lf\n",
							students->id, students->name, 2018 - (students->Age->year), students->kurs, students->srBal
						);
					}
					students++;
				}
			}
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));

		}break;

		case 3:
		{
			blacknote *human = (blacknote*)malloc(sizeof(blacknote));
			
			while (exit == 1)
			{
				printf("введите им€: ");
				human->name = (char*)malloc(50 * sizeof(char));
				fgets(human->name, 50, stdin);

				printf("введите телефон: ");
				human->phone = (char*)malloc(50 * sizeof(char));
				fgets(human->phone, 50, stdin);

				printf("введите дату рождени€: ");
				human->age = (age*)malloc(sizeof(age));
				scanf("%2d.%2d.%4d", human->age->day, human->age->month, human->age->year);
				
				printf("ѕродолжить? 1-Yes 2-No:");
				scanf("%d", &exit);
				printf("\n");
			};
		}break;


		}
		printf("ѕродолжить? 1-Yes 2-No:");
		scanf("%d", &exit);
		printf("\n");
	} while (exit == 1);
}