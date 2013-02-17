

//#include "stdafx.h"
#include "iostream"
using namespace std;


int fact(int n)
{ 
	if (n  > 1)
		n *= fact(n - 1);
	return n ;
}
int main()
{
	cout << "Enter your number x " << "\n" ;
	int x = 0 ;
	cin >> x ;
	int r = fact(x);
	cout << "factorial is " << r ;
	char time = 'p' ;
	cin >> time ;

	return 0;
}

