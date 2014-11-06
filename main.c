#include <stdio.h>
#include <stdlib.h>
#include "amoba.h"

int main(void)
{
    Tabla tabla;
    tabla.meret=10;
    tabla.tomb = malloc(10*sizeof (char*));
    int k;
    for(k = 0; k < 10; k++){
        tabla.tomb[k] = malloc(10*sizeof (char));
    }

    int  i,j;
    for ( i=0; i<10; ++i)
        for(j=0; j<10; ++j)
        tabla.tomb [i][j]=0;

    tabla.tomb[7][3]=4;
    tabla.tomb[2][8]=3;
    kiir(tabla);
    return 0;
}
