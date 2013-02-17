#pragma once

struct InfoBlock
{
	char* name;
	char* telephone; 
};
struct HashTable
{
 InfoBlock** hArray; 
};
void destroyHashTable(HashTable* &hTable);
void addToHashTable(HashTable* hTable, char string1[],char string2[]);
InfoBlock* searchTelephone(HashTable* hTable,char string[]);
int hashFunction1(char string[]);
int hashFunction2(char string[]);
HashTable* createHashTable();