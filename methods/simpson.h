/* Programa simpson.cpp
Integracao numerica pela regra de Simpson 1/3
Forneça a funcao f(x) na function f
*/

#include <stdio.h>
#include <math.h>
#include <conio.h>

#define NMAX 10000 // Numero maximo de sub-intervalos de integracao

float function(float x)
{
	float fx;
	fx = exp(2 * x); // usar intervalo [0,1] [0,2] [0,3] [0,4]
	//fx = 2 + 2 * x - x * x;
	return(fx);
}

void simpson()
{
	float function(float);
	int i;
	int nint = 4;  /* Inicia com quatro sub-intervalos */
	float a, b, h, simpson;
	float x, somapar, somaimpar;
	float erro = 1;      /* Inicia com erro unitario */
	float eps = 1.0E-6;  /* Precisao de seis casa decimais */
	printf("\nLimite inferior a = ");
	scanf_s("%f", &a);
	printf("Limite superior b = ");
	scanf_s("%f", &b);
	float anterior = 1E6;   /* Resultado inicial bem diferente da solucao */

	while (erro > eps)
	{
		somapar = 0;
		somaimpar = 0;
		h = (b - a) / (2 * nint);
		for (i = 1; i <= nint - 1; ++i)
		{
			x = a + h * 2 * i;
			somapar = somapar + function(x);
		}

		for (i = 1; i <= nint; ++i)
		{
			x = a + h * (2 * i - 1);
			somaimpar = somaimpar + function(x);
		}

		simpson = h / 3 * (function(a) + function(b) + 2 * somapar + 4 * somaimpar);
		erro = fabs(simpson - anterior);
		printf("Erro = %f com %d sub-intervalos\n", erro, nint);

		if (nint > NMAX)
		{
			printf("\nO calculo excedeu o numero maximo de sub-intervalos (10.000).\nExecucao interrompida.\n");
			break;
		}

		anterior = simpson;
		nint = nint * 2;
	}

	printf("\nIntegral pela regra de Simpson = %f com %d sub-intervalos de integracao\n", simpson, nint / 2);
	printf("\nExecucao do programa concluida. Tecle <ENTER> para encerrar\n");

	_getch();
}
