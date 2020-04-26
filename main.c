#include "game.c"

int main()
{
	game jeu = init_plateau();
	afficher_plateau(jeu);
	case_ test_case;
	test_case.coordX = 0;
	test_case.coordY = 0;
	direction dir_gauche = GAUCHE;
	direction dir_bas = BAS;
	direction dir_hd = DIAG_HD;
	direction dir_droite = DROITE;
	printf("Gauche : %d, bas : %d, haut_droite : %d, droite : %d", case_existe(test_case, dir_gauche), case_existe(test_case, dir_bas), case_existe(test_case, dir_hd), case_existe(test_case, dir_droite));
	return 0;
}