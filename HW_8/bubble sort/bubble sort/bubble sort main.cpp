#include <stdio.h>

void bubbleSortDown(char* s , int LastElement)
{
	for (int j = 1 ; j <= LastElement ; j++)
		for (int i = 0 ; i <= LastElement - j ; i++ )
			if (s[i] < s[i + 1])
			{
				int temp = s[i];
				s[i] = s[i + 1];
				s[i + 1] = temp;
			}
}

void printArray(char* s , int lastElement)
{
	for(int u = 0 ; u <= lastElement ; u++ )
	printf("%c", s[u]);
}

int main()
{
	char string[31] = {};
	printf("Enter the array of characters\n");
	fgets(string,30,stdin);
	int last = -1;
	do
	{
		last++;
	}
	while(string[last] != '\0');
	last--;

	bubbleSortDown(string,last);
	printArray(string,last);
	getc(stdin);
}