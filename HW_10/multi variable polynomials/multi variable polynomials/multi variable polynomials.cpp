#include "multi variable polynomials.h"
#include <stdio.h>
#include <cmath>
MVPolynomial* createMVPolynomial(int size)
{
	MVPolynomial* pol = new MVPolynomial ;
	if (size != 0)
	{
		pol->youngest = new MVPolynomialElement ;
		MVPolynomialElement* tmp = pol->youngest ;
		for (int i = 1 ; i <= size ; i++)
		{
			tmp->xDegree = i ;
			tmp->yDegree = i ;
			tmp->coefficient = i + 1;
			if (i != size)
			{
				tmp->next = new MVPolynomialElement ;
				tmp = tmp->next ;
			}
			else
				tmp->next = NULL ;
		}
	}
	else
	{
		pol->youngest = NULL ;
	}
	return pol ;
}

bool MVPolynomialIsEmpty(MVPolynomial* pol)
{
	return (pol->youngest == NULL) ;
}
void insertElement(MVPolynomialElement* tmp ,int xDegree,int yDegree,int coeff , MVPolynomialElement* tmp2)
{
	tmp->next = new MVPolynomialElement ;
	tmp->next->xDegree = xDegree;
	tmp->next->yDegree = yDegree;
	tmp->next->coefficient = coeff;
	tmp->next->next = tmp2 ;
}
void addToMVPolynomial(MVPolynomial* pol, int coeff,int xDeg,int yDeg)
{
	int deg = xDeg + yDeg;
	if(coeff != 0)
	{
		if(!(MVPolynomialIsEmpty(pol)))
		{
			MVPolynomialElement* tmp = pol->youngest;
			MVPolynomialElement* tmp2 = tmp;
		
			while((tmp->yDegree + tmp->xDegree <= deg))
			{
				tmp2 = tmp ;
				tmp = tmp->next ;
				if (tmp == NULL)
					break;
			}

			if((tmp == NULL))
			{
				if (tmp2->yDegree + tmp2->xDegree < deg) 
					insertElement(tmp2,xDeg,yDeg,coeff,NULL);
				else if((tmp2->xDegree == xDeg) && (tmp2->yDegree == yDeg))
					tmp2->coefficient += coeff;
				else
					insertElement(tmp2,xDeg,yDeg,coeff,NULL);
			}
			else
			{
				if (tmp == pol->youngest)
				{
					pol->youngest = new MVPolynomialElement;
					pol->youngest->coefficient = coeff;
					pol->youngest->xDegree = xDeg;
					pol->youngest->yDegree = yDeg;
					pol->youngest->next = tmp2;
				}
				else
				{
					if ((tmp2->xDegree == xDeg)&&(tmp2->yDegree == yDeg))
						tmp2->coefficient += coeff;
					else
						insertElement(tmp2,xDeg,yDeg,coeff,tmp);
				}
			}
		}
		else
		{	
			pol->youngest = new MVPolynomialElement ;
			pol->youngest->xDegree = xDeg;
			pol->youngest->yDegree = yDeg;
			pol->youngest->coefficient = coeff;
			pol->youngest->next = NULL ;
		}
	}

}
int elementsLeft(MVPolynomial* pol) 
{
	int amount = 0 ;
	if (pol->youngest != NULL)
	{
		MVPolynomialElement* tmp = pol->youngest;
		amount = 1 ;
		while ( tmp->next != NULL)
		{
			tmp = tmp->next;
			amount++;
		}
	}
	else
		amount = 0 ;
	return amount ;
}
MVPolynomial* multiplyMVPolynomials(MVPolynomial* pol1 , MVPolynomial* pol2)
{
	if(!MVPolynomialIsEmpty(pol1) && !MVPolynomialIsEmpty(pol2))
	{
		MVPolynomial* newPol = createMVPolynomial(0);
		MVPolynomialElement* tmp1 = pol1->youngest;
		MVPolynomialElement* tmp2 = pol2->youngest;
		int xDeg = 0;
		int yDeg = 0;
		int coeff = 0;
		while(tmp1 != NULL)
		{
			tmp2 = pol2->youngest;
			while(tmp2 != NULL)
			{
				xDeg = tmp1->xDegree + tmp2->xDegree;
				yDeg = tmp1->yDegree + tmp2->yDegree;
				coeff = tmp1->coefficient * tmp2->coefficient;
				addToMVPolynomial(newPol,coeff,xDeg,yDeg);
				tmp2 = tmp2->next;
			}
			tmp1 = tmp1->next;
		}
		return newPol;
	}
}
void printMVPolynomial(MVPolynomial* pol) 
{
	int n = elementsLeft(pol);
	MVPolynomialElement* tmp = pol->youngest;
	for (int j = 1 ; j <= n ; j++)
	{
	////////////
		if (j != 1)
		{
	  ////////////////
			if((tmp->coefficient == 1) || (tmp->coefficient == -1))
			{	
				if(tmp->coefficient == 1)
				{
					printf("+x%d",tmp->xDegree);
					printf("y%d",tmp->yDegree);
					tmp = tmp->next ;
				}
				else
				{
					printf("-x%d",tmp->xDegree);
					printf("y%d",tmp->yDegree);
					tmp = tmp->next ;
				}
			}
			else if (tmp->coefficient != 0)
			{
				if(tmp->coefficient > 0)
				{
					printf("+%d*x%d",tmp->coefficient,tmp->xDegree);
					printf("y%d",tmp->yDegree);
				}
				else
				{
					printf("%d*x%d",tmp->coefficient,tmp->xDegree);
					printf("y^%d",tmp->yDegree);
				}
				tmp = tmp->next;
			}
		
		}
	  /////////
		else
		{
			if ((tmp->xDegree != 0) && (tmp->yDegree != 0))
			{
				if((tmp->coefficient == 1) || (tmp->coefficient == -1))
				{	
					if(tmp->coefficient == 1)
					{
						printf("x%d",tmp->xDegree);
						printf("y%d",tmp->yDegree);
						tmp = tmp->next ;
					}	
					else
					{
						printf("-x%d",tmp->xDegree);
						printf("y%d",tmp->yDegree);
						tmp = tmp->next ;
					}
				}
				else
				{
						printf("%d*x%d",tmp->coefficient,tmp->xDegree);
						printf("y%d",tmp->yDegree);
						tmp = tmp->next;
				}
			}
			else
			{
				printf("%d",tmp->coefficient);
				tmp = tmp->next;
			}
		}	
	/////
	}
////////////////////
}
MVPolynomial* createYourMVPolynomial()
{
	MVPolynomial* pol = createMVPolynomial(0);
	int xDegree = 0;
	int yDegree = 0;
	int coeff = 0;
	int len = 0;
	printf("\nEnter the size of your polynomial\n");
	scanf("%d",&len);
	for(int j = 1 ; j <= len ; j++)
	{
		printf("Degree of the %d element(x): ",j);
		scanf("%d",&xDegree);
		printf("Degree of the %d element(y): ",j);
		scanf("%d",&yDegree);
		printf("Coefficient of the %d element: ",j);
		scanf("%d",&coeff);
		addToMVPolynomial(pol,coeff,xDegree,yDegree);
	}
	return pol;
}
double valueInPoint(MVPolynomial* pol,double x0,double y0)
{
	double value = 0;
	MVPolynomialElement* tmp = pol->youngest;
	while (tmp != NULL)
	{
		value += (tmp->coefficient * pow(x0,tmp->xDegree))*(tmp->coefficient * pow(y0,tmp->yDegree));
		tmp = tmp->next;
	}
	return value;
}