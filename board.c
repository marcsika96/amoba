#include "amoba.h"

void kiir ( Tabla tabla )
{
    int i, j;
    for (i=0; i<tabla.meret; ++i)
    {
        for (j=0; j<tabla.meret; ++j)
        {
            printf("%c", tabla.tomb[i][j]);
        }
        printf("\n");
    }
}

