#include <stdio.h>
#include "listprep.h"

List* createList(int n)
{
	List* list = new List ;
	if (n != 0)
	{
		list->first = new ListElement ;
		ListElement* tmp = list->first ;
		for (int i = 1 ; i <= n ; i++)
		{
			tmp->value = i ;
			if (i!=n)
			{
				tmp->next = new ListElement ;
				tmp = tmp->next ;
			}
			else
				tmp->next = list->first ;
		}
	}
	return list;
}
ListElement* deleteNextElement(List* list ,ListElement* tmp,int j) 
{
	for(int i = 1 ; i < j-1 ; i++)
	{
		tmp = tmp->next ;
	}
	ListElement* tmp2 = tmp->next ;
	tmp->next = tmp->next->next ;
	if (tmp2 == list->first)
		list->first = tmp->next ;
	delete tmp2 ;
	return tmp->next ;
}
bool listIsEmpty(List* list)
{
	return (list->first == NULL) ;
}
int elementsLeft(List* list) 
{
	int amount = 0 ;
	ListElement* check = list->first;
	ListElement* tmp = list->first->next ;
	while(tmp != check)
	{
		tmp = tmp->next ;
		amount ++ ;
	}
	return amount +1  ;
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
	ListElement* tmp = list->first ;
	for(int j = 1 ; j < i-1 ; j++)
	{
		tmp = tmp->next ;
	}
	ListElement* tmp2 = tmp->next ;
	tmp->next = tmp->next->next ;
	if (tmp2 == list->first)
		list->first = tmp->next ;
	delete tmp2 ;
}
void add(List* list , int n , int i)
{
	if(!(listIsEmpty(list)))
	{

		if (i != 1)
		{
			ListElement* tmp = list->first ;
		for (int k = 1 ; k < i-1 ; k++)
		{
			tmp = tmp->next ;
		}
		ListElement* tmp2 = tmp->next ;
		tmp->next = new ListElement ;
		tmp->next->value = n ;
		tmp->next->next = tmp2 ;
		}
		else
		{
			ListElement* tmp = list->first ;
			for(int i = 1 ; i < elementsLeft(list) ; i++ )
				tmp = tmp->next;
			ListElement* tmp2 = new ListElement ;
			tmp2->value = n ;
			tmp2->next = list->first ;
			list->first = tmp2 ;
			tmp->next = tmp2 ;
		}
	}
	else
	{
		list->first = new ListElement ;
			ListElement* tmp = list->first ;
		for (int k = 1 ; k < i-1 ; k++)
		{
			tmp = tmp->next ;
		}
		ListElement* tmp2 = tmp->next ;
		tmp->next = new ListElement ;
		tmp->next->value = n ;
		tmp->next->next = tmp2 ;
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

