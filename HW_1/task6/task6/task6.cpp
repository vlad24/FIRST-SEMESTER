//#include "stdafx.h"
#include "iostream"
using namespace std;

int slen(char c[])
{
	int u = 0;
	while (c[u] != '\0') 
	{
		u++;
	}
	return u;
}

int main()
{
	char mainstring[100] = {};
	char substring[100] = {};
	cout << "Enter the main string : " ;
	cin >> mainstring;
	cout << "Enter the sub string : " ;
	cin >> substring;

	int lengthmain = slen(mainstring);
	int lengthsub = slen(substring);

	int amount = 0;
	int indicator = 0;
	for (int j = 0; j <= lengthmain - lengthsub; j++ )
	{
		indicator = 0;
		for (int k = 0; k <= lengthsub; k++ )
		{
			if (mainstring[j + k] == substring[k]) 
			{
				if ((k == lengthsub - 1) && (indicator == 0)) 
					amount ++;
			}
			else
			{
				indicator =- 1;
			}
		}
	}

	cout << "Amount of occurences = " << amount ;


	int time = 0;
	cin >> time;
	
	return 0;
}

