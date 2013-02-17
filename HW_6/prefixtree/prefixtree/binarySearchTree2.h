#pragma once
struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
};

struct Tree
{
	TreeNode* root;
};

Tree* createTree();
void createNode(TreeNode* &node,int value);

bool exsistsInTree(Tree* tree,int value);

TreeNode* searchInTree(Tree* &tree,int value);

void addToTree(Tree* &tree,int value);

void removeFromTree(Tree* tree,int value);

void treePreorder(Tree* &tree);
void treeInorder(Tree* &tree);
void treeSpecialInorder(Tree* &tree);

void deleteTree(Tree* &tree);

int formTreeFromPrefixString(TreeNode* &node,int j,char string[],int reps);
int calculateTree(Tree* &tree);

void preorderExpression(TreeNode* &node);
void inorderExpression(TreeNode* &node);

