#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX_X = 100;
const int MAX_Y = 100;


void delay(float number_of_seconds)
{
	int milli_seconds = (int)1000 * number_of_seconds;
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds)
		;
}


char interpret(int n, int k)
{
	if (k == 1)
	{
		if (n == 1)
			return 254;
		else if (n == 0)
			return 255;
		else
			return '?';
	}
	if (k == 2)
	{
		if (n == 1)
			return 88;
		else if (n == 0)
			return 79;
		else
			return '?';
	}
	if (k == 3)
	{
		if (n == 1)
			return 64;
		else if (n == 0)
			return 255;
		else
			return '?';
	}
	if (k == 4)
	{
		if (n == 1)
			return 254;
		else if (n == 0)
			return 207;
		else
			return '?';
	}
}


void rysuj(int len_x, int len_y, int T[MAX_X][MAX_Y], int k)
{
	int i = 0;
	int j = 0;
	printf("%c", 201);
	while (j < len_x)
	{
		printf("%c%c%c", 205, 205, 205);
		j++;
	}
	printf("%c\n", 187);
	while (i < len_y)
	{
		j = 0;
		printf("%c", 186);
		while (j < len_x)
		{
			printf(" %c ", interpret(T[j][i], k));
			j++;
		}
		i++;
		printf("%c\n", 186);
	}
	j = 0;
	printf("%c", 200);
	while (j < len_x)
	{
		printf("%c%c%c", 205, 205, 205);
		j++;
	}
	printf("%c\n", 188);
}


int one_step(int len_x, int len_y, int T[MAX_X][MAX_Y], int T2[MAX_X][MAX_Y])
{
	int result = 0;
	int i = 0, j = 0;
	while (i < len_y)
	{
		j = 0;
		while (j < len_x)
		{
			T2[j][i] = T[j][i];
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	int sum_sasiad = 0;
	while (i < len_y)
	{
		j = 0;
		while (j < len_x)
		{
			sum_sasiad = 0;
			if (T2[j - 1][i - 1] == 1 && j >= 1 && i >= 1)
				sum_sasiad++;
			if (T2[j - 1][i] == 1 && j >= 1)
				sum_sasiad++;
			if (T2[j - 1][i + 1] == 1 && j >= 1 && i < len_y)
				sum_sasiad++;
			if (T2[j][i - 1] == 1 && i >= 1)
				sum_sasiad++;
			if (T2[j][i + 1] == 1 && i < len_y)
				sum_sasiad++;
			if (T2[j + 1][i - 1] == 1 && j < len_x && i >= 1)
				sum_sasiad++;
			if (T2[j + 1][i] == 1 && j < len_x)
				sum_sasiad++;
			if (T2[j + 1][i + 1] == 1 && j < len_x && i < len_y)
				sum_sasiad++;
			if (T2[j][i] == 0)
			{
				if (sum_sasiad == 3)
				{
					result++;
					T[j][i] = 1;
				}
			}
			else if (T2[j][i] == 1)
			{
				if (sum_sasiad < 2 || sum_sasiad > 3)
				{
					result++;
					T[j][i] = 0;
				}
			}
			else
				T[j][i] = 0;
			j++;
		}
		i++;
	}
	return result;
}


void menu1()
{
	printf("*******GRA W ZYCIE*******");
	printf("\n");
	printf(" MENU:\n");
	printf(" Co checesz?\n");
	printf(" 1. Wpisz recznie\n");
	printf(" 2. Wczytaj z pliku\n");
	printf(" 3. Wylosuj uklad\n");
	printf(" 4. Zmien motyw (1-4)\n");
	printf(" 0. Wyjdz\n");
}


void interfejs()
{
	printf(" INTERFEJS\n");
	printf(" 1. Jeden krok\n");
	printf(" 2. 5 krokow\n");
	printf(" 3. 10 krokow\n");
	printf(" 4. Wykonuj co n sec (float)\n");
	printf(" 5. Edytuj/zmien wartosc pola (x,y)\n");
	printf(" 6. Zapisz stan w pliku txt\n");
	printf(" 0. menu\n");
}


int main()
{
	int wh = 1, wh2 = 1;
	int motyw = 1;
	int error;
	float timer;
	int in = 0, inp = 0;
	int x = 0, y = 0;
	int px = 0, py = 0;
	int itery, iterx, iter;
	int b = 0;
	int tablica[MAX_X][MAX_Y];
	int tabel2[MAX_X][MAX_Y];
	int bad = 0;
	FILE *F;
	while (wh == 1)
	{
		error = 0;
		system("cls");
		menu1();
		scanf("%d", &in);
		if (in == 1 || in == 2 || in == 3)
		{
			printf("\n podaj wymiary (x,y)\n");
			scanf("%d", &x);
			scanf("%d", &y);
		}
		switch (in)
		{
		case 1:
			itery = 0;
			while (itery < y)
			{
				iterx = 0;
				while (iterx < x)
				{
					system("cls");
					rysuj(x, y, tablica, motyw);
					printf("\n");
					scanf("%d", &inp);
					if (inp == 0)
						tablica[iterx][itery] = 0;
					else
						tablica[iterx][itery] = 1;
					iterx++;
				}
				itery++;
			}
			break;
		case 2:
			F = fopen("zycie.txt", "r");
			itery = 0;
			while (itery < y)
			{
				iterx = 0;
				while (iterx < x)
				{
					system("cls");
					rysuj(x, y, tablica, motyw);
					printf("\n");
					fscanf(F, "%d", &inp);
					if (inp == 0)
						tablica[iterx][itery] = 0;
					else
						tablica[iterx][itery] = 1;
					iterx++;
				}
				itery++;
			}
			fclose(F);
			break;
		case 3:
			itery = 0;
			while (itery < y)
			{
				iterx = 0;
				while (iterx < x)
				{
					system("cls");
					rysuj(x, y, tablica, motyw);
					printf("\n");
					inp = rand() % 2;
					if (inp == 0)
						tablica[iterx][itery] = 0;
					else
						tablica[iterx][itery] = 1;
					iterx++;
				}
				itery++;
			}
			break;
		case 4:
			b = 0;
			while (b == 0)
			{
				printf("Dostepne motywy:\n");
				printf("1. %c\t%c\n", 254, 255);
				printf("2. %c\t%c\n", 88, 79);
				printf("3. %c\t%c\n", 64, 255);
				printf("4. %c\t%c\n", 254, 207);
				printf("podaj numer motywu\n");
				scanf("%d", &motyw);
				if (motyw == 1 || motyw == 2 || motyw == 3 || motyw == 4)
				{
					b = 1;
				}
				else
					printf("INVALID INPUT\n");
			}
			error = 1;
			break;

		case 0:
			wh = 0;
			error = 1;
			break;
		default:
			system("cls");
			printf("INVALID INPUT\n");
			system("pause");
			error = 1;
			break;
		}
		if (error != 1)
		{
			int stop = 0;
			wh2 = 1;
			FILE *g;
			while (wh2 == 1)
			{
				system("cls");
				rysuj(x, y, tablica, motyw);
				interfejs();
				scanf("%d", &in);
				switch (in)
				{
				case 1:
					one_step(x, y, tablica, tabel2);
					break;
				case 2:
					iter = 5;
					while (iter > 0)
					{
						one_step(x, y, tablica, tabel2);
						iter--;
					}
					break;
				case 3:
					iter = 10;
					while (iter > 0)
					{
						one_step(x, y, tablica, tabel2);
						iter--;
					}
					break;
				case 4:
					printf("\n");
					scanf("%f", &timer);
					stop = 1;
					iter = 0;
					while (stop > 0 && iter < 100)
					{
						stop = one_step(x, y, tablica, tabel2);
						delay(timer);
						iter++;
						system("cls");
						rysuj(x, y, tablica, motyw);
					}
					break;
				case 5:
					bad = 0;
					scanf("%d", &px);
					scanf("%d", &py);
					if (px < 0 || px > x)
					{
						bad = 1;
						printf("WRONG X\n");
					}
					if (py < 0 || py > y)
					{
						bad = 1;
						printf("WRONG Y\n");
					}
					if (bad == 0)
					{
						if (tablica[px][py] == 0)
							tablica[px][py] = 1;
						else
							tablica[px][py] = 0;
					}
					else
						system("pause");
					break;
				case 6:
					g = fopen("output.txt", "w");
					itery = 0;
					while (itery < y)
					{
						iterx = 0;
						while (iterx < x)
						{
							fprintf(g, "%d ", tablica[iterx][itery]);
							iterx++;
						}
						fprintf(g, "\n");
						itery++;
					}
					fclose(g);
					break;
				case 0:
					wh2 = 0;
					break;
				default:
					printf("INVALID INPUT\n");
					system("pause");
					break;
				}
			}
		}
	}
	return 0;
}
