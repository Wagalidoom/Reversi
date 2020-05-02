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

    for (j = 0; j < COLONNE; j++)
    {
        for (i = 0; i < LIGNE; i++)
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
        printf("%d | %c %c %c %c %c %c %c %c|\n", i + 1, plateau.plateau_tab[0][i].pion, plateau.plateau_tab[1][i].pion, plateau.plateau_tab[2][i].pion, plateau.plateau_tab[3][i].pion, plateau.plateau_tab[4][i].pion, plateau.plateau_tab[5][i].pion, plateau.plateau_tab[6][i].pion, plateau.plateau_tab[7][i].pion);
    }
    printf("   ---------------- \n");
    printf("    A B C D E F G H\n");
}

vector direction_to_vector(direction dir){
    vector deplacement;
    switch (dir)
            {
            case HAUT:
                deplacement.X = 0;
                deplacement.Y = -1;
                break;
            case BAS:
                deplacement.X = 0;
                deplacement.Y = 1;
                break;
            case GAUCHE:
                deplacement.X = -1;
                deplacement.Y = 0;
                break;
            case DROITE:
                deplacement.X = 1;
                deplacement.Y = 0;
                break;
            case DIAG_HD:
                deplacement.X = 1;
                deplacement.Y = -1;
                break;
            case DIAG_BD:
                deplacement.X = 1;
                deplacement.Y = 1;
                break;
            case DIAG_HG:
                deplacement.X = -1;
                deplacement.Y = -1;
                break;
            case DIAG_BG:
                deplacement.X = -1;
                deplacement.Y = 1;
                break;

            default:
                deplacement.X = 0;
                deplacement.Y = 0;
                break;
            }
    return deplacement;
}


int case_existe(int x, int y)
{

    if ((x < 0) || (x > LIGNE - 1) || (y < 0) || (y > COLONNE - 1))
    {
        return false;
    }
    return true;
}

int coup_valide(case_ coup, direction dir, game plateau){
    int joueur_ = plateau.current_player;
    char adversaire_c;
    int taille_prise = 0;
    vector deplacement = direction_to_vector(dir);
    int coordX = deplacement.X;
    int coordY = deplacement.Y;

    if (joueur_ == BLANC)
    {
        adversaire_c = 'N';
        coup.pion = 'B';
    }
    else
    {
        adversaire_c = 'B';
        coup.pion = 'N';
    }
    
    while (case_existe(coordX, coordY) && plateau.plateau_tab[coordX][coordY].pion == adversaire_c)
    {
        coordX += deplacement.X;
        coordY += deplacement.Y;
        taille_prise++;
        if (plateau.plateau_tab[coordX][coordY].pion == coup.pion){
            return taille_prise;
        }
    }
    return 0;
}

game jouer_coup(game plateau, case_ coup_act)
{
    int joueur_ = plateau.current_player;
    char adversaire_c;
    int coordX = coup_act.coordX;
    int coordY = coup_act.coordY;
    int taille_prise;
    int coup_joue = 0;

    if (!case_existe(coordX, coordY))
    {
        printf("La case n'existe pas, rejouez\n");
        return plateau;
    }

    char valeur_case = plateau.plateau_tab[coordX][coordY].pion;

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

    direction dir[8] = {HAUT, BAS, GAUCHE, DROITE, DIAG_HD, DIAG_BD, DIAG_HG, DIAG_BG};
    direction dir_act;


    for (dir_act = HAUT; dir_act <= DIAG_BG; dir_act++)
    {   
        coordX = coup_act.coordX;
        coordY = coup_act.coordY;

        vector deplacement = direction_to_vector(dir_act);
        taille_prise = coup_valide(coup_act, dir_act, plateau);
        printf("%d", taille_prise);
        if(taille_prise){
            coup_joue = 1;
            do
            {
                coordX += deplacement.X;
                coordY += deplacement.Y;
                plateau.plateau_tab[coordX][coordY].pion = coup_act.pion;
                taille_prise --;
            } while (taille_prise > 0);
        }
    }
    if (coup_joue){
        plateau.plateau_tab[coup_act.coordX][coup_act.coordY].pion = coup_act.pion;
        plateau.current_player = !joueur_;
    } else {
        printf("Votre coup ne permet pas de prendre de pièces, rejouez\n");
    }
    return plateau;
}