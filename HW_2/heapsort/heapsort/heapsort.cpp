#include "stdafx.h"
#include "iostream"
using namespace std ;


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
			swap( a[largesti] , a[i] ) ;
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

int main()
{
	int x[10001] = {} ;
	for(int t = 0 ; t <= 10000 ; t++)
	{
		x[t] = rand() % 1000 ;
	}
	int size = 10001 ;
	//printf("Enter the size of the array ") ;
	//scanf("%d", &size) ;
	//printf("Enter the elements \n") ;
	//for (int j = 0 ; j < size ; j++)
		//cin >> x[j] ;
	
	
	heapsort(x,size - 1) ;
	
	for (int i = 0 ; i < size ; i++)
		cout << x[i] << " ";
	int y = 24 ;
	scanf("%d" , &y) ;
	return 0;
}

