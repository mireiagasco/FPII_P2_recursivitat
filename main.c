#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include "input.h"	//Arxiu amb les capçaleres de les funcions que demanen dades a l'usuari
#include "fibonacci.h"	//Arxiu amb les capçaleres de les funcions utilitzades per la sèrie de fibonacci
#include "factorial.h"	//Arxiu amb les capçaleres pel càlcul del factorial
#include "hanoi.h"	//Arxiu amb les capçaleres de les torres de hanoi
#include "mcd.h"	//Arxiu amb les capçaleres pel càlcul del mcd
#include "sumaDigital.h"	//Arxiu amb les capçaleres per fer la suma digital


int main()
{
	setlocale(LC_ALL, "");

	/*Declarem les variables que ens permetran saber quina opció tria l'usuari i saber si es vol continuar i les inicialitzem a valor
	impossible (en el cas de l'opció) i a true en el cas de continuar, per fer que entri al bucle*/
	char opcio = 'a';
	bool continuar = true;

	/*El bucle es repetirà, mostrant el menú, fins que l'usuari digui que vol sortir*/
	while (continuar)
	{
		system("cls");
		mostrarMenu();
		opcio = demanarOpcio();
		system("cls");
		switch (opcio)
		{

		case '0':
			continuar = false;
			break;
		case '1': 
			calculFactorial();
			break;
		case '2':
			calculFibonacci();
			break;
		case '3':
			calculMcd();
			break;
		case '4':
			torresDeHanoi();
			break;
		case '5':
			ferCercaDicotomica();
			break;
		case '6':
			sumaDigital();
			break;
		case '7':
			arrelDigital();
			break;
		default:
			printf("Valor no vàlid, indiqui un número entre 0 i 7\n");
			system("pause");
		}
	}
	return 0;
}