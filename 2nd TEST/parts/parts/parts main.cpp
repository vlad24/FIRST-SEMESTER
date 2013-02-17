#include <stdio.h>
#include "lists24.h"

int main()
{
	int a = 0;
	int b = 0;
	int tmp = 0;
	List* listLess = createList();
	List* listBetween = createList();
	List* listMore = createList();

	printf("Enter a\n");
	scanf("%d",&a);
	printf("Enter b \n");
	scanf("%d",&b);

	FILE* f = fopen("input.txt","r");
	FILE* g = fopen("output.txt","w");

	while (!(feof(f)))
	{
		fscanf(f,"%d",&tmp);
		if (tmp < a)
			add(listLess,tmp);
		if ((a <= tmp) && (tmp <= b))
			add(listBetween,tmp);
		if (tmp >= b)
			add(listMore,tmp);
	}

	printListToFile(listLess,g);
	fprintf(g," | ");
	printListToFile(listBetween,g);
	fprintf(g," | ");
	printListToFile(listMore,g);

	destroyList(listLess);
	destroyList(listBetween);
	destroyList(listMore);
	fclose(f);
	fclose(g);
	printf("See output file\n");
	getc(stdin);
}