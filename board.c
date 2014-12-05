#include "amoba.h"
void uj_jatek (int meret)
{
    Tabla tabla;
    int i, j;
    for (i=0; i<tabla.meret; i++)
    {
        for (j=0; j<tabla.meret; j++)
        {
            tabla.tomb [i][j]=' ';
        }
    }
    do
    {
        kiir (tabla);
        rakas(&tabla);
    }
    while (win(tabla)==0);


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

