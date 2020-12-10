#pragma once

#define dim 9
//const int dim = 9;

int readNumberOfEquations()
{
	int n;
	printf("Entre com o numero de equacoes: ");
	scanf_s("%d", &n);
	return n;
}

void readMyEquations(float matrix[dim][dim], const int numberOfEquations)
{
	float temp;
	int j;
	for (int i = 1; i <= numberOfEquations; ++i)
	{
		printf("Linha %d:\n", i);

		for (j = 1; j <= numberOfEquations; ++j)
		{
			printf("Forneca o termo de X%d: ", j);
			scanf_s("%f", &temp);
			matrix[i][j] = temp;
		}

		printf("O valor de b%d eh: ", i);
		scanf_s("%f", &temp);
		matrix[i][j] = temp;
	}
}

void showMatrix(const float matrix[dim][dim], const int numberOfEquations)
{
	printf("\n\nMatriz original:\n");

	for (int i = 1; i <= numberOfEquations; ++i)
	{
		for (int j = 1; j <= numberOfEquations + 1; ++j)
			printf("%+8.2f", matrix[i][j]);

		printf("\n");
	}
}

void triangulateMatrix(float matrix[dim][dim], const int numberOfEquations)
{
	float temp;
	for (int k = 1; k < numberOfEquations; ++k)
		for (int i = k + 1; i <= numberOfEquations; ++i)
		{
			temp = (-1.0) * matrix[i][k] / matrix[k][k];

			for (int j = 1; j <= numberOfEquations + 1; ++j)
				matrix[i][j] = (temp * matrix[k][j]) + matrix[i][j];
		}
}

void showTriangulatedMatrix(const float matrix[dim][dim], const int numberOfEquations)
{
	printf("\n\nMatriz modificada:\n");

	for (int i = 1; i <= numberOfEquations; ++i)
	{
		for (int j = 1; j <= numberOfEquations + 1; ++j)
			printf("%+8.2f", matrix[i][j]);

		printf("\n");
	}
}

void solveMatrix(float matrix[dim][dim], float solvedMatrix[dim], const int numberOfEquations)
{
	for (int i = numberOfEquations; i >= 0; --i)
	{
		solvedMatrix[i] = matrix[i][numberOfEquations + 1];

		for (int j = numberOfEquations; j > i; --j)
			solvedMatrix[i] -= solvedMatrix[j] * matrix[i][j];

		solvedMatrix[i] = solvedMatrix[i] / matrix[i][i];
	}
}

void showResults(const float solvedMatrix[dim], const int numberOfEquations)
{
	for (int i = 1; i <= numberOfEquations; ++i)
		printf("\nX[%d]=%+8.2f", i, solvedMatrix[i]);
}

void pause()
{
	char pausa = '\0';
	do { pausa = _getch(); } while (pausa == '\0');
}

