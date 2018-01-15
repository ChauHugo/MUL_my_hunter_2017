/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** animation functions
*/

# include "player.h"
# include "hunter.h"
# include "animation.h"

void check_duck_position(param_t *param)
{
	sfVector2f pos = sfSprite_getPosition(param->assets[6].sprite);
	sfVector2u win_size = sfRenderWindow_getSize(param->window);
	duck_info_t inf = get_duck_infos(param);
	sfVector2f offset = { inf.speed, 0 };

	srand(time(NULL));

	if (pos.x >= win_size.x || pos.y >= win_size.y) {
		offset.x *= -1;
		sfVector2f change = { 0, (rand() % win_size.y - 176) };
		sfSprite_setPosition(param->assets[6].sprite, change);
	} else {
		sfSprite_move(param->assets[6].sprite, offset);
	}
}

void duck_move_management(param_t *param, sfIntRect *rec)
{
	anim_t *duck = &param->anim[0];
	sfTime current = sfClock_getElapsedTime(duck->clock);

	if (sfTime_asMilliseconds(current) >= duck->update) {
		rec->left += 183 / 3;
		duck->update += 200;
	} else if (sfTime_asMilliseconds(current) >= duck->max_duration) {
		duck->update = 200;
		rec->left = 0;
		sfClock_restart(duck->clock);
	}

	check_duck_position(param);
}

void animate_duck(param_t *param)
{
	sfIntRect *rec = param->assets[6].rec;
	rec->width = 183 / 3;

	duck_move_management(param, rec);
	sfSprite_setTextureRect(param->assets[6].sprite, *rec);
	sfRenderWindow_drawSprite(param->window, param->assets[6].sprite, NULL);
}

void restart_animation(param_t *param)
{
	sfVector2u win_size = sfRenderWindow_getSize(param->window);
	sfVector2f change = { 0, (rand() % win_size.y - 176) };

	param->anim[0].update = 200;
	param->assets[6].rec->left = 0;
	param->player->updated = false;

	sfSprite_setPosition(param->assets[6].sprite, change);
	sfClock_restart(param->anim[0].clock);
	check_duck_position(param);
	sfRenderWindow_drawSprite(param->window, param->assets[6].sprite, NULL);
}