#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include "input.h"
#include "sumaDigital.h"	//Arxiu amb les cap�aleres per fer la suma digital

void sumaDigital()
{
	setlocale(LC_ALL, "");

	/*Mostrem el t�tol*/
	printf("----- Suma Digital -----\n\n");
	printf("Explicaci�: donat un n�mero, es far� la suma de les seves xifres\n\n");

	/*Demanem el n�mero del que es vol fer la suma digital*/
	int num = demanarNum(0,0);
	num = convertirNatural(num);

	/*Fem la suma digital*/
	int suma = 0;
	suma = sumaDig(num, suma);

	/*Mostrem el resultat*/
	printf("La suma digital de %u �s: %u\n", num, suma);
	system("pause");
}

int sumaDig(int numero, int sum)
{
	return (numero == 0 ? sum : sumaDig((numero - (numero % 10)) / 10, sum + numero % 10));
}

void arrelDigital()
{
	setlocale(LC_ALL, "");

	/*Mostrem el t�tol*/
	printf("----- Arrel Digital -----\n\n");
	printf("Explicaci�: donat un n�mero, es far� la suma digital fins que nom�s quedi una xifra\n\n");

	/*Demanem el n�mero del que es vol fer l'arrel digital*/
	int num = demanarNum(0,0);
	num = convertirNatural(num);

	/*Calculem l'arrel*/
	int sum = 0;
	int resultat = arrel(num, sum);

	/*Mostrem el resultat*/
	printf("L'arrel digital de %u �s: %d\n", num, resultat);
	system("pause");
}

int arrel(int valor, int suma)
{
	int resultat = sumaDig(valor, suma);
	return(valor < 10 ? resultat: arrel(resultat, suma));
}