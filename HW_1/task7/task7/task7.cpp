//#include "stdafx.h"
#include "iostream"
using namespace std;


int main()
{
	int l = 0 ; 
	cout << "Enter the up-number = ";
	cin >> l ;

	while (l>1)
	{
		bool q = true ;
		for ( int d = 2 ; d <= l / 2 ; d++ )
		{
			if ((l % d) == 0) 
				q = false ;  
		}
		if (q == true)
			cout << l << " " ;  
		
		l--;
	}
	int time = 0 ;
	cin >> time ;
	return 0;
}

