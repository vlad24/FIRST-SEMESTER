//#include <stdafx.h >
#include <iostream >

using namespace std;


int main()
{
	int a = 2;
	cout << "Enter number a :" << endl;
	cin >> a;
	int b = 2;
	cout << "Enter number b :" << endl;
	cin >> b;
	int k = 0;
	if (b != 0)
	{
		while(a > b)
		{
			a-= b;
			k+= 1;
		}
		cout<< "partial quotient k =" << k <<endl;
	}
	else
	{
		cout << "Enter another number b.";
	}
	
	int time;
	cin >> time ;
	return 0;
}

