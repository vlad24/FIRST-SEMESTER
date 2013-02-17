#include <stdio.h>
#include"hashTablesCoo.h"

int main()
{
	int answer = 3;
	char name[24] = {};
	char phone[20] = {};
	HashTable* hTab = createHashTable();
	printf("0-end,1-add,2-search\n");
	while(answer != 0)
	{
		printf("?_");
		scanf("%d",&answer);
		switch (answer)
		{
		case 1 :
			{
				printf("Enter the name : ");
				scanf("%s",&name);
				printf("Enter the phone : ");
				scanf("%s",&phone);
				addToHashTable(hTab,name,phone);
				break;
			}
		case 2 :
			{	
				printf("Enter the name : ");
				scanf("%s",&name);
				InfoBlock* block = searchTelephone(hTab,name);
				if (block != NULL)
					printf("%s\n",block->telephone);
				else
					printf("no such a phone\n");
				break;
			}
		case 0 :
			{
				destroyHashTable(hTab);
				printf("Buy");
			}
		default:
			{
				answer = 0;
			}
		}
	}
	getc(stdin);
}