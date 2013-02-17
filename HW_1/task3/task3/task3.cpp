//#include <stdafx.h>
#include <iostream>
using namespace std;

void reflect(int x[], int l, int r)
{
	int j = 0;
	int t = 0;
	for (j = 0; j <= (((l + r) / 2) - l); j++)
	{
		t = x[l + j];
		x[l + j] = x[r - j];
		x[r - j] = t;
	}
}

void print(int *x, int k )
{
	int j = 0;
	for (j = 0; j < k ; j++)
	{
		cout << *(x + j) << " ";
 	}
}


int main()
{ 
	int m = 50;
	cout << "Enter number m " << endl;
	cin >> m;
	int n = 50;
	cout << "Enter number n " << endl;
	cin >> n;
	int a[100];
	int i = 0;
	int t = 0;
	// Инициализация массива
	for (i = 0; i < m + n; i++)
	{
		a[i] = rand() % 25 + 1;
	}
	a[m] = 0;
	//для удобства отслеживания изменений m-ый элемент задан нулём
	for (i = 0; i < m + n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";

	// Переворачивание первого куска
	reflect(a, 0, m-1);
	// Вывод на экран
	print(a, m + n );
	cout << endl;
	// Переворачивание второго куска
	reflect(a, m, (m + n - 1));
	// Вывод на экран
	print(a, m + n);
	cout << endl;
	//Переворачивание целого массива
	reflect(a, 0, m+n-1);
	// Вывод на экран
	print(a, m + n);
	cout << endl;
	
	int time;
	cin >> time;

	return 0;
}

