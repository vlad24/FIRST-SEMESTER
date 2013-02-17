#include "hashTablesCoo.h"
#include <string.h>
#include <stdlib.h>
#include <cmath>

InfoBlock* createInfoBlock()
{
	InfoBlock* block = new InfoBlock;
	block->name = NULL;
	block->telephone = NULL;
	return block;
}
HashTable* createHashTable()
{
	int size = 8423;
	HashTable* hTable = new HashTable;
	hTable->hArray = new InfoBlock*[size];
	for(int i = 0; i < size; i++)
	{
		(hTable->hArray)[i] = createInfoBlock();
	}
	return hTable;
}
bool cellIsEmpty(HashTable* hTab,int index)
{
	return (hTab->hArray[index]->name == NULL);
}
int hashFunction1(char string[])
{
	int p1 = 3;
	int pPow = 1;
	int j = 0;
	int sum = 0;
	while(string[j] != '\0')
	{
		sum += abs(((int(string[j]) * pPow)));
		pPow *= p1;
		j++;
	}
	return (sum % 4211);
}
int hashFunction2(char string[])
{
	int p2 = 5;
	int pPow = 1;
	int j = 0;
	int sum = 0;
	while(string[j] != '\0')
	{
		sum += abs(((int(string[j]) * pPow)));
		pPow *= p2;
		j++;
	}
	return (sum % 4211) + 4211;
}

void addToHashTable(HashTable* hTable, char string1[], char string2[])
{
	int index = hashFunction1(string1);
	if (cellIsEmpty(hTable,index))
	{
		hTable->hArray[index]->name = strdup(string1) ;
		hTable->hArray[index]->telephone = strdup(string2);
	}
	else
	{

		int index2 = hashFunction2(hTable->hArray[index]->name);
		hTable->hArray[index2]->name = strdup(hTable->hArray[index]->name) ;
		hTable->hArray[index2]->telephone = strdup(hTable->hArray[index]->telephone);
		delete hTable->hArray[index]->name;
		delete hTable->hArray[index]->telephone;
		//
		hTable->hArray[index]->name = strdup(string1);
		hTable->hArray[index]->telephone = strdup(string2);
	}

}
bool stringsEqual(char s1[], char s2[])
{
	int j = 0;
	bool b = true;
	if((s1[0] == '\0') && (s2[0] == '\0'))
			b = true;
	else if (s1[0] == '\0')
			b = false;
	else if (s2[0] == '\0')
			b = false;
	else
	{
		while((s1[j] != '\0') && (s2[j] != '\0') && b)
		{
			if (!(s1[j] == s2[j]))
				b = false;
			j++;
		}
	}
	return b;

}

InfoBlock* searchTelephone(HashTable* hTable,char string[])
{
	int index = hashFunction1(string);
	if (!cellIsEmpty(hTable,index))
	{
		if(stringsEqual(hTable->hArray[index]->name,string))
			return hTable->hArray[index];
		else
		{
			int index2 = hashFunction2(string);
			if(!cellIsEmpty(hTable,index2))
				return hTable->hArray[index2];
			else
				return NULL;
		}
	}
	else
		return NULL;

}
void destroyHashTable(HashTable* &hTable)
{
	for (int i = 0; i < 8423; i++)
	{
		if(hTable->hArray[i]->name != NULL)
			delete (hTable->hArray[i]->name);
		if(hTable->hArray[i]->telephone != NULL)
		delete (hTable->hArray[i]->telephone);
	}
	delete [] hTable->hArray;
	delete hTable;
}
