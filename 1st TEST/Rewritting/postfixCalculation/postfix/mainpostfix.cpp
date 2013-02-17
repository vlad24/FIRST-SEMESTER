#include "stacks2.h"
#include <stdio.h>
#include <cstdio>
using namespace std ;
bool isNumber(char v)
{
	if ((int(v) <= int('9')) && (int(v) >= int('0')))
		return true ;
	else
		return false ;
}
bool isSign(char v)
{
	if ((v == '+')||(v == '-')||(v == '*')||(v == '/'))
		return true ;
	else
		return false ;
}
int toInt(char v)
{
	return(int(v)-int('0'));
}
int makeOperation(char c , int a , int b)
{
	if(c == '-')
		return a - b ;
	
	if (c == '+')
		return a + b ;
	if(c == '*')
		return a * b ;
	
	if ((c == '/') && (b != 0))
		return a / b ;
	else
		return INT_MAX ;
}
int lengthOfString(char str[])
{
	int i = 0;
	int len = 0;
	while(str[i] != '\0')
	{
		++len;
		++i;
	}
	--len;
	return len ;
}

int main() 
{
	printf("Enter the string\n");
	char string[100] ={};
	fgets(string,100,stdin);
	int i = 0;
	int length = lengthOfString(string);
	//printf("Length is %d \n",length);
	int tmp1 = 1;
	int tmp2 = 1;
	int res = 0;
	Stack* stack = createStack();
	for(i = 0 ; i < length ; i++)
	{
		if(isNumber(string[i]))
			push(stack,toInt(string[i]));
		if(isSign(string[i]))
		{
			tmp2 = pop(stack);
			tmp1 = pop(stack);
			res = makeOperation(string[i],tmp1,tmp2);
			push(stack,res);
		}
	}
	printf("Result is %d",res);
	destroy(stack);
	printf("\n");
	int u = 24;
	scanf("%d",&u);
	return 0;
}