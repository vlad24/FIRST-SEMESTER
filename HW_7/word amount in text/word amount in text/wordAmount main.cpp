#include <stdio.h>
#include <stdlib.h>
#include "lists26.h"
#include "hashTables.h"


bool isLetter(char c)
{
	return((c <= 'z') && (c >= 'a'))|| ((c <= 'Z')&&(c >= 'A'));
}

int main()
{
	char string[500] = {};
	char symbol = ' ';
	int j = 0;
	FILE* text = fopen("text.txt","r");
	if (text == NULL)
		   exit (EXIT_FAILURE);

	HashTable* hTable = createHashTable();

	
	
	while (!(feof(text)))
	{
		symbol = ' ';
		fscanf(text,"%c",&symbol);
		if(isLetter(symbol))
		{
			string[j] = symbol;
			j++;
		}
		else if (symbol == ' ')
		{
			addToHashTable(hTable,string);
			for(int i = 0 ; i < j ; i++)
				string[i] = '\0';
			
			j = 0;
		}
	}
	for(int i = 0 ; i < 4211 ; i++)
	{
		if(!(listIsEmpty(hTable->hArray[i])))
		{
			printList(hTable->hArray[i]);
			printf("\n");
		}
	}
	destroyHashTable(hTable);
	fclose(text);
	int y = 24;
	scanf("%d",&y);
}