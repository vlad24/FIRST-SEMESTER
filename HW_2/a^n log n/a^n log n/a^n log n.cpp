
#include "stdafx.h"
#include <iostream>
using namespace std ;

int main()
{
	int n = 1 ;	
	int p = 1 ;
	printf("Enter your number" "\n");
	scanf("%d",&n) ;
	printf("Enter the power" "\n");
	scanf("%d",&p) ;
	
	int res = 1 ;
	int gain = n ;

	while ( p != 0)
	{
		if ((p % 2) == 0)
		{
			p = p >> 1 ;
			gain *= gain ;
		}
		else
		{
			p-- ;
			res = res * gain ;
	
		}
	}
	
	cout << "n^p = " << res ;
	
	int u = 0 ;
	cin >> u ;
	cout << endl ;
	return 0;
}

