
//#include "stdafx.h"
#include "iostream"
#include "string.h"
using namespace std;


int main()
{
	char s[100] = {};
	cout <<  "Enter your string : " << "\n" ;
	cin >> s ;
	int length = strlen(s) ;

	int reps[256]={};

	for (int j = 0 ; j < length ; j++)
	{
		reps[s[j]]++ ;
	}

	int odd = 0 ;
	
	for (int j = 0 ; j <= 255 ; j++ )
	{
		if ((reps[j] % 2) != 0)
			odd++ ;
	}

	if (odd > 1) 
	{
		cout << "The string is not a palindrome. " ;
	}
	else
	{
		cout << "The string is a palindrome. " ;
	}
	
	char time = 'p' ;
	cin >> time ;
	return 0;
}

