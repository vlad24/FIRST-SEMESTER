#include "multi variable polynomials.h"
#include <stdio.h>


int main()
{
	
	MVPolynomial* polynomialSet[101] = {};
	printf("1-exit\n//2-check the equation of two polynomials\n3-calculate the value in a point\n//4-sum two polynomials\n5-multiply polynomials\n6-print polynomial\n");
	printf("======================\nFILL TWO POLYNOMIALS");
	printf("\n===Polynomial_1===:");
	MVPolynomial* pol1 = createYourMVPolynomial();	
	polynomialSet[1] = pol1;
	printf("===Polynomial_2===:");
	MVPolynomial* pol2 = createYourMVPolynomial();
	polynomialSet[2] = pol2;
	int answer = 0;
	int number = 1;
	int num1 = 1;
	int num2 = 2;
	int amount = 3;
	double x0 = 1;
	double y0 = 1;
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
		
		case 3 :
			{
				printf("Enter the number of polynomial_");
				scanf("%d",&number);
				printf("Enter the point(x0)_");
				scanf("%lf",&x0);
				printf("Enter the point(y0)_");
				scanf("%lf",&x0);
				if(polynomialSet[number] != NULL)
				{
					double y = valueInPoint(polynomialSet[number],x0,y0);
					printf("%lf",y);
				}
				else
					printf("no such polynomial");
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
					MVPolynomial* newPol = multiplyMVPolynomials(polynomialSet[num1],polynomialSet[num2]);
					printf("Polynomial %d :",amount);
					printMVPolynomial(newPol);
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
					printMVPolynomial(polynomialSet[number]);
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
}