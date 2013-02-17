#include "lexical automats.h"
#include "parser24.h"
#include <stdio.h>

int main()
{
	printf("Enter the string\n");
	char string[100] = {};
	char string2[100] = {};
	fgets(string,100,stdin);
	int count = -1;
	/*for(int i = 0; i < 100; i++)
	{
		if (string[i] != ' ')
		{
			count++;
			string2[count] = string[i];
		}
	}*/
	if (normalArithmeticExpression(string))
		printf("normal");
	else
		printf("not normal\n");
	getc(stdin);
}