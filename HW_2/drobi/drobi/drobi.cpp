
//#include "stdafx.h"
#include "iostream"
using namespace std;



int main()
{
	cout << "Enter N = " ;
	int n = 1 ;
	cin >> n ;
	int i = 1 ;
	int j = 1 ;
	int del[100] = {} ;
	int l = 0 ;
	int u = 1 ;
	bool b = true ;

	for (i = n ; i > 0 ; i-- )
	{

		// �������� ������,� ������� ����� ���������� ������� ��������� i
		for (int k = 0 ; k <= l ; k++) 
			del[k] = 0 ;
		
		// �������� ������� �� �������
		l = 0 ;

		//������� ����� i ,����� ����� ������
		u = i ;

		// ���� ������� ��������
		for (int d = 2 ; d <= i /2 ; d++)
		{

			if (u % d == 0)
			{
				del[l] = d ;
				while (u % d == 0) 
					u = u / d ;
				l++ ;
			}
		}
		
		// �������� � ����������
		for (j = i - 1 ; j >= 1 ; j--)
		{
			 b = true ;
			for(int h = 0 ; h < l ; h++)
			{
				if(j % del[h] == 0)
					b = false ;
			}
			if (b) 
				cout << j << "/" << i << "; " ;
		}

			
	}
	char time = 'p' ;
	cout << "\n" ;
	cin >> time ;
	return 0;
}

