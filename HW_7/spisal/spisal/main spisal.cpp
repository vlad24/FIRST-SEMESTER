#include <stdio.h>
#include <cstdio>
#include "lists24.h"

List** createListTable(int n)
{
	List** table = new List*[n + 1];
	for(int i = 0 ; i <= n; i++)
		table[i] = createList();
	return table;
}
void printCheaters(List** table,int studentNumber)
{
	printList(table[studentNumber]);

	ListElement* tmp = table[studentNumber]->first;
	if (!(listIsEmpty(table[studentNumber])))
		while(tmp != NULL)
		{
			printCheaters(table,tmp->value);
			tmp = tmp->next;
		}
	return;
}

int main()
{
	FILE* studentsInfo = fopen("students.txt","r");
	int amount = 3;
	fscanf(studentsInfo,"%d",&amount);
	List** table = NULL;
	table = createListTable(amount + 1);
	

	int victim = 0;
	int cheater = 0;

	while(!(feof(studentsInfo)))
	{
		fscanf(studentsInfo,"%d %d",&cheater,&victim);
		add(table[victim],cheater);
	}

	for (int i = 1; i <= 3; i++)
	{
		printf("Student %d helped: ", i);
		printCheaters(table,i);
		printf("\n");
	}
	
	for(int i = 0 ; i <= amount ; i++)
	{
		destroyList(table[i]);
	}
	delete table;
	
	
	fclose(studentsInfo);
	int y = 24;
	scanf("%d",&y);
}