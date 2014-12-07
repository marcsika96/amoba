#include "amoba.h"

int win (Tabla *tabla)
{
    int a, b, c, d;
    int i, j;
    for (i = 0; i < tabla->meret; i++)
    {
        for (j = 0; j < tabla->meret; j++)
        {
            if (tabla->tomb[i][j] != ' ')
            {

                // Vizszintesen
                for (a = 1; a < 5 && i + a < tabla->meret; a++)
                {
                    if (tabla->tomb[i + a][j] != tabla->tomb[i][j])
                    {
                        break;
                    }
                }

                // Fuggolegesen
                for (b = 1; b < 5 && j + b < tabla->meret; b++)
                {
                    if (tabla->tomb[i][j + b] != tabla->tomb[i][j])
                    {
                        break;
                    }
                }

                // Atlosan
                for (c = 1; c < 5 && i + c < tabla->meret && j + c < tabla->meret; c++)
                {
                    if (tabla->tomb[i + c][j + c] != tabla->tomb[i][j])
                    {
                        break;
                    }
                }

                // Atlosan felfele
                for (d = 1; d < 5 && i + d < tabla->meret && j - d >= 0; d++)
                {
                    if (tabla->tomb[i + d][j - d] != tabla->tomb[i][j])
                    {
                        break;
                    }


                }
            }

        }
    }
    if (a==5 || b==5 || c==5 || d==5)
    {
        printf("A jateknak vege");
        return 1;
    }
    return 0;
}
