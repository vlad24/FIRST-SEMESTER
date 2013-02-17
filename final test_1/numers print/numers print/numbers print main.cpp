#include "binarySearchTree2.h"
#include <stdio.h>
int main()
{
	int number = 0;
	Tree* tree = createTree();
	printf("Enter your numbers.*Finish with zero :\n");
	do
	{
		scanf("%d",&number);
		if (number != 0)
			addToTree(tree,number);
	}
	while (number != 0);

	if (!(isEmpty(tree)))
		treeInorder(tree);
	else
		printf("No numbers were entered");
	printf("\n");
	deleteTree(tree);

	int y = 24;
	scanf("%d",&y);
}