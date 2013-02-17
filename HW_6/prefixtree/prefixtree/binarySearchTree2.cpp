#include "binarySearchTree2.h"
#include <cstdio>

Tree* createTree()
{
	Tree* tree = new Tree;
	tree->root = NULL;
	return tree;
}

bool isEmpty(Tree* tree)
{
	return (tree->root == NULL);
}

bool exsistsInSubtree(TreeNode* node,int value)
{
	if (node == NULL)
		return false;
	if (node -> value == value )
		return true;
	if (value > node->value)
		return exsistsInSubtree(node->right,value);
	else
		return exsistsInSubtree(node->left,value);
}

bool exsistsInTree(Tree* tree,int value)
{
		return exsistsInSubtree(tree->root,value);
}

TreeNode* searchInSubtree(TreeNode* &node,int value)
{
	if (node == NULL)
		return NULL;
	if (node -> value == value )
		return node;
	if (value > node->value)
		return searchInSubtree(node->right,value);
	else
		return searchInSubtree(node->left,value);
}

TreeNode* searchInTree(Tree* &tree,int value)
{
	return searchInSubtree(tree->root,value);
}

void createNode(TreeNode* &node,int value)
{
	node = new TreeNode;
	node->value = value;
	node->left = NULL;
	node->right = NULL;
}

void addToSubtree(TreeNode* &node,int value)
{
	if (node == NULL)
		return createNode(node,value);
	else if (node -> value == value)
			return;
		 else if (value > node->value)
				  return addToSubtree(node->right,value);
			  else
				   return addToSubtree(node->left,value);		
}

void addToTree(Tree* &tree,int value)
{
	return addToSubtree(tree->root,value);	
}

bool hasLeftChild(TreeNode* &node)
{
	return (node->left != NULL);
}

bool hasRightChild(TreeNode* &node)
{
	return (node->right != NULL);
}

bool hasOneChild(TreeNode* &node)
{
	return ((hasLeftChild(node)) && !(hasRightChild(node))) || ( !(hasLeftChild(node)) && (hasRightChild(node)) );
}

bool isLeaf(TreeNode* &node)
{
	return (!hasLeftChild(node) && !hasRightChild(node)); 
}

int popMostLeftValue(TreeNode* &node)
{
	int k = 0 ;
	if (node->left != NULL)
		return popMostLeftValue(node->left);
	else
	{
		 k = node->value;
		 delete node;
		 node = NULL;
		 return k ;
	}
}

void removeFromSubTree(TreeNode* &node,int value)
{
	if (node == NULL)
		printf("no such an element.");
	else if (node -> value == value )
		{
			if((isLeaf(node))||(hasOneChild(node)))
			{
				if (isLeaf(node))
				{
					delete node;
					node = NULL;
					return;
				}
				if (hasOneChild(node))
				{
					if(hasLeftChild(node))
					{
						TreeNode* tmp = node->left;
						delete node;
						node = tmp;
					}
					else
					{
						TreeNode* tmp = node->right;
						delete node;
						node = tmp;
					}
				}
			}
			else
			{
				int tmp = popMostLeftValue(node->right);
				node->value = tmp;
			}

		}
		else if (value > node->value)
				return removeFromSubTree(node->right,value);
			else
				return removeFromSubTree(node->left,value);
		
	
}

void removeFromTree(Tree* tree,int value)
{
	removeFromSubTree(tree->root,value);
}

void preorder(TreeNode* &node)
{
	if (node != NULL)
	{
		preorder(node->left);
		preorder(node->right);
		printf("%d ",node->value);
	}
	else
	{
		return;
	}
}

void treePreorder(Tree* &tree)
{
	preorder(tree->root);
}
//
void inorder(TreeNode* &node)
{
	if (node->left != NULL)
	{
		inorder(node->left);
		printf(" %d",node->value);
		if( node->right != NULL)
			inorder(node->right);
	}
	else
	{
		printf(" %d",node->value);
		if( node->right != NULL)
			inorder(node->right);
	}
	return;
}

void treeInorder(Tree* &tree)
{
	if (!(isEmpty(tree)) )
		inorder(tree->root);
}
//
void specialInorder(TreeNode* &node)
{
	if (node->right != NULL)
	{
		specialInorder(node->right);
		printf(" %d",node->value);
		if( node->left != NULL)
			specialInorder(node->left);
	}
	else
	{
		printf("%d",node->value);
		if( node->left != NULL)
			specialInorder(node->left);
	}
	return;
}

void treeSpecialInorder(Tree* &tree)
{
	if (!(isEmpty(tree)) )
	specialInorder(tree->root);
}
//
void deleteSubTree(TreeNode* &node)
{
	if (node == NULL)
	{
		return;
	}
	else
	{
		deleteSubTree(node->left);
		deleteSubTree(node->right);
		delete node;
	}
}

void deleteTree(Tree* &tree)
{
	deleteSubTree(tree->root);
	delete tree;
}
//
bool isSign(char v)
{
	return(( v == '*') || (v == '-') || (v == '/') || (v == '+'));
}

int ordToNum(int x)
{
	return (x - int('0'));
}

int makeOperation(int argument1,int argument2,int operation)
{	
	if (argument1 > 9)
		argument1 = ordToNum(argument1);
	if (argument2 > 9)
		argument2 = ordToNum(argument2);
	if (char(operation) == '+')
		return argument1 + argument2;
	if (char(operation) == '-')
		return argument1 - argument2;
	if (char(operation) == '*')
		return argument1 * argument2;
	if ((char(operation) == '/') && (argument2 != 0))
		return argument1 / argument2;
}

int formTreeFromPrefixString(TreeNode* &node,int j,char string[],int reps)
{
	if (reps == 0)
	{
		reps++;
		createNode(node,string[j]);
		createNode(node->left,0);
		createNode(node->right,0);
		j++;
		j = formTreeFromPrefixString(node->left,j,string,reps);
		j++;
		j = formTreeFromPrefixString(node->right,j,string,reps);
	}
	else if (isSign(string[j]))
	{
		node->value = string[j];
		createNode(node->left,0);
		createNode(node->right,0);
		j++;
		j = formTreeFromPrefixString(node->left,j,string,reps);
		j++;
		j = formTreeFromPrefixString(node->right,j,string,reps);
	}
	else
	{
			node->value = string[j];
			return j;
	}
}

int calculateSubtree(TreeNode* &node)
{
	if(isSign(node->value))
	{
		return makeOperation(calculateSubtree(node->left),calculateSubtree(node->right),node->value);
	}
	else
		return node->value;
}

int calculateTree(Tree* &tree)
{
	return calculateSubtree(tree->root);
}

void preorderExpression(TreeNode* &node)
{
	if (node != NULL)
	{
		preorderExpression(node->left);
		preorderExpression(node->right);
		printf("%c ",node->value);
	}
	else
		return;
}

void inorderExpression(TreeNode* &node)
{
	if (node != NULL)
	{
		printf("(");
		inorderExpression(node->left);
		printf("%c",node->value);
		inorderExpression(node->right);
		printf(")");
	}
	else
		return;
}