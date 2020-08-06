#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include "input.h"
#include "factorial.h"

void calculFactorial()
{
	setlocale(LC_ALL, "");

	/*Mostrem el títol*/
	printf("----- Càlcul del Factorial -----\n\n");
	printf("Explicació: donat un número, es calcularà el seu factorial\n\n");

	/*Demanem la posició de la que es vol calcular el factorial*/
	int num = demanarNum(MIN_FACTORIAL, MAX_FACTORIAL);
	
	/*Calculem el factorial*/
	unsigned int numero = num;
	unsigned int resultat = factorial(numero);

	/*Mostrem el resultat*/
	printf("El factorial de %d és: %u\n", numero, resultat);
	system("pause");
}

unsigned int factorial(unsigned int num)
{
	return (num > 1 ? num * factorial(num-1) : 1);
}
