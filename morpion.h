#ifndef MORPION_H
#define MORPION_H

void initialiserPlateau(char plateau[3][3]);
void afficherPlateau(char plateau[3][3]);
int plateauPlein(char plateau[3][3]);
void jouerTour(char plateau[3][3], int joueur);
int verifierVictoire(char plateau[3][3]);

#endif
