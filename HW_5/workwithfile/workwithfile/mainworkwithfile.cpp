#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	FILE* file = fopen("file1.txt","r");
	freopen("file2.txt","w",stdout);
	int i = 0;
	int j = 0;
	bool notInStarComment = true;
	bool notInKav = true;
	char line[100] = {};
	if (file != NULL)
	{
		fgets(line,100,file);
		while (!feof(file))
		{
				if ((notInStarComment) && (notInKav))
				{
					if (line[j] != '\n')
					{
						while ((line[j] != '/') && (line [j] != '\n') && (line[j] != '"' ))
						j++;
						////
						if ((line[j] == '/') && (line[j + 1] == '/'))
						{
							i = j + 2;
							while(line[i] != '\n')
							{
								printf("%c",line[i]);
								i++;
							}
							printf("\n");
							j = i ;
						}
						////
						else
						{
							////	
							if ( (line[j] == '/') && (line[j + 1] == '*') )
								{	
									notInStarComment = false;
									j += 2;
								}
							/////
								else if(line[j] == '"')
								{
										notInKav = false;
										j += 1;
								}
						}
					}
					else
					{
						fgets(line,100,file);
						j = 0 ;
					}
					
				}
			else
			{
				if(!notInKav)
				{
					while ((line[j] != '\n') && (line[j] != '"') )
						j++;
					if (line[j] == '\n')
						fgets(line,100,file);
					else
						{
						notInKav = true;
						j = j + 1 ;
						}
				}
				else
				{
					while ((line[j] != '\n') && (line[j] != '*') )
					j++;

					if (line[j] == '\n')
						fgets(line,100,file);
					else
					{
						if ((line[j] == '*') && (line[j + 1] == '/'))
						{
							notInStarComment = true;
							j = j + 2;
						}
					}
				}
					
			}
		
		}
	}
	fclose(stdout);
	fclose(file);
}
