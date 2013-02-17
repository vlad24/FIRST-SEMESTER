#include <stdio.h>
enum states
{
	start = 0 , state1 , success , mistake
};
bool isNumber(char c)
{
	return (((int(c) - int('0')) >= 0) && ((int(c) - int('0')) <= 9));
}
bool isLetter(char c)
{
	return ( ( (c <= 'Z') && (c >= 'A') ) || ( (c <= 'z') && (c >= 'a') ) );
}
bool endOfString(char c)
{
	return ((c == '\0') || (c == '\n'));
}
int main()
{
	printf("Enter your string\n");
	char string[600] = {};
	fgets(string,600,stdin);

	int i = 0;
	char current = '4';
	bool end = false;
	int state = start;
	while (!end)
	{
		current = string[i];
		switch (state)
		{
		case start:
			{
				if (isLetter(current))
					state = state1;
				else
					state = mistake;
				break;
			}
		case state1:
			{
				if (isLetter(current) || isNumber(current) || (current == '_'))
					state = state1;
				else if ( endOfString(current) )
					state = success;
				else
					state = mistake;
				break;
			}
		case success:
			{
				end = true;
				printf("valid string\n");
				break;
			}
		case mistake :
			{
				end = true;
				printf("invalid string\n");
				break;
			}
		}
		++i;
	}
	getc(stdin);
}