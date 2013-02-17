#include "sortedlists.h"
#include <stdlib.h>
#include <iostream>
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
				tmp->next = NULL ;
		}
	}
	else
	{
		list->first = NULL ;
	}
	return list ;
}
	

bool listIsEmpty(List* list)
{
	return (list->first == NULL) ;
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
int elementsLeft(List* list) 
{
	int amount = 0 ;
	if (list->first != NULL)
	{
		ListElement* tmp = list->first ;
		amount = 1 ;
		while ( tmp->next != NULL)
		{
			tmp = tmp->next;
			amount++;
		}
	}
	else
		amount = 0 ;
	return amount ;
}
void insertElement(ListElement* tmp , int n , ListElement* tmp2)
{
	tmp-> next = new ListElement ;
	tmp->next->value = n ;
	tmp->next->next = tmp2 ;
}
void addToSList(List* list, int n)
{
	int size = elementsLeft(list) ;
	int p = 1 ;
	if(!(listIsEmpty(list)))
	{
		ListElement* tmp = list->first;
		ListElement* tmp2 = tmp ;
		
		while((tmp->value <= n) && (p < size) )
		{
			tmp2 = tmp ;
			tmp = tmp->next;
			p++ ;
		}

		if((tmp == list->first))
		{
			if (tmp->value >= n)
			{
				tmp2 = list->first ;
				list->first = new ListElement ;
				list->first->value = n ;
				list->first->next = tmp2 ;
			}
			else
				insertElement(tmp,n,NULL);

		}
		else
		{
			if (tmp->value > n)
				insertElement(tmp2,n,tmp);
			
			else
				insertElement(tmp,n,NULL);
			
		}
	}
	else
	{	
		list->first = new ListElement ;
		list->first->value = n ;
		list->first->next = NULL ;
	}

}
void removeSList(List* list , int n)
{
	int size = elementsLeft(list) ;
	int p = 1 ;
	ListElement* tmp = list->first ;
	ListElement* tmp2 = list->first ;
	if (!listIsEmpty(list))
	{
		while((tmp->value != n) && (p < size))
		{
			tmp2 = tmp ;
			tmp = tmp->next ;
			p++ ;
		}
		if (tmp->next == NULL)
		{
			if (tmp->value == n)
			{
				if (tmp != list->first)
				{
				tmp2->next = tmp->next ;
				delete tmp ;
				}
				else
				{
					list->first = NULL ;
					delete tmp ;
				}
			}
			else
				printf("No such value \n");
		}
		else
		{
			if(tmp == tmp2)
			{
				list->first = tmp->next ;
				delete tmp ;
			}
			else
			{
				tmp2->next = tmp->next ;
				delete tmp ;
			}
		}
	}
	else
		printf("No such value \n") ;

}