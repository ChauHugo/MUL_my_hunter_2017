/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** mouse_events functions
*/

# include "animation.h"
# include "hunter.h"
# include "events.h"

void mouse_move_event(param_t *param, sfEvent event)
{
	if (event.type == sfEvtMouseMoved) {
		sfMouseMoveEvent mouse = event.mouseMove;
		sfVector2f pos = {(mouse.x - (178 / 6)), (mouse.y - (178 / 6))};
		sfSprite_setPosition(param->assets[4].sprite, pos);

		if (param->state == gameWait) {
			if (mouse.x >= 800 && mouse.x <= 1000 &&
			   mouse.y >= 480 && mouse.y <= 552)
				param->assets[2].rec->top = 71;
			else
				param->assets[2].rec->top = 0;

			sfSprite_setTextureRect(param->assets[2].sprite,
				*param->assets[2].rec);
		}
	}
}

void mouse_click_event(param_t *param, sfEvent event)
{
	if (event.type == sfEvtMouseButtonPressed) {
		sfMouseButtonEvent mouse = event.mouseButton;

		if (param->state == gameWait) {
			if (mouse.x >= 800 && mouse.x <= 1000 &&
				mouse.y >= 480 && mouse.y <= 552)
				param->assets[2].rec->top = 71 + 72;
			else
				param->assets[2].rec->top = 0;

			sfSprite_setTextureRect(param->assets[2].sprite,
				*param->assets[2].rec);
		} else if (param->state == gamePlay) {
			sfVector2f pos;
			sfIntRect srec = *param->assets[6].rec;

			pos = sfSprite_getPosition(param->assets[6].sprite);

			if (mouse.x >= pos.x && mouse.x <= (pos.x + srec.width) &&
				mouse.y >= pos.y && mouse.y <= (pos.y + srec.height)) {
				param->player->score += 1;
				
				restart_animation(param);
			} else {
				param->player->shoots -= 1;
			}
		}
	} else if (event.type == sfEvtMouseButtonReleased) {
		sfMouseButtonEvent mouse = event.mouseButton;

		if (param->state == gameWait) {
			if (mouse.x >= 800 && mouse.x <= 1000 &&
				mouse.y >= 480 && mouse.y <= 552) {
				sfSleep(sfMilliseconds(125));
				change_state(param);
			}
		}
	}
}