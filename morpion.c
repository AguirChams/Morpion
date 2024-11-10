#include <stdio.h>
#include "morpion.h"

void initialiserPlateau(char plateau[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            plateau[i][j] = ' ';
        }
    }
}

void afficherPlateau(char plateau[3][3]) {
    printf(" %c | %c | %c\n", plateau[0][0], plateau[0][1], plateau[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", plateau[1][0], plateau[1][1], plateau[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", plateau[2][0], plateau[2][1], plateau[2][2]);
}

int plateauPlein(char plateau[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (plateau[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void jouerTour(char plateau[3][3], int joueur) {
    int ligne, colonne;
    char symbole = (joueur == 1) ? 'X' : 'O';

    do {
        printf("Joueur %c, entrez la ligne et la colonne (0, 1 ou 2) : ", symbole);
        scanf("%d %d", &ligne, &colonne);
    } while (ligne < 0 || ligne > 2 || colonne < 0 || colonne > 2 || plateau[ligne][colonne] != ' ');

    plateau[ligne][colonne] = symbole;
}

int verifierVictoire(char plateau[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (plateau[i][0] == plateau[i][1] && plateau[i][1] == plateau[i][2] && plateau[i][0] != ' ')
            return 1;
        if (plateau[0][i] == plateau[1][i] && plateau[1][i] == plateau[2][i] && plateau[0][i] != ' ')
            return 1;
    }
    if (plateau[0][0] == plateau[1][1] && plateau[1][1] == plateau[2][2] && plateau[0][0] != ' ')
        return 1;
    if (plateau[0][2] == plateau[1][1] && plateau[1][1] == plateau[2][0] && plateau[0][2] != ' ')
        return 1;

    return 0;
}
