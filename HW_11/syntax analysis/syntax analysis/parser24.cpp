#include "parser24.h"
#include "lexical automats.h"

bool sumExpression(char s[], int &position);
bool multiplicationExpression(char s[], int &position);
bool sumExpressionDash(char s[], int &position);
bool multiplicationExpressionDash(char s[], int &position);
bool simpleExpression(char s[], int &position);
bool stopAtEnd(char s[], int position)
{
	return ((s[position] == '\0') || (s[position] == '\n'));
}
bool normalArithmeticExpression(char s[])
{
	int position = 0;
	return sumExpression(s, position) && stopAtEnd(s, position);
}
bool sumExpression(char s[],int &position)
{
	int current = position;
	if (multiplicationExpression(s, current) && sumExpressionDash(s, current))
	{
		position = current;
		return true;
	}
	else
	{
		return false;
	}
}
bool multiplicationExpression(char s[], int &position)
{
	int current = position;
	if (simpleExpression(s, current) && multiplicationExpressionDash(s, current))
	{
		position = current;
		return true;
	}
	else
	{
		return false;
	}
}
bool isPlusOrMinus(char c)
{
	return ((c == '-') || (c == '+'));
}
bool sumExpressionDash(char s[],int &position)
{
	if (isPlusOrMinus(s[position]))
	{
		int current = position + 1;
		if (multiplicationExpression(s, current) && (sumExpressionDash(s, current)))
		{
			position = current;
			return true;
		}
		else
			return true;
	}
	else
	{
		return true;
	}
}
bool isStarOrSlash(char c)
{
	return ((c == '*') || (c == '/')) ;
}
bool multiplicationExpressionDash(char s[], int &position)
{
	if ( isStarOrSlash(s[position]) )
	{
		int current = position + 1;
		if (simpleExpression(s, current) && multiplicationExpressionDash(s, current))
		{
			position = current;
			return true;
		}
		else
			return true;
	}
	else
	{
		return true;
	}
}
bool isNumberSymbol(char c)
{
	return (((int(c) - int('0')) >= 0) && ((int(c) - int('0')) <= 9));
}
bool isMinusSymbol(char c)
{
	return (c == '-');
}
bool simpleExpression(char s[], int &position)
{
	if (s[position] == '(') 
	{
		int current = position + 1;
		if (sumExpression(s, current))
		{
			position = current;
			if (s[position] == ')')
			{
				position++;
				return true;
			}
			else
			{
				return false;
			}
		}
		else
			return false;
	}
	else if (isNumberSymbol(s[position]) || isMinusSymbol(s[position]))
	{
		 return correctNumber(s,position);
	}
	else 
	{
		return false;
	}
}
