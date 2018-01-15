/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** main function
*/

# include "my.h"
# include "utils.h"
# include "hunter.h"

void check_flags(int ac, char **av)
{
	if (ac < 2)
		return;

	for (int i = 1; i <= ac; i++) {
		if (av[i][0] == '-' && av[i][1] == 'h') {
			my_putstr("Je suis l'aide.\n");
			exit(0);
		}
	}
}

int main(int ac, char **av)
{
	param_t *param;

	check_flags(ac, av);
	param = initiate_params();

	game_management(param);
	destroy_assets(param);
	destroy_animations(param);
	destroy_content(param);

	return (0);
}