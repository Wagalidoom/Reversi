#include "game.h"
#include <stdio.h>
#include <stdbool.h>

game init_plateau()
{
    int i, j;
    game plateau;
    plateau.noir = 0;
    plateau.blanc = 0;

    for (i = 0; i < COLONNE; i++)
    {
        for (j = 0; j < LIGNE; j++)
        {
            plateau.plateau_tab[i][j].pion = '.';
            plateau.plateau_tab[i][j].coordX = i;
            plateau.plateau_tab[i][j].coordY = j;
        }
    }
    plateau.plateau_tab[3][3].pion = 'B';
    plateau.plateau_tab[4][4].pion = 'B';
    plateau.plateau_tab[3][4].pion = 'N';
    plateau.plateau_tab[4][3].pion = 'N';

    return plateau;
}

void afficher_plateau(game plateau)
{
    int i;
    printf("   ________________ \n");
    for (i = 0; i < LIGNE; i++)
    {
        printf("%d | %c %c %c %c %c %c %c %c|\n", i + 1, plateau.plateau_tab[i][0].pion, plateau.plateau_tab[i][1].pion, plateau.plateau_tab[i][2].pion, plateau.plateau_tab[i][3].pion, plateau.plateau_tab[i][4].pion, plateau.plateau_tab[i][5].pion, plateau.plateau_tab[i][6].pion, plateau.plateau_tab[i][7].pion);
    }
    printf("   ---------------- \n");
    printf("    A B C D E F G H\n");
}

int coup_valide(game plateau, coup coup_)
{
    joueur joueur_ = plateau.current_player;
    int coordX = coup_.coordX;
    int coordY = coup_.coordY;
    char actual_case = plateau.plateau_tab[coordX][coordY].pion;
    direction dir[8] = {HAUT, BAS, GAUCHE, DROITE, DIAG_HD, DIAG_BD, DIAG_HG, DIAG_BG};

    


    if ((plateau.plateau_tab[coordX - 1][coordY].pion != actual_case) && (plateau.plateau_tab[coordX - 1][coordY].pion != '.'))
    {
        //check_direction(plateau, coup, GAUCHE);
    }

    if ((plateau.plateau_tab[coordX + 1][coordY].pion != actual_case) && (plateau.plateau_tab[coordX + 1][coordY].pion != '.'))
    {
        //check_direction(plateau, coup, DROITE);
    }

    if ((plateau.plateau_tab[coordX][coordY-1].pion != actual_case) && (plateau.plateau_tab[coordX][coordY-1].pion != '.'))
    {
        //check_direction(plateau, coup, HAUT);
    }

    if ((plateau.plateau_tab[coordX][coordY+1].pion != actual_case) && (plateau.plateau_tab[coordX][coordY+1].pion != '.'))
    {
        //check_direction(plateau, coup, BAS);
    }
}

int case_existe(case_ case_actuelle, direction dir){
    int deplacement_x, deplacement_y, new_x, new_y;
    switch (dir)
    {
    case HAUT:
        deplacement_x = 0;
        deplacement_y = -1;
        break;
    case BAS:
        deplacement_x = 0;
        deplacement_y = 1;
        break;
    case GAUCHE:
        deplacement_x = -1;
        deplacement_y = 0;
        break;
    case DROITE:
        deplacement_x = 1;
        deplacement_y = 0;
        break;
    case DIAG_HD:
        deplacement_x = 1;
        deplacement_y = -1;
        break;
    case DIAG_BD:
        deplacement_x = 1;
        deplacement_y = 1;
        break;
    case DIAG_HG:
        deplacement_x = -1;
        deplacement_y = -1;
        break;
    case DIAG_BG:
        deplacement_x = -1;
        deplacement_y = 1;
        break;
    
    
    default:
        printf("Erreur sur la vérifiction du déplacement");
        break;
    }

    new_x = case_actuelle.coordX + deplacement_x;
    new_y = case_actuelle.coordY + deplacement_y;
    if ( (new_x < 0) || (new_x > LIGNE) || (new_y < 0) || (new_y > COLONNE) ){
        return false;
    }
    return true;
}