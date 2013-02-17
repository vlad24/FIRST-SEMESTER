#include <cstdio>
#include <bitset>
#include <iostream>
using namespace std ;

void arrayReflect(int x[],int lastEl)
{
	int y = 0;
	int tmp = 0;
	for ( y = 0 ; y < (lastEl / 2) ; y++)
	{
		tmp = x[y];
		x[y] = x[lastEl - y];
		x[lastEl - y] = tmp;
	}
}
int main()
{
	double x = 0 ;
	printf("Enter a number \n");
	scanf("%lf",&x);
	unsigned char * b = (unsigned char*)&x;
	int xbit[64] = {};
	int bitNum = 1;
	int byteNum = 0;
	int check = 1;
	for(byteNum = 0; byteNum < 8; byteNum++)
	{
		check = 1;
		for(bitNum = 0; bitNum < 8 ; bitNum++)
		{
			if ((unsigned(b[byteNum]) & (check) ) > 0)
				xbit[(8 * byteNum) + bitNum] = 1;
			else
				xbit[(8 * byteNum) + bitNum] = 0;
			
			check = check << 1;
			
		}
	}
	arrayReflect(xbit,63);
	///
	for (bitNum = 0 ; bitNum < 64 ; bitNum++)
	{
		if ((bitNum == 1) || (bitNum == 12))
			printf(" ");
		printf("%d",xbit[bitNum]);
	}
	printf("\n");
	///
	char sign = '+';
	sign = xbit[0]? '-' : '+';
	int i = 0;
	int deg  = 0;
	///
	for(i = 11 ; i > 0 ; i--)
	{
		if ((1 & (xbit[i])) > 0)
		{
			deg << 1;
			deg += (1 << (11 - i));
			
		}
		else
			deg << 1;
	}
	deg -= 1023;
	printf("degree = %d\n",deg);
	///
	for (i = 0 ; i < 12 ; i++)
	{
		if (i == 11)
			xbit[i] = 1;
		else
			xbit[i] = 0;
	}
	///
	double tmp = 1;
	double man = 0;

	for (i = 12 ; i < 64 ; i++)
	{
		tmp = tmp / 2 ;
		man += (xbit[i]) * tmp;
	}

	printf("mantissa = %lf\n",man);

	double res = 1 + man ;
	
	printf(" %c%lf * 2^(%d)",sign,res,deg);

	int o = 24;
	scanf("%d",&o);
}