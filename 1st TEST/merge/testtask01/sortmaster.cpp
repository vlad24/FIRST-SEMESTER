
#include "sortmaster.h"
#include "stdlib.h"
#include <iostream>
void putinheap(int a[], int i, int lengtha )
{
	lengtha -- ;
	int largesti = i ;
	int kidleft = 2 * i + 1 ;
	int kidright = 2 * i + 2 ;
	if (kidright <= lengtha)
	{
		if ( ( a[i] < a[kidleft] ) || ( a[i] < a[kidright] ) )
		{
			if (a[kidleft] <= a[kidright])
				largesti =  kidright ;
			else
				largesti = kidleft ;
		}
	
		if ( i != largesti )
		{
			int u = a[largesti] ; 
			a[largesti] = a[i] ;
			a[i] = u ;
			putinheap(a,largesti,lengtha ) ;
		}
	}
	else
	{
		if ( kidright == (lengtha + 1) )
				if ( a[i] < a[kidleft] )
				{
					int u = a[kidleft];
					a[kidleft] = a[i];
					a[i] = u;
				}
	}

}

void buildheap (int a[],int lengtha)
{
	lengtha -- ;
	int j = lengtha / 2 - 1;
	if (lengtha % 2 == 0)
	{
		for (int k = j ; k >= 0 ; k-- )
			putinheap(a,k,lengtha) ;
	}
	else
	{
		j = lengtha / 2 ;
		for (int k = j ; k >= 0 ; k-- )
			putinheap(a,k,lengtha) ;
	}

}

void heapsort(int a[],int lengtha)
{
	lengtha -- ;
	
	for (int i = 0 ; i < lengtha ; i++)
		{
			int u = a[0] ;
			a[0] = a[lengtha - i];
			a[lengtha - i ] = u ;
			
			putinheap(a,0,lengtha - i - 1);
		}
}


int setelement(int x[], int  left, int  right )
{
	int i = left ;
	int j = right ;
	int m = ( i + j ) / 2 ;
	while (i < j)
	{
		while (x[i] >= x[m] && (i<m))
			i++ ;
		while (x[j] <= x[m] && (j>m))
			j-- ;
		int u = x[i];
			x[i] = x[j];
			x[j] = u;

		if (i == m) 
			m = j ;
		else
			if (j == m )
				m = i ;
	}
return m ;
}

void quicksort (int x[], int  left, int  right)
{
	if (left < right)
		{
		int l = setelement(x,left,right);
		quicksort (x,left,l - 1);
		quicksort (x,l + 1,right);
		}
}

void inssort(int a[], int size)
{
	int k = 0 ;
	int j = 0 ;
	for (int i = 1 ; i < size ; i++ )
	{
		j = i ;  	
		while ( ( a[j - 1] > a[j] ) && (j >= 1) )
		{
			int u = a[j];
			a[j] = a[j-1];
			a[j-1] = u;
			j-- ;
		}
	}
}