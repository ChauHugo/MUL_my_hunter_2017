/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** utils functions
*/

# include "hunter.h"
# include "my.h"
# include "utils.h"

assets_t *initiate_assets_struct(void)
{
	assets_t *ass = my_malloc(sizeof(assets_t) * ASSETS_CNT);

	ass->texture = NULL;
	ass->sprite = NULL;

	return (ass);
}

playerStat_t *initiate_playerStats(void)
{
	playerStat_t *stats = my_malloc(sizeof(playerStat_t));

	stats->speed_mul = 1.8;
	stats->stade = 0;
	stats->score = 0;
	stats->shoots = 3;
	stats->updated = false;

	return (stats);
}

param_t *initiate_params(void)
{
	param_t *param = my_malloc(sizeof(param_t));
	sfVideoMode mode = { 1024, 576, 32 };
	char *title;

	title = "Duck Hunt - v3.3.5";
	param->window = sfRenderWindow_create(mode, title, sfClose, NULL);
	param->state = gameWait;
	param->fixedView = sfRenderWindow_getView(param->window);
	param->text = sfText_create();

	sfRenderWindow_setFramerateLimit(param->window, 60);
	sfRenderWindow_setMouseCursorVisible(param->window, sfFalse);
	param->player = initiate_playerStats();
	param->assets = initiate_assets_struct();
	initiate_assets(param);
	param->anim = NULL;
	return (param);
}

sfIntRect *configure_rect(int left, int top, int width, int height)
{
	sfIntRect *rec = my_malloc(sizeof(sfIntRect));

	rec->left = left;
	rec->top = top;
	rec->width = width;
	rec->height = height;

	return (rec);
}

void destroy_content(param_t *param)
{
	sfRenderWindow_destroy(param->window);
	sfText_destroy(param->text);
	free(param->player);
	free(param);
}