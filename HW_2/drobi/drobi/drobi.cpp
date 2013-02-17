
//#include "stdafx.h"
#include "iostream"
using namespace std;



int main()
{
	cout << "Enter N = " ;
	int n = 1 ;
	cin >> n ;
	int i = 1 ;
	int j = 1 ;
	int del[100] = {} ;
	int l = 0 ;
	int u = 1 ;
	bool b = true ;

	for (i = n ; i > 0 ; i-- )
	{

		// Обнуляем массив,в который будем складывать простые множители i
		for (int k = 0 ; k <= l ; k++) 
			del[k] = 0 ;
		
		// Обнуляем счетчик по массиву
		l = 0 ;

		//Создаем копию i ,чтобы смочь делить
		u = i ;

		// Ищем простые делители
		for (int d = 2 ; d <= i /2 ; d++)
		{

			if (u % d == 0)
			{
				del[l] = d ;
				while (u % d == 0) 
					u = u / d ;
				l++ ;
			}
		}
		
		// Работаем с числителем
		for (j = i - 1 ; j >= 1 ; j--)
		{
			 b = true ;
			for(int h = 0 ; h < l ; h++)
			{
				if(j % del[h] == 0)
					b = false ;
			}
			if (b) 
				cout << j << "/" << i << "; " ;
		}

			
	}
	char time = 'p' ;
	cout << "\n" ;
	cin >> time ;
	return 0;
}

