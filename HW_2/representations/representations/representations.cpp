

#include "stdafx.h"
#include <iostream>
using namespace std;


void pre(int a[] , int r, int down , int pos )
{
    if (r == 0)
    {
       for (int i = 0 ; i < pos ; i++)
       {
           cout << a[i] << " " ;
       }
       cout << endl;
       return ;
    }
    for (int i = down ; i <= r ; i++ )
    {
        a[pos] = i ;
        pre(a , r - i, i , pos + 1 ) ;
    }
}
int main()
{
	int a[100] = {} ;
	int r = 1 ;
    cout << "Enter the number " << " " ;
    cin >> r ;
    pre(a,r,1,0) ;
    
    int stop = 0;
    cin >> stop ;
}

