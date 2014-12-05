#include <stdio.h>
#include <stdlib.h>

void menu ()
{
    int valasztas;
    do
    {
        printf("1. Uj jatek\n");
        printf("2. Jatek betoltese\n");
        printf("0. Kilepes\n");
        scanf("%d", &valasztas);
        switch(valasztas)
        {
        case 1:
            uj_jatek();
            break;
//        case 2:
//            betoltes();
//            break;
        }
    }
    while(valasztas!=0);
    return 0;
}

