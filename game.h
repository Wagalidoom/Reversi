// DEFINE

#define LIGNE 8
#define COLONNE 8

// STRUCTURE

typedef struct
{
    int alive;
    int color;
    int coordX;
    int coordY;
} case_;

typedef struct
{
    case_ plateau[LIGNE][COLONNE];
} game;