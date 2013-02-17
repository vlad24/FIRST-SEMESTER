#include "stacks2.h"

int prior(char v)
{
		if ((v == '+') || (v == '-'))
			return 5 ;
		if ((v == '*') || (v == '/'))
			return 7 ;
		if (v == '(')
			return 2 ;
		if (v == ')')
			return 4 ;
		if (v == 'z')
			return 0 ;	
}

bool isSign(char v)
{
	if ((v == '+')||(v == '-')||(v == '*')||(v == '/'))
		return true ;
	else
		return false ;
}
bool isNumber(char v)
{
	if ((int(v) <= int('9')) && (int(v) >= int('0')))
		return true ;
	else
		return false ;
}
int main()
{	
	printf("Enter the string \n") ;
	char norm[100] ;
	fgets(norm,100,stdin);
	int i = 0 ;
	int length = 0 ;
	while(norm[i] != '\0')
	{
		++length;
		++i;
	}
	--length;

	Stack* stack = createStack();
	int u = 24 ;
	for (u = 0 ; u < length ; u++)
		if( isNumber(norm[u]) )
			printf("%c " , norm[u]);
		else
		{
			//Brackets or signs are detected
			if (  isSign(norm[u]) )
			{
				// If it is a sign
				if ( prior(norm[u]) > prior (top(stack)) )
					push(stack,norm[u]);
				else
				{
					while(prior(norm[u]) <= prior( top(stack) ))
					{
						printf("%c " , pop(stack)) ;
					}
					push(stack,norm[u]);
				}
			}
			else
			{
				//If it is a bracket
				if (prior(norm[u]) == 2)
					// It is '(' , because priority of '(' equals 2
					push(stack,norm[u]);
				else
				{
					//Writing everything til an opening bracket
					while (prior(top(stack)) != 2)
					{
						printf("%c " , pop(stack)) ;
					}
					//Deleting the opening bracket
					pop(stack);
				}
			 }
		}
	if (!isEmpty(stack))
		printStack(stack) ;
	destroy(stack) ;
	
	int y = 'y' ;
	scanf("%d" , &y) ;
	return 0;
}
