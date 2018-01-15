/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** my_hunter functions
*/

# include "player.h"
# include "animation.h"
# include "my.h"
# include "events.h"
# include "utils.h"
# include "hunter.h"

void change_state(param_t *param)
{
	if (param->state == gameWait) {
		sfRenderWindow_clear(param->window, sfBlack);
		configure_animations(param);
		sfVector2f change = { 0, (rand() % 400) };
		sfSprite_setPosition(param->assets[6].sprite, change);
		param->state = gamePlay;
	} else if (param->state == gamePlay) {
		sfRenderWindow_clear(param->window, sfBlack);
		param->state = gameEnd;
	}
}

void game_wait(param_t *param)
{
	if (param->state == gameWait) {
		sfRenderWindow_drawSprite(param->window,
			param->assets[0].sprite, NULL);
		sfRenderWindow_drawSprite(param->window,
			param->assets[2].sprite, NULL);
		sfVector2f pos = { 800, 480 };
		sfSprite_setPosition(param->assets[2].sprite, pos);
	}
}

void game_play(param_t *param)
{
	if (param->state == gamePlay) {
		sfRenderWindow_drawSprite(param->window,
			param->assets[1].sprite, NULL);
		display_score(param);
		animate_duck(param);
		life_indicator(param);
		update_player_info(param);
	}
}

void game_loader(param_t *param)
{
	sfRenderWindow_clear(param->window, sfBlack);
	sfRenderWindow_setView(param->window, param->fixedView);
	game_wait(param);
	game_play(param);

	if (param->state == gameEnd) {
		sfRenderWindow_drawSprite(param->window,
			param->assets[8].sprite, NULL);
		sfRenderWindow_setMouseCursorVisible(param->window, sfTrue);
		sfRenderWindow_display(param->window);
		sfSleep(sfSeconds(3));
		sfRenderWindow_close(param->window);
	}

	sfRenderWindow_drawSprite(param->window,
		param->assets[4].sprite, NULL);
	sfRenderWindow_display(param->window);
}

void game_management(param_t *param)
{
	sfEvent event;

	while (sfRenderWindow_isOpen(param->window)) {
		while (sfRenderWindow_pollEvent(param->window, &event)) {
			if (event.type == sfEvtClosed ||
				sfKeyboard_isKeyPressed(sfKeyEscape))
				sfRenderWindow_close(param->window);

			events_manager(param, event);
		}

		game_loader(param);
	}
}