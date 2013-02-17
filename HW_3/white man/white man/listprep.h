#pragma once
struct ListElement
{
	int value ;
	ListElement* next ;
};
struct List
{
	ListElement* first ;
};
List* createList(int n);
ListElement* deleteNextElement(List* list ,ListElement* tmp,int j);
bool listIsEmpty(List* list);
int elementsLeft(List* list);
void printList(List* list);
void remove(List* list ,int j);
void add(List* list , int j , int i);
void destroyList(List* list);
