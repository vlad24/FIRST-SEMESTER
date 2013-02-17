#include <stdio.h>
#include <cstdio>
#include <iostream>

int spaceDemand(int x,int i,int deg)
{
	
	int space = 0 ;
	int x1 = x;
	//for symbols
	do
	{
	x1 /= 10 ;
	space++;
	}
	while(x1 != 0);
	//
	// for a sign
	space++;
	if(( i == 0 ) && (x >= 0))
	{
		space--;
	}
	//
	//for 'x'
	space++;
	if ((i == deg - 1)&&(i == deg))
	{
		space--;
	}
	//
	

	return space;
}
void printSummand(int g,int j,int deg)
{
	if ((j != 0) && (j != deg) && (j != deg - 1) )
	{
		if (g >= 0)
		{
			printf("+");
			printf("%d",g);
			printf("x");
			printf(" ");
		}
		else
		{
			printf("%d",g);
			printf("x");
			printf(" ");
		}
	}
	else
	{
		if (j == 0)
		{
			
				printf("%d",g);
				printf("x");
				printf(" ");
		}
		if (j == deg)
		{
			if (g >= 0)
			{
				printf("+");
				printf("%d",g);
			}
			else
				printf("%d",g);
		}
		if (j == deg - 1)
		{
			if (g >= 0)
			{
				printf("+");
				printf("%d",g);
				printf("x");
			}
			else
			{
				printf("%d",g);
				printf("x");
			}
		}
	}

		
}
int main()
{
	int const size = 100;
	int coefficient[size] = {};
	char string[200] = {};
	int j = 0;
	int deg = 0;
	printf("Enter the degree\n");
	scanf("%d",&deg);
	printf("Enter the coefficients(x^deg..x^0) \n");
	for(int i = 0 ; i <= deg ; i++ )
	{
		scanf("%d",coefficient + i);
	}
	while(j <= deg)
	{
		for(int u = 1 ; u <= spaceDemand(coefficient[j],j,deg) ; u++)
		{
			printf(" ");
		}
		
			if ((deg - j != 0 ) && (deg - j != 1 ))
				printf("%d",deg - j);
		j++;
	}

	printf("\n");
	j = 0;
	while(j <= deg)
	{
		printSummand(coefficient[j],j,deg);
		j++;
	}

int o = 0 ;
scanf("%d",&o);
}