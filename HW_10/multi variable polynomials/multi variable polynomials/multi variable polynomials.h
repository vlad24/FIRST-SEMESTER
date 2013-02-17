#pragma once
#include <stdio.h>
struct MVPolynomialElement
{
	int coefficient;
	int xDegree;
	int yDegree;
	 MVPolynomialElement* next;
};
struct MVPolynomial
{
	MVPolynomialElement* youngest; 
};
MVPolynomial* createMVPolynomial(int size);
bool MVPolynomialIsEmpty(MVPolynomial* pol);
void insertElement(MVPolynomialElement* tmp ,int xDegree,int yDegree,int coeff , MVPolynomialElement* tmp2);
void addToMVPolynomial(MVPolynomial* pol, int coeff,int xDeg,int yDeg);
MVPolynomial* multiplyMVPolynomials(MVPolynomial* pol1 , MVPolynomial* pol2);
int elementsLeft(MVPolynomial* pol);
void printMVPolynomial(MVPolynomial* pol);
MVPolynomial* createYourMVPolynomial();
double valueInPoint(MVPolynomial* pol ,double x0 , double y0);