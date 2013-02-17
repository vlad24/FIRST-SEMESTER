#include <stdio.h>

int main()
{
	printf( "Enter the number of Fn ") ;
	int n = 0 ;
	scanf("%d", &n) ;
	int a = 0 ; 
	int b = 1 ;
	int fn = 1 ;

	for(int i = 1 ; i <= n-3 ; i++)
	{
		a = b ;
		b = fn ;
		fn = a + b ;
	}
	printf("The number is %d \n",fn); 
	int y = 24;
	scanf("%d",&y);
	return 0;
}