

#include "stdafx.h"
#include "iostream "
using namespace std ;


int main()
{
	cout << "Enter the number of Fn " ;
	int n = 0 ;
	cin >> n ;
	int a = 0 ; 
	int b = 1 ;
	int fn = 1 ;

	for(int i = 1 ; i<= n-3 ; i++)
	{
		a = b ;
		b = fn ;
		fn = a + b ;
	}
	cout <<"The number is "<< fn << endl ; 
	int r = 24 ;
	cin >> r ;
	return 0;
}