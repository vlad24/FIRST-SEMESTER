#include <stdio.h>
#include "lists24.h"

List* createList()
{
	List* list = new List ;
	list->first = NULL;
	return list;
}
bool listIsEmpty(List* list)
{
	return (list->first == NULL) ;
}
int elementsLeft(List* list) 
{
	int amount = 0 ;
	ListElement* check = NULL;
	if (!listIsEmpty(list))
	{
		ListElement* tmp = list->first->next ;
		while(tmp != check)
		{
			tmp = tmp->next ;
			amount ++ ;
		}
		amount++;
		return amount ;
	}
	else
		return 0;
}
void printList(List* list) 
{
	int n = elementsLeft(list);
	ListElement* tmp = list->first ;
	for(int j = 1 ; j <= n ; j++)
	{
		printf("%d ",tmp->value) ;
		tmp = tmp->next ;
	}

}
void remove(List* list ,int i)
{
	if (!(listIsEmpty(list)))
	{
		if (!(i == 1))
		{
			ListElement* tmp = list->first ;
			for(int j = 1 ; j < i-1 ; j++)
			{
				if (!(tmp == NULL))
					tmp = tmp->next ;
			}
			if (tmp != NULL)
			{
				if (tmp->next != NULL)
				{
					ListElement* tmp2 = tmp->next ;
					tmp->next = tmp->next->next ;
					delete tmp2;
				}
	
			}
		}
		else
		{
			ListElement* tmp = list->first;
			list->first = list->first->next;
			delete tmp;
		}
	}
}
void add(List* list , int n )
{
	int i = elementsLeft(list);	
	if (i >= 1)
		{
			ListElement* tmp = list->first ;
			for (int k = 1 ; k < i ; k++)
			{
				if (tmp->next != NULL)
					tmp = tmp->next ;
			}
				ListElement* tmp2 = tmp->next ;
				tmp->next = new ListElement ;
				tmp->next->value = n ;
				tmp->next->next = tmp2 ;
		}
	else
		{
			ListElement* tmp = list->first;
			list->first = new ListElement;
			list->first->next = tmp;
			list->first->value = n;
		}
	}	
void destroyList(List* list)
{
	int r = elementsLeft(list);
	if (list->first != NULL)
	{
		ListElement* tmp = list->first;
		for(int i = 1 ; i < r ; i++)
		{
			ListElement* tmp2 = tmp ;
			tmp = tmp->next ;
			delete tmp2;
		}
		delete tmp ;
	}
	delete list ;
}
