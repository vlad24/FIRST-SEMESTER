// ¬ прикрепленном файле размер матрицы - 3 х 4 , там несколько седловых точек (4)
#include <stdio.h>
#include <stdlib.h>
void printMatrix(int** matrix,int m,int n)
{
	for (int i = 0 ; i < m ; i++)
	{
		printf("\n");
		for (int j = 0 ; j < n ; j++)
			if ( j != n - 1)
				printf("%d ",matrix[i][j]);
			else
				printf("%d",matrix[i][j]);
	}
}
int** createMatrix(int m,int n)
{
	int** matrix = new int*[m];
	for (int i = 0 ; i < m ; i ++)
		matrix[i] = new int[n];
	return matrix;
}
void initializeMatrixRandomly(int** matrix,int m,int n)
{
	for (int i = 0 ; i < m ; i++)
		for (int j = 0 ; j < n ; j++)
			matrix[i][j] = rand() % 10;
}
void initializeMatrixFromFile(int** matrix,int m,int n,FILE* file)
{
	for (int i = 0 ; i < m ; i++)
		for (int j = 0 ; j < n ; j++)
			fscanf(file,"%d",&matrix[i][j]);
}
void initializePositive(int* matrix,int p)
{
	for (int i = 0 ; i < p ; i++)
			matrix[i] = 32000;
}
void initializeNegative(int* matrix,int p)
{
	for (int i = 0 ; i < p ; i++)
			matrix[i] = -32000;
}

int main()
{
	int m = 0;
	int n = 0;
	printf("A matrix m x n will be created\n");
	printf("Enter m : ");
	scanf("%d",&m);
	printf("Enter n : ");
	scanf("%d",&n);
	int** matrix = createMatrix(m,n);
	initializeMatrixRandomly(matrix,m,n);
	//FILE* file = fopen("matrix.txt","r");
	//initializeMatrixFromFile(matrix,m,n,file);
	printf("The matrix,you've created :");
	printMatrix(matrix, m, n);
	printf("\n");

	int* rowMin = new int[m];
	initializePositive(rowMin,m);
	int* columnMax = new int[n];
	initializeNegative(columnMax, n);

	//Work with rows
	for (int p = 0 ; p < m ; p++)
		for (int q = 0 ; q < n ; q++)
			if (matrix[p][q] <= rowMin[p])
				rowMin[p] = matrix[p][q];
	//Work with columns
	for (int q = 0 ; q < n ; q++)
		for (int p = 0 ; p < m ; p++)
			if (matrix[p][q] >= columnMax[q])
				columnMax[q] = matrix[p][q];
	bool met = false;
	for (int i = 0  ; i < m ; i++)
		for (int j = 0 ; j < n ; j++)
			if (((matrix[i][j] == rowMin[i]) && (matrix[i][j] == columnMax[j])))
			{
				if (!met)
					printf("Coordinates of point(s) :");
				printf("(%d,%d) ",i,j);
				met = true;
			}

		if (!met)
			printf("no points");

	delete[] rowMin;
	delete[] columnMax;
	for (int i = 0; i < m; i++)
		delete[] matrix[i];
	delete[] matrix;
	printf("\n");
	//fclose(file);
	int y = 24;
	scanf("%d", &y);
	return 0;
}