#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include "input.h"
#include "fibonacci.h"	/*Arxiu amb les capçaleres de les funcions utilitzades per la sèrie de fibonacci*/

/*Funció que fa el càlcul de la sèrie de Fibonacci*/
void calculFibonacci()
{
	setlocale(LC_ALL, "");

	/*Mostrem el títol*/
	printf("----- Sèrie de Fibonacci -----\n\n");
	printf("Explicació: donat un número, es calcularà el nombre de la sèrie de Fibonacci que ocupa la seva posició\n\n");
	/*Demanem la posició de la que es vol calcular el num de Fibonacci*/
	int numero = demanarNum(MIN_FIB,MAX_FIB);

	/*Calculem el número*/
	unsigned int resultat = fibonacci(numero);

	/*Mostrem el resultat*/
	printf("El valor de la sèrie de Fibonacci que es troba en la posició %u és: %u\n", numero, resultat);
	system("pause");
}


/*Funicó que calcula el número de la sèrie de fibonacci corresponent a l'índex indicat*/
unsigned int fibonacci(unsigned int n)
{
	return(n > 1 ? fibonacci(n-1) + fibonacci(n-2) : n);
}
