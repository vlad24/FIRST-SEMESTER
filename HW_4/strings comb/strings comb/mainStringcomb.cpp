#include "stdlib.h"
#include "stdio.h"
#include <iostream>

void countsort(char a[],int length)
{
	char tmp[250] = {} ;
	
	for (int i = 0 ; i < length ; i++) 
	{
		tmp[int(a[i])]++;
	}
	int t = 0 ;
	for (int j = 0 ; j <= 250 ; j++)
	{
		if(tmp[j] > 0)
			for (int r = 1 ; r <= tmp[j] ; r++)
			{
				a[t] = j ;
				t++ ;
			}
		
	}

}
bool strAreEqual(char a[],char b[] , int la ,int lb)
{
	bool h = true ;
	if(la != lb) 
		h = false ;
	else
	{
		for(int i = 0 ; i < la ; i++)
		{
			if (a[i] != b[i]) 
				h = false;
		}
	}
	return h ;
}
int length(char a[])
{
	int i = 0 ;
	while(a[i] != '\0')
		i++;
	return i-1 ;
}

int main()
{
	
	char x[150] ;
	char y[150] ;
	printf("Enter the first string_") ;
	fgets(x,150,stdin);
	printf("Enter the second string_") ;
	fgets(y,150,stdin);
	int lengthx = 24 ;
	int lengthy = 24 ;
	lengthx = length(x);
	lengthy = length(y);
	countsort(x,lengthx);
	countsort(y,lengthy);
	for(int j = 0 ; j <= lengthx ; j ++)
	{
		printf("%c",x[j]);
	}
	printf("\n");
	for(int j = 0 ; j <= lengthx ; j ++)
	{
		printf("%c",y[j]);
	}
	printf("\n");
	if (strAreEqual(x,y,lengthx,lengthy))
		printf("Strings are equal");
	else
		printf("Strings are not equal");
	int u = 24 ;
	scanf("%d" , &u);
}