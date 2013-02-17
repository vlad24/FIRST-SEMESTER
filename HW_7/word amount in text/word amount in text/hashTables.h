#pragma once
#include"lists26.h"
struct HashTable
{
 List** hArray; 
};
void destroyHashTable(HashTable* &hTable);
void addToHashTable(HashTable* hTable, char string[]);
int hashFunction(char string[]);
HashTable* createHashTable();