#include "game.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

game jouer_coup(game plateau, case_ coup_act)
{
    int joueur_ = plateau.current_player;
    char adversaire_c;
    int coordX = coup_act.coordX;
    int coordY = coup_act.coordY;
    int deplacement_x, deplacement_y;
    int taille_prise;
    if (!case_existe(coordX, coordY))
    {
        printf("La case n'existe pas, rejouez\n");
        return plateau;
    }
    char valeur_case = plateau.plateau_tab[coordY][coordX].pion;
    if (valeur_case != '.')
    {
        printf("Case non vide, rejouez\n");
        return plateau;
    }
    if (joueur_ == BLANC)
    {
        adversaire_c = 'N';
        coup_act.pion = 'B';
    }
    else
    {
        adversaire_c = 'B';
        coup_act.pion = 'N';
    }
    int isValid = 0;
    direction dir[8] = {HAUT, BAS, GAUCHE, DROITE, DIAG_HD, DIAG_BD, DIAG_HG, DIAG_BG};
    direction dir_act;


    for (dir_act = HAUT; dir_act <= DIAG_BG; dir_act++)
    {   
        coordX = coup_act.coordX;
        coordY = coup_act.coordY;
        taille_prise = 0;

        switch (dir_act)
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

        if (case_existe(coordX+deplacement_x, coordY+deplacement_y))
        {
            do
            {
                coordX += deplacement_x;
                coordY += deplacement_y;
                taille_prise++;

            } while (case_existe(coordX+deplacement_x, coordY+deplacement_y) && plateau.plateau_tab[coordY][coordX].pion == adversaire_c);

            if(taille_prise>1 && plateau.plateau_tab[coordY][coordX].pion == coup_act.pion){

                isValid = 1;
                
                
                do
                {
                    //printf("coordX : %d coordY : %d dir %d\n", coordX, coordY, dir_act);
                    coordX -= deplacement_x;
                    coordY -= deplacement_y;
                    plateau.plateau_tab[coordY][coordX].pion = coup_act.pion;
                } while (coordX != coup_act.coordX && coordY != coup_act.coordY);
                //plateau.plateau_tab[coordX][coordY].pion = coup_act.pion; ???
                
            }
        }
    }
    if (isValid){
        plateau.plateau_tab[coup_act.coordY][coup_act.coordX].pion = coup_act.pion;
        plateau.current_player = !joueur_;
    } else {
        printf("Votre coup ne permet pas de prendre de pièces, rejouez\n");
    }
    return plateau;
}

int case_existe(int x, int y)
{

    if ((x < 0) || (x > LIGNE - 1) || (y < 0) || (y > COLONNE - 1))
    {
        return false;
    }
    return true;
}