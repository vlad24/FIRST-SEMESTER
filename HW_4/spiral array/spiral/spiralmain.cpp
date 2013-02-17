#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std ;

int main()
{
	int dim = 1 ;
	printf("Enter an odd number \n");
	scanf("%d",&dim);
	if (dim % 2 == 1)
	{
		int a[101][101] = {} ;
		int i = 0;
		int j = 0;
		printf("Initialize strings \n") ;
		for (i = 0 ; i < dim ; i++)
			for (j = 0 ; j < dim ; j++)
				cin >> a[i][j] ;
		int edge = dim - 1 ;
		int downborder = edge / 2 + 1;
		int leftborder = edge / 2 - 1;
		int upborder = edge / 2 - 1;
		int rightborder = edge / 2 + 1;
		i = edge / 2  ;
		j = edge / 2  ;
		
		while(!((i == 0) && (j == edge)))
		{
			// moving down
			do
			{
				cout << a[i][j] << " " ;
				i++;
			}
			while (i < downborder) ;
			downborder++ ;
		
			// moving left
			do
			{
				cout << a[i][j] << " ";
				j--;
			}
			while(j > leftborder) ;
			leftborder -- ;
		
			// moving up
			do
			{
				cout << a[i][j] << " ";
				i -- ;
			}
			while (i > upborder) ;
			upborder--;
		
			// moving right
			do
			{
				cout << a[i][j] << " " ;
				j++;
			}
			while(j < rightborder) ;
			rightborder++;

		}
		// printing last column
		for(i = 0 ; i <= edge ; i++)
			cout << a[i][j] << " ";
	}
	else
		cout << " Try again " ;

	int u = 24 ;
	cin >> u ;
}
