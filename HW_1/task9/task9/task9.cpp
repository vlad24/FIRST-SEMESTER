
//#include "stdafx.h"
#include "iostream"
#include "stdio.h"
using namespace std;


int main()
{
	int a = 1 ;
	printf("Enter the number A = ");
	scanf("%d", &a);
	int n = 1 ;
	printf("Enter the number n = ");
	scanf("%d", &n);
	int b = 1;
	do
	{
		b *= a ;
		n--;
	}
	while (n > 0) ;

	printf("A^n = %d" , b) ;

	int time = 0;
	scanf("%d", time);
	return 0;
}

