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

            if ((i == 4) && (j==4)){
                plateau.plateau_tab[i][j].pion = BLANC; //ETC
            }

        }

    }
}