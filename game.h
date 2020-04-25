// DEFINE

#define LIGNE 8
#define COLONNE 8

// STRUCTURES
typedef struct
{
    char pion;
    int coordX;
    int coordY;
} case_;

typedef struct
{
    case_ plateau_tab[LIGNE][COLONNE];
    int noir;
    int blanc;
} game;


// FONCTIONS

// initialisation du plateau avec les 4 pions centraux
game init_plateau();

// afficher plateau
void afficher_plateau(game plateau);

int position_gagnante(game plateau);

