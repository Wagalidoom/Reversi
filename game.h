// DEFINE

#define LIGNE 8
#define COLONNE 8

// STRUCTURE
typedef enum
{
    VIDE,
    BLANC,
    NOIR
} state;

typedef struct
{
    state pion;
    int coordX;
    int coordY;
} case_;

typedef struct
{
    case_ plateau_tab[LIGNE][COLONNE];
    int noir;
    int blanc;
} game;

// init plateau
game init_plateau();

int position_gagnante(game plateau);

