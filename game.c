#include "game.h"
#include <stdbool.h>
#include <stdio.h>

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

int coup_valide(game plateau, case_ coup_act)
{
    joueur joueur_ = plateau.current_player;
    char adversaire_c;
    char joueur_c;
    int coordX = coup_act.coordX;
    int coordY = coup_act.coordY;
    int case_adverse;
    if (!case_existe(coup_act, AUCUNE))
    {
        return false;
    }
    char valeur_case = plateau.plateau_tab[coordX][coordY].pion;
    if (valeur_case != '.')
    {
        return false;
    }
    if (joueur_ == BLANC)
    {
        adversaire_c = 'N';
        joueur_c = 'B';
    }
    else
    {
        adversaire_c = 'B';
        joueur_c = 'N';
    }
    int isValid = 0;
    direction dir[8] = {HAUT, BAS, GAUCHE, DROITE, DIAG_HD, DIAG_BD, DIAG_HG, DIAG_BG};

    for (direction dir = HAUT; dir <= DIAG_BG; dir++)
    {
        case_adverse = 0;
        if (case_existe(plateau.plateau_tab[coordX][coordY], dir))
        {
            do
            {
                switch (dir)
                {
                case HAUT:
                    coordY--;
                    break;
                case BAS:
                    coordY++;
                    break;
                case GAUCHE:
                    coordX--;
                    break;
                case DROITE:
                    coordX++;
                    break;
                case DIAG_HD:
                    coordX++;
                    coordY--;
                    break;
                case DIAG_BD:
                    coordX++;
                    coordY++;
                    break;
                case DIAG_HG:
                    coordX--;
                    coordY--;
                    break;
                case DIAG_BG:
                    coordX--;
                    coordY++;
                    break;

                default:
                    printf("Erreur sur la vérifiction du déplacement");
                    break;
                }
                case_adverse++;

            } while (case_existe(plateau.plateau_tab[coordX][coordY], dir) && plateau.plateau_tab[coordX][coordY].pion == adversaire_c);

            if(case_adverse!=1 && plateau.plateau_tab[coordX][coordY].pion == joueur_c){
                isValid = 1;

            }
        }
    }
    return isValid;
}

int case_existe(case_ case_actuelle, direction dir)
{
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
        deplacement_x = 0;
        deplacement_y = 0;
        break;
    }

    new_x = case_actuelle.coordX + deplacement_x;
    new_y = case_actuelle.coordY + deplacement_y;
    if ((new_x < 0) || (new_x > LIGNE) || (new_y < 0) || (new_y > COLONNE))
    {
        return false;
    }
    return true;
}