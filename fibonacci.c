#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include "input.h"
#include "fibonacci.h"	/*Arxiu amb les cap�aleres de les funcions utilitzades per la s�rie de fibonacci*/

/*Funci� que fa el c�lcul de la s�rie de Fibonacci*/
void calculFibonacci()
{
	setlocale(LC_ALL, "");

	/*Mostrem el t�tol*/
	printf("----- S�rie de Fibonacci -----\n\n");
	printf("Explicaci�: donat un n�mero, es calcular� el nombre de la s�rie de Fibonacci que ocupa la seva posici�\n\n");
	/*Demanem la posici� de la que es vol calcular el num de Fibonacci*/
	int numero = demanarNum(MIN_FIB,MAX_FIB);

	/*Calculem el n�mero*/
	unsigned int resultat = fibonacci(numero);

	/*Mostrem el resultat*/
	printf("El valor de la s�rie de Fibonacci que es troba en la posici� %u �s: %u\n", numero, resultat);
	system("pause");
}


/*Funic� que calcula el n�mero de la s�rie de fibonacci corresponent a l'�ndex indicat*/
unsigned int fibonacci(unsigned int n)
{
	return(n > 1 ? fibonacci(n-1) + fibonacci(n-2) : n);
}
