#include <stdafx.h>
#include <iostream>
using namespace std;

int main()
{
	int x = 0;
	cout << "Enter the numer x: " << endl;
	cin >> x;
	int sq = 0;
	sq = x * x;
	int f = 0;
	f = (sq + 1) * (sq + x) + 1;
	cout << "x4+x3+x3+x2+1= " << f << endl;
	int time;
	cin >> time;
	return 0;
}