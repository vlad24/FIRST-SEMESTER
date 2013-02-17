#include <stdio.h>

bool isNumber(char c)
{
	return (((int(c) - int('0')) >= 0) && ((int(c) - int('0')) <= 9));
}
bool endOfString(char c)
{
	return ((c == '\0') || (c == '\n'));
}
bool isSign(char c)
{
	return ((c == '+') || (c == '-'));
}

int main()
{
	bool end = false;
	char current = 'p';
	char string[100] = {};
	printf("Enter the real number\n");
	fgets(string,100,stdin);
	int state = 0;
	int i = 0;
	while (!end)
	{
		current = string[i];
		switch (state)
		{
		case(0):
			{
				if (isNumber(current))
					state = 1;
				else
					state = -1;
				break;
			}
		case(1):
			{
				if (isNumber(current))
					state = 1;
				else if (current == 'E')
					state = 3;
				else if (current == '.')
					state = 2;
				else if (endOfString(current))
					state = 7;
				break;
			}
		case(2):
			{
				if (isNumber(current))
					state = 2;
				else if (endOfString(current))
					state = 7;
				else
					state = -1;
				break;
			}
		case(3):
			{
				if (isSign(current))
					state = 4;
				else if (isNumber(current))
					state = 6;
				else
					state = -1;
				break;
			}
		case(4):
			{
				if (isNumber(current))
					state = 5;
				else
					state = -1;
				break;
			}
		case(5):
			{
				if (isNumber(current))
					state = 5;
				else if (endOfString(current))
					state = 7;
				else
					state = -1;
				break;
			}
		case(6):
			{
				if (isNumber(current))
					state = 6;
				else if (endOfString(current))
					state = 7;
				else 
					state = -1;
				break;
			}
		default:
			{
				if (state == -1)
					printf("mistake");
				else if (state == 7)
					printf("correct");
				end = true;
				break;
			}
		}
		++i;
	}
	getc(stdin);
}
