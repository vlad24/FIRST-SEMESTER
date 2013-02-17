
#include "sortmaster.h"
#include "stdlib.h"
#include <iostream>
/// Heapsort up
void putinheap(int a[], int i, int lastEl )
{
	int largesti = i ;
	int kidleft = 2 * i + 1 ;
	int kidright = 2 * i + 2 ;
	if (kidright <= lastEl)
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
			putinheap(a,largesti,lastEl ) ;
		}
	}
	else
	{
		if ( kidright == (lastEl+ 1) )
				if ( a[i] < a[kidleft] )
				{
					int u = a[kidleft];
					a[kidleft] = a[i];
					a[i] = u;
				}
	}

}

void buildheap (int a[],int lastEl)
{
	int j = lastEl / 2 - 1;
	if (lastEl % 2 == 0)
	{
		for (int k = j ; k >= 0 ; k-- )
			putinheap(a,k,lastEl) ;
	}
	else
	{
		j = lastEl / 2 ;
		for (int k = j ; k >= 0 ; k-- )
			putinheap(a,k,lastEl) ;
	}

}

void heapsort(int a[],int lastEl)
{
	buildheap (a,lastEl) ;
	for (int i = 0 ; i < lastEl ; i++)
		{
			int u = a[0] ;
			a[0] = a[lastEl - i];
			a[lastEl - i ] = u ;
			
			putinheap(a,0,lastEl - i - 1);
		}
}
///

///Qsort down
int setelement(char x[], int  left, int  right )
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

void qsort (char x[], int  left, int  right)
{
	if (left < right)
		{
		int l = setelement(x,left,right);
		qsort (x,left,l - 1);
		qsort (x,l + 1,right);
		}
}
///

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
			if (j == 0)
				break;
		}
	}
}
void selsort(int a[] , int lastEl)
{
	for(int r = 0 ; r <= lastEl ; r++)
	{
		int min = 32000 ;
		int j = 0 ;
		for(int i = r ; i <= lastEl ; i++)
		{
			if (a[i] < min)
			{
				min = a[i] ;
				j = i ;
			}
		}
		int u = a[r] ;
		a[r] = a[j] ;
		a[j] = u ;

	}
}