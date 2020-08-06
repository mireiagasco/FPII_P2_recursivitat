#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include "input.h"
#include "sumaDigital.h"	//Arxiu amb les capçaleres per fer la suma digital

void sumaDigital()
{
	setlocale(LC_ALL, "");

	/*Mostrem el títol*/
	printf("----- Suma Digital -----\n\n");
	printf("Explicació: donat un número, es farà la suma de les seves xifres\n\n");

	/*Demanem el número del que es vol fer la suma digital*/
	int num = demanarNum(0,0);
	num = convertirNatural(num);

	/*Fem la suma digital*/
	int suma = 0;
	suma = sumaDig(num, suma);

	/*Mostrem el resultat*/
	printf("La suma digital de %u és: %u\n", num, suma);
	system("pause");
}

int sumaDig(int numero, int sum)
{
	return (numero == 0 ? sum : sumaDig((numero - (numero % 10)) / 10, sum + numero % 10));
}

void arrelDigital()
{
	setlocale(LC_ALL, "");

	/*Mostrem el títol*/
	printf("----- Arrel Digital -----\n\n");
	printf("Explicació: donat un número, es farà la suma digital fins que només quedi una xifra\n\n");

	/*Demanem el número del que es vol fer l'arrel digital*/
	int num = demanarNum(0,0);
	num = convertirNatural(num);

	/*Calculem l'arrel*/
	int sum = 0;
	int resultat = arrel(num, sum);

	/*Mostrem el resultat*/
	printf("L'arrel digital de %u és: %d\n", num, resultat);
	system("pause");
}

int arrel(int valor, int suma)
{
	int resultat = sumaDig(valor, suma);
	return(valor < 10 ? resultat: arrel(resultat, suma));
}