#pragma once
#include <stdio.h>
struct ListElement
{
	int value ;
	ListElement* next ;
};
struct List
{
	ListElement* first ;
};
List* createList();

ListElement* deleteNextElement(List* list ,ListElement* tmp,int j);

bool listIsEmpty(List* list);

int elementsLeft(List* list);

void printList(List* list);

void printListToFile(List* list, FILE* file);

void remove(List* list ,int j);

void add(List* list , int j);

void destroyList(List* list);