#include <stdio.h>
#include <stdlib.h>
#include "amoba.h"


int main(void)
{
    //int meret;
    //printf("Mekkora legyen a tabla?\n");
    //scanf("%d", &meret);

//    Tabla tabla;
//    scanf("%d", &tabla.meret);
//    tabla.tomb = malloc((tabla.meret+1)*sizeof (char*));
//    int k;
//    for(k = 0; k < (tabla.meret+1); k++)
//    {
//        tabla.tomb[k] = malloc((tabla.meret+1)*sizeof (char));
//    }


    //Tabla tabla = uj_jatek ();
	Tabla tabla = betoltes();
	jatek(tabla);

    return 0;
}
