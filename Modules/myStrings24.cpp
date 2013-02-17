#include <stdio.h>
#include "myStrings24.h"
bool stringsEqual(char s1[], char s2[])
{
	int j = 0;
	bool b = true;
	while((s1[j] != '\0') && (s2[j]!='\0') && b)
	{
		if (!(s1[j] == s2[j]))
			b = false;
		j++;
	}
	return b;
}
int stringLength(char s[])
{
	int j = 0;
	while (s[j] != '\0')
		j++;
	return j - 1;
}
void fillString(char mainString[],char tmpString[], int from,int subLen)
{
	for(int i = 0 ; i < subLen ; i++)
	{
		tmpString[i] = mainString[from + i];
	}
}