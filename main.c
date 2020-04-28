#include "game.c"

int position_gagnante(game jeu)
{
	return 0;
}

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}

case_ entrer_coup()
{
	case_ coup;
	int x = 0;
	int y = 0;
	char c;

	do
	{
		printf("Entrer les coordonnées x (entre 1 et 8)\nx : ");

	} while (((scanf("%d%c", &x, &c)!=2 || c!='\n') && clean_stdin()) || x < 1 || x > 8);

	do
	{
		printf("Entrer les coordonnées y (entre 1 et 8)\ny : ");

	} while (((scanf("%d%c", &y, &c)!=2 || c!='\n') && clean_stdin()) || y < 1 || y > 8);


	coup.coordX = x - 1;
	coup.coordY = y - 1;
	printf("%d %d\n", x, y);
	return coup;
}

int main()
{
	game jeu = init_plateau();
	jeu.current_player = NOIR;
	int n_b = 0;
	int player_temp;
	case_ coup;
	char c;
	do
	{
		printf("Quelle couleur voulez vous prendre ? (NOIR commence)\n1 : NOIR		2 : BLANC\n");
		
	} while (((scanf("%d%c", &n_b, &c)!=2 || c!='\n') && clean_stdin()) || n_b != 1 && n_b != 2);

	afficher_plateau(jeu);

	if (n_b == 1)
	{
		do
		{
			player_temp = jeu.current_player;
			if (jeu.current_player == NOIR)
			{
				coup = entrer_coup();
			}
			else
			{
				coup = entrer_coup();
			}
			printf("%d %d\n", coup.coordX, coup.coordY);
			

			jeu = jouer_coup(jeu, coup);
			if (player_temp == !jeu.current_player)
			{
				afficher_plateau(jeu);
			}

		} while (!position_gagnante(jeu));
	}

	else if (n_b == 2)
	{
		do
		{
			player_temp = jeu.current_player;
			if (jeu.current_player == BLANC)
			{
				coup = entrer_coup();
			}
			else
			{
				coup = entrer_coup();
			}

			jeu = jouer_coup(jeu, coup);
			if (player_temp == !jeu.current_player)
			{
				afficher_plateau(jeu);
			}

		} while (!position_gagnante(jeu));
	}

	else
	{
		return 1;
	}

	return 0;
}