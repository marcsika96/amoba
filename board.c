#include "amoba.h"
#include <stdio.h>

void mentes(Tabla* tabla){

	FILE* ofile = fopen("text.txt", "w");

	fprintf(ofile, "%d\n", tabla->meret);

	int i, j;
	for (i = 0; i < tabla->meret; i++)
	{
		for (j = 0; j < tabla->meret; j++){
			fprintf(ofile, "%c", tabla->tomb[i][j] == ' ' ? '.' : tabla->tomb[i][j]);
		}
		fprintf(ofile, "\n");
	}

	fclose(ofile);
}

Tabla uj_jatek()
{
	int meret;
	printf("Mekkora legyen a tabla?\n");
	scanf("%d", &meret);

	Tabla tabla;
	tabla.meret = meret;

	tabla.tomb = malloc((tabla.meret + 1)*sizeof (char*));
	int k;
	for (k = 0; k < (tabla.meret + 1); k++)
	{
		tabla.tomb[k] = malloc((tabla.meret + 1)*sizeof (char));
	}

	int i, j;
	for (i = 0; i < tabla.meret; i++)
	{
		for (j = 0; j < tabla.meret; j++)
		{
			tabla.tomb[i][j] = ' ';
		}
	}

	return tabla;

}

void jatek(Tabla tabla){
    do
    {
        kiir (tabla);
        rakas(&tabla);
		kiir(tabla);
		robot(&tabla);

		// Most mindig mentunk
		mentes(&tabla);
    }
    while (win(&tabla)==0);

	free(tabla.tomb);
}
void rakas (Tabla *tabla)
{
    printf("Hova lepsz?\n");
    int i, j;
    do
    {
        scanf("%d %d", &i, &j);
        if (tabla->tomb [i][j]!=' ')
        {
            printf("Ide mar nem rakhatsz");
        }
    }
    while (tabla->tomb[i][j]!=' ');
    tabla->tomb[i][j]='x';
}
void kiir ( Tabla tabla )
{
    int i, j;
    for (j=0; j<tabla.meret+1; j++)
    {
        if (j-1>=0)
        {
            printf("%d", j-1);
        }
        else
        {
            printf("*");
        }
    }
    printf("\n");
    for (i=0; i<tabla.meret; ++i)
    {
        printf("%d", i);
        for (j=0; j<tabla.meret; ++j)
        {
            printf("%c", tabla.tomb[i][j]);
        }
        printf("\n");
    }
}

