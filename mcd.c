#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include "input.h"
#include "mcd.h"	//Arxiu amb les cap�aleres pel c�lcul del mcd

void calculMcd()
{
	setlocale(LC_ALL, "");

	/*Mostrem el t�tol*/
	printf("----- C�lcul MCD -----\n\n");
	printf("Explicaci�: es calcular� el m�xim com� divisor de dos n�meros\n\n");

	/*Demanem els n�meros*/
	printf("--> Primer valor\n");
	int numero1 = demanarNum(0,0);
	numero1 = convertirNatural(numero1);
	printf("--> Segon valor\n");
	int numero2 = demanarNum(0,0);
	numero2 = convertirNatural(numero2);

	/*Si el primer n�mero �s m�s gran, els intercanviem*/
	masGrande(&numero1, &numero2);
	
	/*Calculem el MCD*/
	int resultat = mcd(numero1, numero2);

	/*Mostrem el resultat*/
	printf("El MCD de %d i %d �s %d\n", numero1, numero2, resultat);
	system("pause");
}

/*Acci� que intercanvia dos nombre si el primer �s m�s gran que el segon*/
void masGrande(int* a, int* b)
{
	if (a < b)
	{
		int c = a;
		a = b;
		b = c;
	}
}

int mcd(int a, int b)
{
	return (b == 0 ? a : mcd(b, a % b));
}
