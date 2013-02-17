#include "binarySearchTree2.h"
#include <stdio.h>
	enum command
		{
			exit = 0,add,deleteValue,printup,printdown,exsists
		};

void introduction()
{
	printf("===============================\n");
	printf("0 - exit \n");
	printf("1 - add value to the set\n");
	printf("2 - remove value from the set\n");
	printf("3 - print list up \n");
	printf("4 - print list down \n");
	printf("===============================\n");
}

int ask(int &ans)
{
	printf("What now? ");
	scanf("%d",&ans);
	return ans;
}


int main()
{

	Tree* treeSet = createTree();
	introduction();
	int answer = -1;
	int value = 0 ;
	
	while (answer != exit)
	{
		answer = ask(answer);
		switch(answer)
		{
			case(add):
			{
				printf("What value? ");
				scanf("%d",&value);
				addToTree(treeSet,value);
				printf("Done.\n");
				break;
			}
			case(deleteValue):
			{
				printf("What value? ");
				scanf("%d",&value);
				removeFromTree(treeSet,value);
				printf("Done.\n");
				break;
			}	
			case(printup):
			{
				treeInorder(treeSet);
				printf("\n");
				break;
			}
			case(printdown):
			{
				treeSpecialInorder(treeSet);
				printf("\n");
				break;
			}
			case(exsists):
			{
				printf("What value? ");
				scanf("%d",&value);
				if(exsistsInTree(treeSet,value))
					printf("Exsists\n");
				else
					printf("Doesn't exsist\n");
				break;
			}
		}
	

	}
	deleteTree(treeSet);

}
