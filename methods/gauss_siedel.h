/* Método Iterativo de Gauss-Siedes para solução de equações. ANSI-C
	1 1 1 10
	-1 2 1 4	[4 2 4]
	1 0 1 8
*/

#include "MatrixUtils.h"

#define MAX 50  // Numero maximo de iteracoes

void solve(float matrix[dim][dim])
{
	float x1 = 0, x2 = 0, x3 = 0, x4 = 0;

	for (int i = 1; i <= MAX; ++i)
	{
		x1 = (matrix[1][2] - x2 /*- x3*/) / matrix[1][1];
		x2 = (matrix[2][2] - x1 /*- x3*/) / matrix[2][2];
		//x3 = (matrix[3][4] - x1) / matrix[3][3];
		printf("%d  x1 = %10.6f   x2 = %10.6f \n", i, x1, x2);
		//  x3 = %10.6f
		_getch();
	}
}

void gauss_siedel()
{
	float matrix[dim][dim] = { 0 }; // Até uma matriz 9X9

	int numberOfEquations = readNumberOfEquations();

	readMyEquations(matrix, numberOfEquations);

	showMatrix(matrix, numberOfEquations);

	solve(matrix);
}
