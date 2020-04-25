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
} pion;

typedef struct
{
    pion plateau[LIGNE][COLONNE];
} game;

ABC
