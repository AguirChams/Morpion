#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ia.h"

void jouerIA(char plateau[3][3]) {
    int ligne, colonne;
    srand(time(NULL));

    do {
        ligne = rand() % 3;
        colonne = rand() % 3;
    } while (plateau[ligne][colonne] != ' ');

    plateau[ligne][colonne] = 'O';
    printf("IA a joué en (%d, %d)\n", ligne, colonne);
}
