#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include "input.h"
#include "cercaDicotomica.h" //Arxiu amb les cap�aleres de les funcions utilitzades per la cerca dicot�mica

void ferCercaDicotomica()
{
	setlocale(LC_ALL, "");
	/*Creem el vector on buscarem el n�mero*/
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
		/*Si s'ha obert b�, carreguem les dades que hi hagi*/
		size_t final_vec = 0;
		carregarDades(vector, fitxer, &final_vec);

		/*Comprovem si hi havia dades al fitxer*/
		bool buit = comprovarVector(vector);

		/*Si el fitxer estava buit, donem error*/
		if (buit)
		{
			printf("El fitxer est� buit\n");
			system("pause");
		}

		/*Si el fitxer contenia dades, fem la cerca dicot�mica*/
		else
		{
			/*Mostrem el t�tol*/
			printf("----- Cerca Dicot�mica -----\n\n");
			printf("Explicaci�: partint d'un vector amb un m�xim de 100 n�meros, s'indicar� si el n�mero demanat es troba entre ells\n\n");

			/*Demanem el n�mero que es vol buscar*/
			int numero = demanarNum(0,0);

			/*Fem la cerca dicot�mica*/
			size_t num_posicions = 0;
			bool trobat = cercaDicotomica(&num_posicions, vector, numero, 0, final_vec);

			/*Mostrem el n�mero de posicions a les que s'ha accedit*/
			printf("N�mero de posicions a les que s'ha accedit: %u\n", num_posicions);

			/*Informem de si s'ha trobat o no*/
			if (trobat)
			{
				printf("S'ha trobat el n�mero %d a la taula\n", numero);
			}
			else
			{
				printf("No s'ha trobat el n�mero %d a la taula\n", numero);
			}
			system("pause");
		}
	}
}

/*Acci� que carrega les dades del fitxer en un vector*/
void carregarDades(int vect[], FILE* fit, size_t* index)
{
	/*Carreguem les dades del fitxer al vector*/
	fscanf(fit, "%d", &vect[*index]);
	while (!feof(fit) && *index < MAX_VECTOR)
	{
		(*index)++;
		fscanf(fit, "%d", &vect[*index]);
	}

	/*Si el fitxer estava buit, posem un sentinella a la primera posici�*/
	if (*index==0)
	{
		vect[*index] = -1;
	}

	/*Si no ho estava, el col�loquem a la posici� seg�ent*/
	else
	{
		vect[*index + 1] = -1;
	}
}

/*Funci� que comprova si el vector est� buit*/
bool comprovarVector(int vec[])
{
	bool buit = false;

	/*Si el vector t� un -1 en la primera posici�, vol dir que est� buit*/
	if (vec[0]==-1)
	{
		buit = true;
	}
	return(buit);
}

/*Funci� que fa la cerca dicot�mica*/
bool cercaDicotomica(size_t* num_p, int vect[], int num, size_t inici, size_t fi)
{
	/*Cada cop que s'entri al procediment vol dir que s'ha accedit a una nova posici�*/
	(*num_p)++;

	/*Inicialitzem variables*/
	bool trobat;

	/*Si el n�mero que busquem no es troba entre l'inici i el final, ja podem dir que no hi �s*/
	if (num < vect[inici] || num >vect[fi])
	{
		trobat = false;
	}
	else
	{
		/*Calculem la posici� central (arrodonint sempre a l'al�a)*/
		size_t mig = (inici + fi) / 2;

		/*Si el n�mero �s igual al de la posici� central*/
		if (num == vect[mig])
		{
			trobat = true;
		}

		/*Si no l'hem trobat*/
		else
		{
			/*Si el n�mero �s m�s gran que el valor del mig, descarto els valors de l'esquerra i busco a la dreta*/
			if (num > vect[mig])
			{
				trobat = cercaDicotomica(num_p, vect, num, mig + 1, fi);
			}

			/*Si el n�mero �s m�s petit que el valor del mig, descarto els valors de la dreta i busco a l'esquerra*/
			if (num < vect[mig])
			{
				trobat = cercaDicotomica(num_p, vect, num, inici, mig - 1);
			}
		}
	}
	return(trobat);
}