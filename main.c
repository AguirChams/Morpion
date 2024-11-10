#include <stdio.h>
#include "morpion.h"
#include "ia.h"

int main() {
    char plateau[3][3];
    int joueur = 1;  // 1 pour joueur 1 (X), -1 pour joueur 2 (O)
    int mode;        // 0 pour joueur vs joueur, 1 pour joueur vs IA
    int victoire = 0;

    // Initialisation du plateau
    initialiserPlateau(plateau);

    // Choix du mode de jeu
    printf("Choisissez un mode de jeu :\n");
    printf("0 - Joueur contre Joueur\n1 - Joueur contre IA\n");
    scanf("%d", &mode);

    // Boucle principale du jeu
    while (!victoire && !plateauPlein(plateau)) {
        afficherPlateau(plateau);
        if (mode == 1 && joueur == -1) {
            // Tour de l'IA
            jouerIA(plateau);
        } else {
            // Tour du joueur
            jouerTour(plateau, joueur);
        }

        victoire = verifierVictoire(plateau);
        joueur = -joueur;  // Changer de joueur (alternance entre 1 et -1)
    }

    afficherPlateau(plateau);

    if (victoire) {
        printf("Le joueur %c a gagné!\n", (joueur == -1) ? 'X' : 'O');
    } else {
        printf("Match nul!\n");
    }

    return 0;
}
