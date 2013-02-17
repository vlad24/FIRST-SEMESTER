#include "stdafx.h"
#include "iostream"
using namespace std ;

int setelement(char x[], int  left, int  right )
{
	int i = left ;
	int j = right ;
	int m = ( i + j ) / 2 ;
	while (i < j)
	{
		while (x[i] <= x[m] && (i<m))
			i++ ;
		while (x[j] >= x[m] && (j>m))
			j-- ;
		swap(x[i] , x[j]) ;

		if (i == m) 
			m = j ;
		else
			if (j == m )
				m = i ;
	}
return m ;
}

void qsort (char x[], int  left, int  right)
{
	if (left < right)
		{
		int l = setelement(x,left,right);
		qsort (x,left,l - 1);
		qsort (x,l + 1,right);
		}
}
int main()
{
	char a[100] = {} ;
	int k = 0 ;
	cout << "Enter the number of elements" << endl ;
	cin >> k ;
	cout << "Enter the elements" << endl ;
	for ( int i = 0 ; i < k ; i++) 
	{	
		cin >> a[i] ;
	}

	qsort(a,0,k-1);

	for (int i = 0 ; i <= k-1 ; i++)
	{
		cout << a[i] << " " ;
	}
		int time = 0 ;
		cin >> time ;
		cout << endl ;
		return 0 ;
}