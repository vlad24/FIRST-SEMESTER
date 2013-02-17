#include "graph24.h"
#include "lists26.h"
#include <stdio.h>

void test()
{
	List* list1 = createList();
	add(list1,'t');
	add(list1,'r');
	add(list1,'q');
	add(list1,'o');
	add(list1,'p');
	printList(list1);
	printf("\n");
	List* list2 = createList();
	copyList(list1,list2);
	printList(list2);
	int r = elementsLeft(list2);
	printf(" %d" , r);
	getc(stdin);
}
int main()
{

	//test();
	
	FILE* file0 = fopen("towns2.txt","r");
	Graph* townGraph = createGraphFromFile(file0);

	int* seq = new int[townGraph->verteces + 1];
	int seqNum = 0;
	List** order = new List*[townGraph->verteces + 1];
	for(int y = 1 ; y <= townGraph->verteces ; y++)
		order[y] = createList();
	add(order[1],'1');

	printGraphAdjecencyMatrix(townGraph);
	int* distance = dijkstraAlgorythm(townGraph,1,seq,order,seqNum);
	for(int i = 1 ; i <= seqNum ; i++)
	{
			if (i == 1)
			{
				printf("->'%d'\n",seq[i]);
			}
			if (( i > 1) && ( i <= townGraph->verteces ))
			{
				printf("->'%d'\n",seq[i]);
				printList(order[seq[i]]);
				printf(" | length = %d \n",distance[seq[i]]);
			}
	}
	for(int u = 1 ; u <= townGraph->verteces ; u++)
		destroyList(order[u]);
	delete[] order;
	delete[] seq;
	delete[] distance;	
	destroyGraph(townGraph);
	
	fclose(file0);
	printf("\n");
	getc(stdin);
}
