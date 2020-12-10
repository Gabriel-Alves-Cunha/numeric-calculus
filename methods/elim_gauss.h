/* Método de eliminação de Gauss para solução de equações. */

/*  1 1 1 10
	-1 2 1 4   Resp: [4 2 4]
	1 0 1 8
*/

#include "MatrixUtils.h"

void elim_gauss()
{
	float matrix[dim][dim], solvedMatrix[dim]; // Até uma matriz 9X9

	/* Leitura do numero de equações. */
	int numberOfEquations = readNumberOfEquations();

	/* Leitura dos termos das equações. */
	readMyEquations(matrix, numberOfEquations);

	/* Mostra a matriz original. */
	showMatrix(matrix, numberOfEquations);

	/* Processo de triangularização da matriz. */
	triangulateMatrix(matrix, numberOfEquations);

	/* Mostra a matriz modificada. */
	showTriangulatedMatrix(matrix, numberOfEquations);

	/* PAUSA */
	pause();

	/* Determinação da solução das equações. */
	solveMatrix(matrix, solvedMatrix, numberOfEquations);

	/* Saída de Resultados. */
	showResults(solvedMatrix, numberOfEquations);

	/* PAUSA */
	pause();
}
