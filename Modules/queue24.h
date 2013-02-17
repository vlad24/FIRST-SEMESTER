struct QueueElement
{
	int value;
	QueueElement* next;
};

struct Queue
{
	queueElement* first;
	queueElement* last;
};

