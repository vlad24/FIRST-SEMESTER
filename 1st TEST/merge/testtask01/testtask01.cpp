#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include "sortmaster.h"
using namespace std ;

/*int* mergesort(int x[] , int y[] , int lengthx , int lengthy)
{
	int* z = new int[lengthx+lengthy];
	int r = lengthy ;
	if (lengthx < lengthy)
		r = lengthx;
	for (int u = 0 ; u <= r ; u++);
	return z ;
}*/
int main()
{
	int a[100] = {} ;
	int b[100] = {} ;
	int lengtha = 0 ;
	int lengthb = 0 ;
	int i = -1 ;
	
	printf("Enter the list of the 1st man. End with -1 . \n");
	do
	{
		i++ ;
		cin >> a[i] ;
		lengtha++;
	}
	while (a[i] != -1) ;

	a[i] = 0 ;
	lengtha--;

	i = -1 ;

	printf("Enter the list of the 2nd man.End with -1 . \n");
	do
	{
		i++ ;
		cin >> b[i] ;
		lengthb++ ;
	}
	while (b[i] != -1) ;
	
	b[i] = 0 ;
	lengthb-- ;
	cout << lengtha << endl ;
	cout << lengthb << endl ;

	

	int* c = new int[lengtha+lengthb] ;
	for(int w = 0 ; w < lengtha+lengthb ; w++)
	{
		c[w] = -2 ;
	}
	for (int w = 0 ; w < lengtha ; w++)
	{
		c[w] = a[w]; 
	}
	for (int w = lengtha ; w <= lengtha + lengthb - 1 ; w++ )
	{
		c[w] = b[w - lengthb];
	}

	quicksort(c,0,lengtha + lengthb - 1) ;

	
	for(int w = 0 ; w < lengtha + lengthb ; w++)
		printf("%d",c[w]) ;
	delete c ;

	int o = 24 ;
	cin >> o ;
	// Сложность алгоритма nlog(n)
}