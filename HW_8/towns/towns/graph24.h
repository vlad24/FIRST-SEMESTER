#pragma once
#include <stdio.h>
#include "lists26.h"

struct Graph
{
	int edges;
	int verteces;
	int** adjMatrix;
	int** incidMatrix;
};

Graph* createGraphFromFile(FILE* file);
void destroyGraph(Graph* &graph);
void printGraphAdjecencyMatrix(Graph* graph);
int* dijkstraAlgorythm(Graph* graph , int vertex , int* &sequence , List** &orderForTowns, int &seqNum);


