#include "sortedlists.h"
#include <stdlib.h>
#include <iostream>

void talk()
{
	printf("\n===============================\n");
	printf("0 - exit \n");
	printf("1 - add value to sorted list \n");
	printf("2 - remove value from list  \n");
	printf("3 - print list \n");
	printf("===============================\n");
}

int main()
{
	int k = 24;
	int v = 24;
	List* list = createList(0);
	printf("Hello,an empty list has been created.What do you want to do?");
	talk();
	do
	{
		printf("What now?\n");
		scanf("%d",&k);
		if(k == 1)
		{
			printf("Enter the value\n");
			scanf("%d",&v);
			addToSList(list,v);
			printf("Done!");
		}
		if(k == 2)
		{
			printf("Enter the value \n");
			scanf("%d",&v);
			removeSList(list,v);
		}

		if(k == 3)
		{
			printList(list);
		}
	}
	while(k != 0);
	
	printf("Goodbye!");
	destroyList(list);
	int u = 24;
	scanf("%d",&u);
}