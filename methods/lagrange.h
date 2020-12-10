#pragma once

/* Calcula o valor de um ponto por Interpolação usando Lagrange
1.3 3.669
1.4 4.055
1.5 4.482

1.32 = 7.7429
*/

#include<stdio.h>
#include<math.h>
#include<conio.h>

main()
{
	int i, j, n;
	float x[20], y[20], u, p, p1, sum;
	printf("Digite o numero de pontos: n = ");
	scanf_s("%d", &n);
	printf("\nDigite o valor do ponto a ser calculado: u = ");
	scanf_s("%f", &u);

	for (i = 0; i < n; ++i)
	{
		printf("x[%d]:", i + 1);
		scanf_s("%f", &x[i]);
		printf("y[%d]:", i + 1);
		scanf_s("%f", &y[i]);
	}
	p = 1;

	for (i = 0; i < n; ++i)
		p = p * (u - x[i]);

	sum = 0;

	for (i = 0; i < n; ++i)
	{
		p1 = y[i] / (u - x[i]);
		for (j = 0; j < n; ++j)
			if (i != j)
				p1 = p1 / (x[i] - x[j]);
		sum += p1;
	}
	p = p * sum;

	for (i = 0; i < n; i++)
		printf("%8.4f\t %f\n", x[i], y[i]);

	printf("O valor do ponto u=%f eh %8.4f\n", u, p);
	_getch();
}
