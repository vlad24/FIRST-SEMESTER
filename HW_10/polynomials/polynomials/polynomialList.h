struct PolynomialElement
{
	int degree ;
	int coefficient ;
	PolynomialElement* next ;
};
struct Polynomial
{
	PolynomialElement* youngest ;
};

Polynomial* createPolynomial(int size);
bool polynomialIsEmpty(Polynomial* pol) ;
int elementsLeft(Polynomial* pol) ;
void destroyPolynomial(Polynomial* pol) ;
void printPolynomial(Polynomial* pol) ;
void addToPolynomial(Polynomial* pol,int coeff,int deg);
void removeFromPolynomial(Polynomial* pol,int deg);
Polynomial* mergePolynomials(Polynomial* pol1,Polynomial* pol2);
double valueInPoint(Polynomial* pol,double x0);
bool polynomialsEqual(Polynomial* pol1 , Polynomial* pol2);
Polynomial* createYourPolynomial();
Polynomial* multiplyPolynomials(Polynomial* pol1,Polynomial* pol2);
