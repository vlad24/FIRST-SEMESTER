#pragma once
struct ListElement
{
	char value ;
	ListElement* next ;
};
struct List
{
	ListElement* first ;
};
List* createList();
bool listIsEmpty(List* list);
int elementsLeft(List* list);
void printList(List* list);
void remove(List* list ,char j);
void add(List* list , char j);
void destroyList(List* list);
void destroyList2(List* list);
void copyList(List* list1,List* &list2);