#include "binarySearchTree2.h"
#include <stdio.h>
#include <cstdio>

int main()
{
	FILE* file  = fopen("pretree.txt","r");
	char string[240] = {};
	Tree* tree = createTree();

	char c = 'p';
	int i = 0;

	while(!feof(file))
	{
		fscanf(file,"%c",&c);
		if ((c != '(') && (c != ')') && (c != ' ') )
		{
			string[i] = c;
			i++;
		}
		c = '(';
	}

	formTreeFromPrefixString(tree->root,0,string,0);

	inorderExpression(tree->root);	
	printf("\n");
	preorderExpression(tree->root);
	printf("\n");

	int result = calculateTree(tree);
	printf("the value of the expression is %d\n",result);
	
	deleteTree(tree);
	fclose(file);

	int pause = 24;
	scanf("%d",&pause);
}