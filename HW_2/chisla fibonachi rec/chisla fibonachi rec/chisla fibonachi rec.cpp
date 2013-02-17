// chisla fibonachi rec.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include "iostream"
using namespace std;

int fib(int n)
{
	if (n == 1) 
		return 0 ;
	if (n == 2)
		return 1 ;
	if (n > 2) 
		return fib(n - 1) + fib(n - 2) ;

}
int main()
{
	int n = 1 ;
	cout << "Enter the number of Fn " ;
	cin >> n ;
	int y = fib(n) ;
	cout << "The number n is " << y << endl;
	int u = 24 ;
	cin >> u ;

	return 0;
}

