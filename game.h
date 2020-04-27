// DEFINE
#define BLANC 1
#define NOIR 0
#define LIGNE 8
#define COLONNE 8

// STRUCTURES

typedef enum
{
    HAUT,
    BAS,
    GAUCHE,
    DROITE,
    DIAG_HD,
    DIAG_BD,
    DIAG_HG,
    DIAG_BG,
} direction;

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
    int current_player;
} game;


// FONCTIONS

// initialisation du plateau avec les 4 pions centraux
game init_plateau();

// afficher plateau
void afficher_plateau(game plateau);

int position_gagnante(game plateau);

game jouer_coup(game plateau, case_ coup);

int case_existe(int x, int y);

char check_direction(game plateau, case_ case_actuelle, direction dir, int isValid);

case_ coup_ordinateur(game plateau);
