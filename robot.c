#include "amoba.h"

void robot(Tabla *tabla){

	printf("Pont most: %d\n", pontoz(tabla));
	int elerheto = valaszt(tabla, 0, 0);
	printf("Elerheto: %d\n", elerheto);
}

int pontozCella(Tabla* tabla, int i, int j){
	int a, b, c, d;

	// Vizszintesen
	for (a = 1; a < 5 && i + a < tabla->meret; a++){
		if (tabla->tomb[i + a][j] != tabla->tomb[i][j]){
			break;
		}
	}

	// Fuggolegesen
	for (b = 1; b < 5 && j + b < tabla->meret; b++){
		if (tabla->tomb[i][j + b] != tabla->tomb[i][j]){
			break;
		}
	}

	// Atlosan
	for (c = 1; c < 5 && i + c < tabla->meret && j + c < tabla->meret; c++){
		if (tabla->tomb[i + c][j + c] != tabla->tomb[i][j]){
			break;
		}
	}

	// Atlosan felfele
	for (d = 1; d < 5 && i + d < tabla->meret && j - d >= 0; d++){
		if (tabla->tomb[i + d][j - d] != tabla->tomb[i][j]){
			break;
		}
	}

	int pont = 0;

	if (a >= 2){
		pont += (1 << 4*(a-1));
	}

	if (b >= 2){
		pont += (1 << 4*(b-1));
	}

	if (c >= 2){
		pont += (1 << 4*(c-1));
	}

	if (d >= 2){
		pont += (1 << 4*(d-1));
	}

	return (tabla->tomb[i][j] == 'x') ? pont : -pont;
}

int pontoz(Tabla *tabla){
	int pont = 0;
	int i, j;
	for (i = 0; i < tabla->meret; i++){
		for (j = 0; j < tabla->meret; j++){
			if (tabla->tomb[i][j] != ' '){
				pont += pontozCella(tabla, i, j);
			}
		}
	}

	for (i = tabla->meret/2-1; i < tabla->meret/2+1; i++){
		for (j = tabla->meret / 2 - 1; j < tabla->meret / 2 + 1; j++){
			if (tabla->tomb[i][j] == 'x'){
				pont++;
			}
			if (tabla->tomb[i][j] == 'o'){
				pont--;
			}
		}
	}

	return pont;
}

int nincsSzomszed(Tabla* tabla, int x, int y){

	int i, j;
	for (i = x - 1; i <= x + 1; i++){
		for (j = y - 1; j <= y + 1; j++){
			if (i >= 0 && i < tabla->meret && j >= 0 && j < tabla->meret){
				if (tabla->tomb[i][j] != ' '){
					return 0;
				}
			}
		}
	}

	return 1;
}

int valaszt(Tabla* tabla, int felhasznaloJon, int szint) {

	int i, j;

	int iMax = 0, jMax = 0;
	int ertek = 0;
	int elsoErtek = 1;

	//for (int k = 0; k < szint; k++){
	//	printf(" ");
	//}
	//printf(" szint: %d, felhasznaloJon: %d\n", szint, felhasznaloJon);

	// Szint limit csak paratlan lehet
	if (szint > 3){
		return pontoz(tabla);
	}

	for (i = 0; i < tabla->meret; i++){
		for (j = 0; j < tabla->meret; j++){
			if (tabla->tomb[i][j] == ' '){
				// Van-e szomszed ?
				if (nincsSzomszed(tabla, i, j)){
					continue;
				}

				if (felhasznaloJon){
					tabla->tomb[i][j] = 'x';
				}
				else {
					tabla->tomb[i][j] = 'o';
				}

				int mezoErtek = valaszt(tabla, !felhasznaloJon, szint+1);

				if (elsoErtek){
					ertek = mezoErtek;
					iMax = i;
					jMax = j;
					elsoErtek = 0;
				}

				// Minimumot keresek
				if (felhasznaloJon){
					if (ertek < mezoErtek){
						ertek = mezoErtek;
						iMax = i;
						jMax = j;
					}
				}
				// Maximumot keresek
				else {
					if (ertek > mezoErtek){
						ertek = mezoErtek;
						iMax = i;
						jMax = j;
					}
				}

				tabla->tomb[i][j] = ' ';
			}
		}
	}

	if (szint == 0){
		tabla->tomb[iMax][jMax] = 'o';
	}

	//printf(" iMax: %d, jMax: %d, ertek: %d\n", iMax, jMax, ertek);

	return ertek;
}
