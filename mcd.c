#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include "input.h"
#include "mcd.h"	//Arxiu amb les capçaleres pel càlcul del mcd

void calculMcd()
{
	setlocale(LC_ALL, "");

	/*Mostrem el títol*/
	printf("----- Càlcul MCD -----\n\n");
	printf("Explicació: es calcularà el màxim comú divisor de dos números\n\n");

	/*Demanem els números*/
	printf("--> Primer valor\n");
	int numero1 = demanarNum(0,0);
	numero1 = convertirNatural(numero1);
	printf("--> Segon valor\n");
	int numero2 = demanarNum(0,0);
	numero2 = convertirNatural(numero2);

	/*Si el primer número és més gran, els intercanviem*/
	masGrande(&numero1, &numero2);
	
	/*Calculem el MCD*/
	int resultat = mcd(numero1, numero2);

	/*Mostrem el resultat*/
	printf("El MCD de %d i %d és %d\n", numero1, numero2, resultat);
	system("pause");
}

/*Acció que intercanvia dos nombre si el primer és més gran que el segon*/
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
