#include <stdio.h>
#include <stdlib.h>

void printMatrix(int** matrix, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		printf("\n");
		for (int j = 0; j < n; j++)
			if (j != n - 1)
				printf("%d ", matrix[i][j]);
			else
				printf("%d", matrix[i][j]);
	}
}
int** createMatrix(int m, int n)
{
	int** matrix = new int*[m];
	for (int i = 0; i < m; i++)
		matrix[i] = new int[n];
	return matrix;
}
void initializeMatrixRandomly(int** matrix, int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = rand() % 10;
}
void swapParts(int** matrix, int m, int n)
{
	int mHalf = m / 2;
	int nHalf = n / 2;
	for (int i = 0; i < mHalf; i++)
		for (int j = 0; j < nHalf; j++)
		{
			int temp = matrix[i + mHalf][j + nHalf];
			matrix[i + mHalf][j + nHalf] = matrix[i][j];
			matrix[i][j] = temp;
		}
}
int main()
{
	int m = 0;
	int n = 0;
	printf("A matrix m x n will be created\n");
	printf("Enter even m : ");
	scanf("%d", &m);
	printf("Enter even n : ");
	scanf("%d", &n);

	if ((m > 0) && (n > 0) && ((m % 2) == 0) && ((n % 2) == 0))
	{
		int** matrix = createMatrix(m, n);
		initializeMatrixRandomly(matrix, m, n);
		printf("Your matrix:\n");
		printMatrix(matrix, m, n);
		swapParts(matrix, m, n);
		printf("\n---- New matrix:");
		printMatrix(matrix, m, n);
		for (int i = 0; i < m; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
	else
	{
		printf("error");
	}
	int pause = 0;
	scanf("%d", &pause);
	return 0;
}