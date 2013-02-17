#include "polynomialList.h"
#include <stdlib.h>
#include <cmath>
#include <stdio.h>

Polynomial* createPolynomial(int size)
{
	Polynomial* pol = new Polynomial ;
	if (size != 0)
	{
		pol->youngest = new PolynomialElement ;
		PolynomialElement* tmp = pol->youngest ;
		for (int i = 1 ; i <= size ; i++)
		{
			tmp->degree = i ;
			tmp->coefficient = i + 1;
			if (i != size)
			{
				tmp->next = new PolynomialElement ;
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
bool polynomialIsEmpty(Polynomial* pol)
{
	return (pol->youngest == NULL) ;
}
int elementsLeft(Polynomial* pol) 
{
	int amount = 0 ;
	if (pol->youngest != NULL)
	{
		PolynomialElement* tmp = pol->youngest;
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
bool isSingleTerm(PolynomialElement* tmp)
{
	return ((tmp->coefficient == 1) || (tmp->coefficient == -1));
}
void printSignSingle(PolynomialElement* tmp)
{
		if(tmp->coefficient == 1)
		{
			printf("+x^%d",tmp->degree);
			tmp = tmp->next ;
		}
		else
		{
			printf("-x^%d",tmp->degree);
			tmp = tmp->next ;
		}
}
void printSingle(PolynomialElement* tmp)
{
		if(tmp->coefficient == 1)
			printf("x^%d",tmp->degree);
		else
			printf("-x^%d",tmp->degree);
		
}
void printPlusAdder(PolynomialElement* tmp)
{
	printf("+%d*x^%d",tmp->coefficient,tmp->degree);
}
void printAdder(PolynomialElement* tmp)
{
	printf("%d*x^%d",tmp->coefficient,tmp->degree);
}
void printZeroDegree(PolynomialElement* tmp)
{
	printf("%d",tmp->coefficient);
}
void printPolynomial(Polynomial* pol) 
{
	int n = elementsLeft(pol);
	PolynomialElement* tmp = pol->youngest;
	for (int j = 1 ; j <= n ; j++)
	{
//////////////
		if (j != 1)
		{
			if(isSingleTerm(tmp))
			{
				printSignSingle(tmp);
				tmp = tmp->next;
			}
			else 
			{
				if(tmp->coefficient > 0)
					printPlusAdder(tmp);
				else
					printAdder(tmp);
				tmp = tmp->next;
			}
		
		}
		else
		{
			if (tmp->degree != 0)
			{
				if(isSingleTerm(tmp))
					printSingle(tmp);
				else
					printAdder(tmp);
				tmp = tmp->next;		
			}
			else
			{
				printZeroDegree(tmp);
				tmp = tmp->next;
			}
		}	
	}
////////////////
}
void insertElement(PolynomialElement* tmp , int degree, int coeff , PolynomialElement* tmp2)
{
	tmp->next = new PolynomialElement ;
	tmp->next->degree = degree;
	tmp->next->coefficient = coeff;
	tmp->next->next = tmp2 ;
}
void addToPolynomial(Polynomial* pol, int coeff,int deg)
{
	if(coeff != 0)
	{
		if(!(polynomialIsEmpty(pol)))
		{
			PolynomialElement* tmp = pol->youngest;
			PolynomialElement* tmp2 = tmp;
		
			while((tmp->degree <= deg))
			{
				tmp2 = tmp ;
				tmp = tmp->next ;
				if (tmp == NULL)
					break;
			}

			if((tmp == NULL))
			{
				if (tmp2->degree < deg) 
					insertElement(tmp2,deg,coeff,NULL);
				else
					tmp2->coefficient += coeff;
			}
			else
			{
				if (tmp == pol->youngest)
				{
					pol->youngest = new PolynomialElement;
					pol->youngest->coefficient = coeff;
					pol->youngest->degree = deg;
					pol->youngest->next = tmp2;
				}
				else
				{
					if (tmp2->degree == deg)
						tmp2->coefficient += coeff;
					else
						insertElement(tmp2,deg,coeff,tmp);
				}
			}
		}
		else
		{	
			pol->youngest = new PolynomialElement ;
			pol->youngest->degree = deg ;
			pol->youngest->coefficient = coeff;
			pol->youngest->next = NULL ;
		}
	}

}
void removeFromPolynomial(Polynomial* pol , int deg)
{
	int size = elementsLeft(pol) ;
	int p = 1 ;
	PolynomialElement* tmp = pol->youngest ;
	PolynomialElement* tmp2 = pol->youngest ;
	if (!polynomialIsEmpty(pol))
	{
		while((tmp->degree != deg) && (p < size))
		{
			tmp2 = tmp ;
			tmp = tmp->next ;
			p++ ;
		}
		if (tmp->next == NULL)
		{
			if (tmp->degree == deg)
			{
				if (tmp != pol->youngest)
				{
					tmp2->next = tmp->next ;
					delete tmp ;
				}
				else
				{
					pol->youngest = NULL ;
					delete tmp ;
				}
			}
			else
				printf("No such degree\n");
		}
		else
		{
			if(tmp == tmp2)
			{
				pol->youngest = tmp->next ;
				delete tmp ;
			}
			else
			{
				tmp2->next = tmp->next ;
				delete tmp ;
			}
		}
	}
	else
		printf("No such degree \n") ;

}
void destroyPolynomial(Polynomial* pol)
{
	int n = elementsLeft(pol);
	if (!polynomialIsEmpty(pol))
	{
		PolynomialElement* tmp = pol->youngest;
		for(int i = 1 ; i < n ; i++)
		{
			PolynomialElement* tmp2 = tmp ;
			tmp = tmp->next ;
			delete tmp2;
		}
		delete tmp ;
	}
	delete pol ;
}
Polynomial* mergePolynomials(Polynomial* pol1 , Polynomial* pol2)
{
	Polynomial* result = createPolynomial(0);
	PolynomialElement* tmp1 = pol1->youngest;
	PolynomialElement* tmp2 = pol2->youngest;	
	while((tmp1 != NULL)||(tmp2 != NULL))
	{
		if (tmp1 == NULL)
			while (tmp2 != NULL)
			{
				addToPolynomial(result,tmp2->coefficient,tmp2->degree);
				tmp2 = tmp2->next;
			}
		else if (tmp2 == NULL)
			while (tmp1 != NULL)
			{
				addToPolynomial(result,tmp1->coefficient,tmp1->degree);
				tmp1 = tmp1->next;
			}
		else
		{

			if(tmp1->degree != tmp2->degree)
			{
				if(tmp1->degree < tmp2->degree)
					while(tmp1->degree < tmp2->degree)
					{
						addToPolynomial(result,tmp1->coefficient,tmp1->degree);
						tmp1 = tmp1->next;
						if (tmp1 == NULL)
							break;
					}
				else
					while(tmp2->degree < tmp1->degree)
					{
						addToPolynomial(result,tmp2->coefficient,tmp2->degree);
						tmp2 = tmp2->next;
						if (tmp2 == NULL)
							break;
					}
			}
			else
			{
				addToPolynomial(result,tmp1->coefficient + tmp2->coefficient,tmp1->degree);
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
			}
		}
	}
	return result;
}
double valueInPoint(Polynomial* pol,double x0)
{
	double value = 0;
	PolynomialElement* tmp = pol->youngest;
	while (tmp != NULL)
	{
		value += tmp->coefficient * pow(x0,tmp->degree);
		tmp = tmp->next;
	}
	return value;
}
bool polynomialElementsEqual(PolynomialElement* tmp1 , PolynomialElement* tmp2)
{
	return ((tmp1->coefficient == tmp2->coefficient) && (tmp1->degree == tmp2->degree));
}
bool polynomialsEqual(Polynomial* pol1 , Polynomial* pol2)
{
	int len = elementsLeft(pol1);
	if (len == 0)
		return (elementsLeft(pol2) == 0);
	else
	{
	
		if (len == elementsLeft(pol2))
		{
			PolynomialElement* tmp1 = pol1->youngest;
			PolynomialElement* tmp2 = pol2->youngest;
			bool b = true;
			while (b && tmp1 != NULL && tmp2 != NULL)
			{
				b = polynomialElementsEqual(tmp1,tmp2);
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
			}
		return b;
		}
		else
			return false;
	}
}
Polynomial* createYourPolynomial()
{
	Polynomial* pol = createPolynomial(0);
	int degree = 0;
	int coeff = 0;
	int len = 0;
	printf("\nEnter the size of your polynomial\n");
	scanf("%d",&len);
	for(int j = 1 ; j <= len ; j++)
	{
		printf("Coefficient of the %d element: ",j);
		scanf("%d",&coeff);
		printf("Degree of the %d element: ",j);
		scanf("%d",&degree);
		addToPolynomial(pol,coeff,degree);
	}
	return pol;
}
Polynomial* multiplyPolynomials(Polynomial* pol1 , Polynomial* pol2)
{
	if(!polynomialIsEmpty(pol1) && !polynomialIsEmpty(pol2))
	{
		Polynomial* newPol = createPolynomial(0);
		PolynomialElement* tmp1 = pol1->youngest;
		PolynomialElement* tmp2 = pol2->youngest;
		int deg = 0;
		int coeff = 0;
		while(tmp1 != NULL)
		{
			tmp2 = pol2->youngest;
			while(tmp2 != NULL)
			{
				deg = tmp1->degree + tmp2->degree;
				coeff = tmp1->coefficient * tmp2->coefficient;
				addToPolynomial(newPol,coeff,deg);
				tmp2 = tmp2->next;
			}
			tmp1 = tmp1->next;
		}
		return newPol;
	}
}