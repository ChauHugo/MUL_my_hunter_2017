/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** player functions
*/

# include "my.h"
# include "hunter.h"
# include "player.h"

duck_info_t get_duck_infos(param_t *param)
{
	duck_info_t inf;
	playerStat_t *stat = param->player;

	inf.count = 1;
	inf.speed = 1.2 * stat->speed_mul;

	return (inf);
}

void life_indicator(param_t *param)
{
	sfIntRect rec = *param->assets[7].rec;
	playerStat_t player = *param->player;
	sfVector2f pos = { 12, 576 - 24 - 37 };

	rec.width /= ((player.shoots == 3) ? 1 : 3);

	if (player.shoots == 2) {
		rec.width *= 2;
	} else if (player.shoots == 0) {
		rec.width = 1;
		change_state(param);
	}

	sfSprite_setTextureRect(param->assets[7].sprite, rec);
	sfSprite_setPosition(param->assets[7].sprite, pos);
	sfRenderWindow_drawSprite(param->window, param->assets[7].sprite, NULL);
}

void update_player_info(param_t *param)
{
	playerStat_t *stat = param->player;

	if (stat->score && (stat->score % 5 == 0) && !stat->updated) {
		stat->speed_mul *= 1.3;
		stat->updated = true;
	}
}