#include "game.h"

game init_plateau()
{
    int i, j;
    game plateau;
    plateau.noir = 0;
    plateau.blanc = 0;

    for(i = 0; i < COLONNE; i++){
        for(j=0; j < LIGNE; j++){
            plateau.plateau_tab[i][j].pion = VIDE;
            plateau.plateau_tab[i][j].coordX = i;
            plateau.plateau_tab[i][j].coordY = j;
            }
    }
    plateau.plateau_tab[3][3].pion, plateau.plateau_tab[4][4].pion = BLANC;
    plateau.plateau_tab[3][4].pion, plateau.plateau_tab[4][3].pion = NOIR;
    
    return plateau;
}