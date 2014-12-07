#include <stdio.h>
#include <stdlib.h>
#include "amoba.h"

Tabla betoltes()
{

	FILE* ifile = fopen("text.txt", "r");

	Tabla tabla;
	fscanf(ifile, "%d", &tabla.meret);

	tabla.tomb = malloc((tabla.meret + 1)*sizeof (char*));
	int k;
	for (k = 0; k < (tabla.meret + 1); k++)
	{
		tabla.tomb[k] = malloc((tabla.meret + 1)*sizeof (char));
	}

	char buffer[256];

	int i, j;
	for (i = 0; i < tabla.meret; i++)
	{

		fscanf(ifile, "%s", buffer);

		for (j = 0; j < tabla.meret; j++)
		{
			tabla.tomb[i][j] = (buffer[j] == '.') ? ' ' : buffer[j];
		}
	}

	fclose(ifile);

	return tabla;
}

void menu ()
{
    int valasztas;
    Tabla tabla;
    do
    {
        printf("1. Uj jatek\n");
        printf("2. Jatek betoltese\n");
        printf("0. Kilepes\n");
        scanf("%d", &valasztas);
        switch(valasztas)
        {
        case 1:
            tabla = uj_jatek();
            break;
        case 2:
            tabla = betoltes();
            break;
        }
        jatek(tabla);
    }
    while(valasztas==0);

}

