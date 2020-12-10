/* M�todo de elimina��o de Gauss para solu��o de equa��es. */

/*  1 1 1 10
	-1 2 1 4   Resp: [4 2 4]
	1 0 1 8
*/

#include "MatrixUtils.h"

void elim_gauss()
{
	float matrix[dim][dim], solvedMatrix[dim]; // At� uma matriz 9X9

	/* Leitura do numero de equa��es. */
	int numberOfEquations = readNumberOfEquations();

	/* Leitura dos termos das equa��es. */
	readMyEquations(matrix, numberOfEquations);

	/* Mostra a matriz original. */
	showMatrix(matrix, numberOfEquations);

	/* Processo de triangulariza��o da matriz. */
	triangulateMatrix(matrix, numberOfEquations);

	/* Mostra a matriz modificada. */
	showTriangulatedMatrix(matrix, numberOfEquations);

	/* PAUSA */
	pause();

	/* Determina��o da solu��o das equa��es. */
	solveMatrix(matrix, solvedMatrix, numberOfEquations);

	/* Sa�da de Resultados. */
	showResults(solvedMatrix, numberOfEquations);

	/* PAUSA */
	pause();
}
