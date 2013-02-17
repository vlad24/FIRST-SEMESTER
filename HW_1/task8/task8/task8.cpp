//Итеративно
//#include "stdafx.h"
#include "iostream"
using namespace std;


int main()
{
	int x = 1 ;
	cout << "Enter your number x : " ;
	cin >> x;
	int fac = 1 ;
	for (int i = 2 ; i <= x ; i++)
	{
		fac *= i ;
	}

	cout << "factorial x =" << fac ;
	char time = 'p' ;
	cin >> time ;
	return 0;
}

