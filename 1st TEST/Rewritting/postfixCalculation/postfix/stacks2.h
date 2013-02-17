#pragma once
#include <stdlib.h>
#include <limits.h>
#include <iostream>
using namespace std;
struct StackElement
{
	int value ;
	StackElement* next ;
};

struct Stack
{
	StackElement* head ;
};
Stack* createStack() ;
bool isEmpty(Stack* stack) ;
int top(Stack* stack) ;
void push(Stack* stack,char c) ;
int pop(Stack* stack) ;
void printStack(Stack* stack) ;
void destroy(Stack* stack) ;
