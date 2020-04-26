#include "game.c"

int main()
{
	game jeu = init_plateau();
	jeu.current_player = NOIR;
	afficher_plateau(jeu);
	case_ test_case_n;
	test_case_n.coordX = 2;
	test_case_n.coordY = 3;
	test_case_n.pion = 'N';
	jeu = jouer_coup(jeu, test_case_n);
	afficher_plateau(jeu);
	jeu.current_player = BLANC;
	case_ test_case_b;
	test_case_b.coordX = 2;
	test_case_b.coordY = 2;
	test_case_b.pion = 'B';
	jeu = jouer_coup(jeu, test_case_b);
	afficher_plateau(jeu);
	return 0;
}