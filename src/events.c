/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** events functions
*/

# include "events.h"

void mouse_event(param_t *param, sfEvent event)
{
	mouse_move_event(param, event);
	mouse_click_event(param, event);
}

void events_manager(param_t *param, sfEvent event)
{
	mouse_event(param, event);
}