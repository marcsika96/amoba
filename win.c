#include "amoba.h"

int win (Tabla tabla)
{
    int x;
    int y;
    for (x=0; x<tabla.meret; x++)
    {
        for (y=0; y<tabla.meret; y++)
        {
            if (tabla.tomb [x][y]=='x' && tabla.tomb [x][y+1]=='x' && tabla.tomb [x][y+2]=='x' && tabla.tomb [x][y+3]=='x' && tabla.tomb [x][y+4]=='x'
                                  ||
                                  tabla.tomb [x][y]=='x' && tabla.tomb [x+1][y+1]=='x' && tabla.tomb [x+2][y+2]=='x' && tabla.tomb [x+3][y+3]=='x' && tabla.tomb [x+4][y+4]=='x'
                                                    ||
                                                    tabla.tomb [x][y]=='x' && tabla.tomb [x+1][y]=='x' && tabla.tomb [x+2][y]=='x' && tabla.tomb [x+3][y]=='x' && tabla.tomb [x+4][y]=='x'
                                                            ||
                                                            tabla.tomb [x+4][y]=='x' && tabla.tomb [x+3][y+1]=='x' && tabla.tomb [x+2][y+2]=='x' && tabla.tomb [x+2][y+3]=='x' && tabla.tomb [x][y+4]=='x')
            {
                printf("Nyertél!! :D");
                return 1;
            }
            else if (tabla.tomb [x][y]=='o' && tabla.tomb [x][y+1]=='o' && tabla.tomb [x][y+2]=='o' && tabla.tomb [x][y+3]=='o' && tabla.tomb [x][y+4]=='o'
                                       ||
                                       tabla.tomb [x][y]=='o' && tabla.tomb [x+1][y+1]=='o' && tabla.tomb [x+2][y+2]=='o' && tabla.tomb [x+3][y+3]=='o' && tabla.tomb [x+4][y+4]=='o'
                                               ||
                                               tabla.tomb [x][y]=='o' && tabla.tomb [x+1][y]=='o' && tabla.tomb [x+2][y]=='o' && tabla.tomb [x+3][y]=='o' && tabla.tomb [x+4][y]=='o'
                                                       ||
                                                       tabla.tomb [x+4][y]=='o' && tabla.tomb [x+3][y+1]=='o' && tabla.tomb [x+2][y+2]=='o' && tabla.tomb [x+2][y+3]=='o' && tabla.tomb [x][y+4]=='o')
            {
                printf("Vesztettél!! ");
                return 1;
            }
        }
    }
    return 0;
}
