#include "game.c"

int main()
{
	game jeu = init_plateau();
	jeu.current_player = NOIR;
	afficher_plateau(jeu);
	case_ test_case;
	test_case.coordX = 2;
	test_case.coordY = 3;
	jeu = jouer_coup(jeu, test_case);
	afficher_plateau(jeu);
	case_ test_case_b;
	test_case.coordX = 2;
	test_case.coordY = 2;
	jeu = jouer_coup(jeu, test_case);
	afficher_plateau(jeu);
	test_case.coordX = 3;
	test_case.coordY = 2;
	jeu = jouer_coup(jeu, test_case);
	afficher_plateau(jeu);
	return 0;
}