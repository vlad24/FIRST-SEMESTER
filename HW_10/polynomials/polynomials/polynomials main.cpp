#include "polynomialList.h"
#include <stdio.h>
#include <stdlib.h>

void test1()
{
	Polynomial* pol = createPolynomial(3);
	Polynomial* pol2 = createPolynomial(0);
	addToPolynomial(pol,-1,1);
	addToPolynomial(pol,-1,2);
	addToPolynomial(pol,-1,3);
	printPolynomial(pol);
	printf("\n");

	addToPolynomial(pol2,5,4);
	addToPolynomial(pol2,-1,3);
	addToPolynomial(pol2,5,2);
	printPolynomial(pol2);
	printf("\n");

	Polynomial* pol3 = mergePolynomials(pol,pol2);
	printPolynomial(pol3);
}
void test2()
{
	Polynomial* pol4 = createYourPolynomial();
	printPolynomial(pol4);
	getc(stdin);
	double v = valueInPoint(pol4,24);
	printf(" %0.3f\n",v);
}
int main()
{
	/*test1();
	test2();*/
	Polynomial* polynomialSet[101] = {};
	printf("1-exit\n2-check the equation of two polynomials\n3-calculate the value in a point\n4-sum two polynomials\n5-multiply polynomials\n6-print polynomial\n");
	printf("======================\nFILL TWO POLYNOMIALS");
	printf("\n===Polynomial_1===:");
	Polynomial* pol1 = createYourPolynomial();	
	polynomialSet[1] = pol1;
	printf("===Polynomial_2===:");
	Polynomial* pol2 = createYourPolynomial();
	polynomialSet[2] = pol2;
	int answer = 0;
	int number = 1;
	int num1 = 1;
	int num2 = 2;
	int amount = 3;
	double x0 = 1;
	int y = 0;
	do
	{
		
		printf("\nWhat now?_");
		scanf("%d",&answer);
		switch (answer)
		{
		case 1:
			{
				break;
			}
		case 2 :
			{
				printf("Enter the number of 1st polynomial_");
				scanf("%d",&num1);
				printf("Enter the number of 2nd polynomial_");
				scanf("%d",&num2);
				if((polynomialSet[num1] != NULL) && (polynomialSet[num2] != NULL))
					if (polynomialsEqual(polynomialSet[num1],polynomialSet[num2]))
						printf("they equal");
					else
						printf("they do not equal");
				break;
			}
		case 3 :
			{
				printf("Enter the number of polynomial_");
				scanf("%d",&number);
				printf("Enter the point_");
				scanf("%lf",&x0);
				if(polynomialSet[number] != NULL)
				{
					double y = valueInPoint(polynomialSet[number],x0);
					printf("%lf",y);
				}
				else
					printf("no such polynomial");
				break;
			}
		case 4 :
			{
				printf("Enter the number of 1st polynomial_");
				scanf("%d",&num1);
				printf("Enter the number of 2nd polynomial_");
				scanf("%d",&num2);
				if((polynomialSet[num1] != NULL) && (polynomialSet[num2] != NULL))
				{
					Polynomial* newPol = mergePolynomials(polynomialSet[num1],polynomialSet[num2]);
					printf("Polynomial %d :",amount);
					printPolynomial(newPol);
					polynomialSet[amount] = newPol;
					++amount;
				}
				else
					printf("one of the polynomials doesn't exsist");
				break;
			}
		case 5 :
			{
				printf("Enter the number of 1st polynomial_");
				scanf("%d",&num1);
				printf("Enter the number of 2nd polynomial_");
				scanf("%d",&num2);
				if((polynomialSet[num1] != NULL) && (polynomialSet[num2] != NULL))
				{
					Polynomial* newPol = multiplyPolynomials(polynomialSet[num1],polynomialSet[num2]);
					printf("Polynomial %d :",amount);
					printPolynomial(newPol);
					polynomialSet[amount] = newPol;
					++amount;
				}
				else
					printf("one of the polynomials doesn't exsist");
				break;
			}
		case 6:
			{
				printf("Enter the number of polynomial_");
				scanf("%d",&number);
				if(polynomialSet[number] != NULL)
					printPolynomial(polynomialSet[number]);
				else
					printf("no such polynomial");
				break;
			}
		default:
			{
				answer = 1;
				break;
			}
		}
	}
	while(answer != 1);

	for(int j = 1 ; j < amount ; j++)
		destroyPolynomial(polynomialSet[j]);
	
	getc(stdin);
}