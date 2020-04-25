#include "game.c"

int main()
{
	game jeu = init_plateau();
	afficher_plateau(jeu);
	return 0;
}