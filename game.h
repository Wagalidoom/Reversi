// DEFINE

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
    AUCUNE,
} direction;

typedef enum
{
    VIDE,
    NOIR,
    BLANC,
} joueur;

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
    joueur current_player;
} game;

typedef struct
{
    int coordX;
    int coordY;
} coup;


// FONCTIONS

// initialisation du plateau avec les 4 pions centraux
game init_plateau();

// afficher plateau
void afficher_plateau(game plateau);

int position_gagnante(game plateau);

int coup_valide(game plateau, coup coup_);

int case_existe(case_ case_actuelle, direction dir);

char check_direction(game plateau, case_ case_actuelle, direction dir, int isValid);

coup coup_ordinateur(game plateau);
