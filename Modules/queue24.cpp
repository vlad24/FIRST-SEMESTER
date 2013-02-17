#include "queue.h"
#include <stdlib.h>
#include <limits.h>
#include <iostream>
using namespace std;
Queue* createQueue()
{
	Queue* queue = new Queue ;
	queue->first = NULL ;
	queue->last = NULL ;
	return queue ;
}
bool isEmpty(Queue* queue)
{
	return (queue->last == NULL) ;
}

int lastQ(Queue* queue)
{
	if (!isEmpty(queue))
		return queue->last->value ;
	else
		return INT_MIN;
}

void pushQ(Stack* stack,int k)
{
		queue->last->next = new QueueElement;
		queue->last->next->value = k;
		queue->last->next->next = NULL;
		queue->last = queue->last->next;
		
}

int takeQ(Stack* stack)
{
	if (isEmpty(queue))
	{
		return INT_MIN;
	}
	else
	{
		int result = queue->first->value;
		QueueElement* tmp = queue->first;
		queue->first = tmp->next;
		delete tmp;
		if (queue->first == NULL)
			queue->last = NULL;
		return result;
	}
}
 
void printQueue(Queue* queue)
{
	if (!isEmpty(queue))
	{
		printf("%d ",queue->first->value) ;
		QueueElement* tmp = queue->first ;
		while (tmp != queue->last)
		{
			tmp = tmp->next ;
			printf("%d",tmp->value);

		}
	}
	else
		printf("An empty queue ") ;
}


void destroy(Stack* stack)
{
	StackElement* tmp = stack->head ;
	if (stack->head != NULL)
	{
		while (tmp->next != NULL)
		{
		StackElement* tmp2 = tmp ;
		tmp = tmp->next ;
		delete tmp2;
		}
		delete tmp ;
		delete stack ;
	}
	else
		delete stack ;
}