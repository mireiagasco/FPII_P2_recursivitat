#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include "hanoi.h"	//Arxiu amb les cap�aleres de les funcions de les torres de hanoi
#include "input.h"	//Arxiu amb les cap�aleres de les funcions que demanen dades a l'usuari

void torresDeHanoi()
{
	setlocale(LC_ALL, "");

	/*Mostrem el t�tol*/
	printf("----- Torres de Hanoi -----\n\n");
	printf("Explicaci�: es parteix d'un nombre determinat de discs en la primera torre (A) i es donaran indicacions sobre com s'han de moure els discs per arribar a tenir-los tots en la �ltima torre (C) amb la condici� que no poden haver-hi discs grans sobre petits i que nom�s es pot moure un disc cada cop\n\n");

	/*Demanem la posici� de la que es vol calcular el factorial*/
	printf("Quants discs vols? ");
	int num = demanarNum(MIN_DISCS, MAX_DISCS);

	/*Donem nom a les torres*/
	char torreA = 'A';
	char torreB = 'B';
	char torreC = 'C';

	/*Comencem el joc*/
	torre(num, torreA, torreB, torreC);
	system("pause");
}

/*Funci� que indica els passos que cal fer*/
void torre(int discos, char origen, char aux, char destino) {
	if (discos == 1)
	{
		printf("Mou el disc %d de la vareta %c a la vareta %c\n", discos, origen, destino);
	}
	else
	{
		torre(discos - 1, origen, destino, aux);
		printf("Mou el disc %d de la vareta %c a la vareta %c\n", discos, origen, destino);
		torre(discos - 1, aux, origen, destino);
	}
}