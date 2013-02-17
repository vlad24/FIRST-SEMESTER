

//#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int i = 1;
	int j = 1;
	int l = 1;
	int k[28];
	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9 ; j++)
		{
			for (l = 0; l <= 9 ; l++)
			{
				k[l + j + i]++ ;
			}
		}
	}
	int s = 0;
	for (int y=0; y <= 27; y++) 
	{
		s += k[y] * k[y] ;
	}

	cout << "Amount of happy tickets is " << s ;
	
	int time = 0;
	cin >> time ;

	return 0;
}

