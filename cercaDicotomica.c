#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include "input.h"
#include "cercaDicotomica.h" //Arxiu amb les capçaleres de les funcions utilitzades per la cerca dicotòmica

void ferCercaDicotomica()
{
	setlocale(LC_ALL, "");
	/*Creem el vector on buscarem el número*/
	int vector[MAX_VECTOR];

	/*Carreguem les dades del vector des d'un fitxer*/
	FILE* fitxer = fopen("vector.txt", "r");

	/*Comprovem que el fitxer s'ha obert correctament*/
	if (fitxer == NULL)
	{
		printf("Error, no s'ha pogut obrir el fitxer amb el vector\n");
		system("pause");
	}
	else
	{
		/*Si s'ha obert bé, carreguem les dades que hi hagi*/
		size_t final_vec = 0;
		carregarDades(vector, fitxer, &final_vec);

		/*Comprovem si hi havia dades al fitxer*/
		bool buit = comprovarVector(vector);

		/*Si el fitxer estava buit, donem error*/
		if (buit)
		{
			printf("El fitxer està buit\n");
			system("pause");
		}

		/*Si el fitxer contenia dades, fem la cerca dicotòmica*/
		else
		{
			/*Mostrem el títol*/
			printf("----- Cerca Dicotòmica -----\n\n");
			printf("Explicació: partint d'un vector amb un màxim de 100 números, s'indicarà si el número demanat es troba entre ells\n\n");

			/*Demanem el número que es vol buscar*/
			int numero = demanarNum(0,0);

			/*Fem la cerca dicotòmica*/
			size_t num_posicions = 0;
			bool trobat = cercaDicotomica(&num_posicions, vector, numero, 0, final_vec);

			/*Mostrem el número de posicions a les que s'ha accedit*/
			printf("Número de posicions a les que s'ha accedit: %u\n", num_posicions);

			/*Informem de si s'ha trobat o no*/
			if (trobat)
			{
				printf("S'ha trobat el número %d a la taula\n", numero);
			}
			else
			{
				printf("No s'ha trobat el número %d a la taula\n", numero);
			}
			system("pause");
		}
	}
}

/*Acció que carrega les dades del fitxer en un vector*/
void carregarDades(int vect[], FILE* fit, size_t* index)
{
	/*Carreguem les dades del fitxer al vector*/
	fscanf(fit, "%d", &vect[*index]);
	while (!feof(fit) && *index < MAX_VECTOR)
	{
		(*index)++;
		fscanf(fit, "%d", &vect[*index]);
	}

	/*Si el fitxer estava buit, posem un sentinella a la primera posició*/
	if (*index==0)
	{
		vect[*index] = -1;
	}

	/*Si no ho estava, el col·loquem a la posició següent*/
	else
	{
		vect[*index + 1] = -1;
	}
}

/*Funció que comprova si el vector està buit*/
bool comprovarVector(int vec[])
{
	bool buit = false;

	/*Si el vector té un -1 en la primera posició, vol dir que està buit*/
	if (vec[0]==-1)
	{
		buit = true;
	}
	return(buit);
}

/*Funció que fa la cerca dicotòmica*/
bool cercaDicotomica(size_t* num_p, int vect[], int num, size_t inici, size_t fi)
{
	/*Cada cop que s'entri al procediment vol dir que s'ha accedit a una nova posició*/
	(*num_p)++;

	/*Inicialitzem variables*/
	bool trobat;

	/*Si el número que busquem no es troba entre l'inici i el final, ja podem dir que no hi és*/
	if (num < vect[inici] || num >vect[fi])
	{
		trobat = false;
	}
	else
	{
		/*Calculem la posició central (arrodonint sempre a l'alça)*/
		size_t mig = (inici + fi) / 2;

		/*Si el número és igual al de la posició central*/
		if (num == vect[mig])
		{
			trobat = true;
		}

		/*Si no l'hem trobat*/
		else
		{
			/*Si el número és més gran que el valor del mig, descarto els valors de l'esquerra i busco a la dreta*/
			if (num > vect[mig])
			{
				trobat = cercaDicotomica(num_p, vect, num, mig + 1, fi);
			}

			/*Si el número és més petit que el valor del mig, descarto els valors de la dreta i busco a l'esquerra*/
			if (num < vect[mig])
			{
				trobat = cercaDicotomica(num_p, vect, num, inici, mig - 1);
			}
		}
	}
	return(trobat);
}