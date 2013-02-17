#include <stdio.h>
#include <iostream>
using namespace std ;
int main()
{
	printf("Enter the text: ");
	char text[1001] = {};
	char letters[26] = {};
	fgets(text,1000,stdin);
	int i = 0;
	while (text[i] != '\n')
	{
		if (text[i] != ' ')
		{
			/// analysis of the word
			while ((text[i] != ' ') && (text[i] != '\n'))
			{
					if (letters[int(text[i])-int('a')] == 0)
					{
						letters[int(text[i])-int('a')] = 1;
						printf("%c",text[i]);
					}
					i++;

			}
		}
		else
		{
			for (int j = 0 ; j<= 26 ; j++)
			letters[j] = 0;
			printf(" ");
			i++;
		}
	}

	
	int u = 24;
	scanf("%d",&u);
}