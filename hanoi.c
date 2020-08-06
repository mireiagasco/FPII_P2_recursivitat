#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include "hanoi.h"	//Arxiu amb les capçaleres de les funcions de les torres de hanoi
#include "input.h"	//Arxiu amb les capçaleres de les funcions que demanen dades a l'usuari

void torresDeHanoi()
{
	setlocale(LC_ALL, "");

	/*Mostrem el títol*/
	printf("----- Torres de Hanoi -----\n\n");
	printf("Explicació: es parteix d'un nombre determinat de discs en la primera torre (A) i es donaran indicacions sobre com s'han de moure els discs per arribar a tenir-los tots en la última torre (C) amb la condició que no poden haver-hi discs grans sobre petits i que només es pot moure un disc cada cop\n\n");

	/*Demanem la posició de la que es vol calcular el factorial*/
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

/*Funció que indica els passos que cal fer*/
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