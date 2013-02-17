#include "lexical automats.h"
#include <stdio.h>

enum states
{
	start = 0,numberSignTaken,numberIsReady,pointTaken,ETaken,
	ESignTaken,EFracIsReady,fracIsReady,success,fail
};
bool isNumber(char c)
{
	return (((int(c) - int('0')) >= 0) && ((int(c) - int('0')) <= 9));
}
bool isNumberSign(char c)
{
	return ((c == '+') || (c == '-'));
}
bool isMathsSign(char c)
{
	return ((c == '+') || (c == '-') || (c == '/') || (c == '*') || (c == '^'));
}
bool isBracket(char c)
{
	return (c == '(') || ( c == ')');
}
bool endOfString(char c)
{
	return ((c == '\0') || (c == '\n') || (isMathsSign(c) || isBracket(c)));
}
bool correctNumber(char string[],int &i)
{
	bool end = false;
	char current = 'p';
	int state = start;

	while (!end)
	{
		current = string[i];
		switch (state)
		{
		case(start):
			{
				if (isNumberSign(current))
					state = numberSignTaken;
				else if (isNumber(current))
					state = numberIsReady;
				else 
					state = fail;
				break;
			}
		case(numberSignTaken):
			{
				if (isNumber(current))
					state = numberIsReady;
				else 
					state = fail;
				break;
			}
		case(numberIsReady):
			{
				if (isNumber(current))
					state = numberIsReady;
				else if ((current == 'E') || (current == 'e'))
					state = ETaken;
				else if (current == '.')
					state = pointTaken;
				else if (endOfString(current))
					state = success;
				else
					state = fail;
				break;
			}
		case(pointTaken):
			{
				if (isNumber(current))
					state = fracIsReady;
				else
					state = fail;
				break;
			}
		case(fracIsReady):
			{
				if (isNumber(current))
					state = fracIsReady;
				else if (endOfString(current))
					state = success;
				else 
					state = fail;
				break;
			}
		case(ETaken):
			{
				if (isNumberSign(current))
					state = ESignTaken;
				else if (isNumber(current))
					state = EFracIsReady;
				else
					state = fail;
				break;
			}
		case(ESignTaken):
			{
				if (isNumber(current))
					state = EFracIsReady;
				else
					state = fail;
				break;
			}
		case(EFracIsReady):
			{
				if (isNumber(current))
					state = EFracIsReady;
				else if (endOfString(current))
					state = success;
				else
					state = fail;
				break;
			}
		default:
			{
				if (state == fail)
				{
					end = true;
					i--;
					return false;
				}
				else if (state == success)
				{
					end = true;
					i--;
					return true;
				}
				break;
			}
		}
		++i;
	}
}