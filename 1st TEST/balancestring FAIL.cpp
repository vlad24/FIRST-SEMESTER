#include "stdafx.h"
#include "iostream"
using namespace std;
int bracketNumber(char c)
{
	if (c == '(') return 1 ;
	if (c == ')') return 1 ;
	if (c == '{') return 2 ;
	if (c == '}') return 2 ;
	if (c == '[') return 3 ;
	if (c == ']') return 3 ;
}
int bracketSign(char c)
{
	if (c == '(') return 1 ;
	if (c == ')') return -1 ;
	if (c == '{') return 1 ;
	if (c == '}') return -1 ;
	if (c == '[') return 1 ;
	if (c == ']') return -1 ;
}
bool isBracket(char c)
{
	return ((c == '(') || (c== ')') || (c == '{' ) || (c == '}') || (c == ']') || (c == '[')) ;
}
int main()
{
	char s[100] = {};
	int balance[3] = {0,0,0} ;
	bool bad = false ;
	cout << "Enter your string : ";
	cin >> s;
	for (int i = 0; i < 100; i++)
	{
		if (isBracket(s[i]))
		{
			balance[bracketNumber(s[i])] += bracketSign(s[i]) ;
			for (int j = 0 ; j<=2 ; j++)
			{
				if (balance[j] < 0)
					bad = true ;
			}
			if (bad) break ;
		}
   	}
	for (int j = 0 ; j <= 2 ; j++)
	{
		if (balance[j] != 0)
			bad = true ;
	}

	if (bad)
	{
		cout << "disbalance";
	}
	else
	{
		cout << "balance";
	}
	int time;
	cin >> time;

	return 0;
}

