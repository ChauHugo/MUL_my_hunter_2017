/*
** EPITECH PROJECT, 2017
** Project Name
** File description:
** ext_utils functions
*/

# include "my.h"
# include "utils.h"

void param_textures(assets_t *ass)
{
	sfTexture_setSmooth(ass[2].texture, sfTrue);
	sfTexture_setSmooth(ass[3].texture, sfTrue);
	sfTexture_setSmooth(ass[4].texture, sfTrue);
	sfTexture_setSmooth(ass[5].texture, sfTrue);
}

assets_t *configure_assets(param_t *param)
{
	assets_t *ass = param->assets;
	ass[0].rec = ass[3].rec = ass[5].rec = ass[8].rec = NULL;
	ass[0].texture = sfTexture_createFromFile("ext/img/bwait.png", NULL);
	ass[1].rec = configure_rect(0, 150, 1024, 576);
	ass[1].texture = sfTexture_createFromFile("ext/img/bplay.png", ass[1].rec);
	ass[2].rec = configure_rect(0, 0, 200, 72);
	ass[2].texture = sfTexture_createFromFile("ext/img/btn_start.png", NULL);
	ass[3].texture = sfTexture_createFromFile("ext/img/btn_pause.png", NULL);
	ass[4].rec = configure_rect(178, 178, 357, 357);
	ass[4].texture = sfTexture_createFromFile("ext/img/cross_hair.png", NULL);
	ass[5].texture = sfTexture_createFromFile("ext/img/score.png", NULL);
	ass[6].rec = configure_rect(0, 0, 183, 45);
	ass[6].texture = sfTexture_createFromFile("ext/img/duck.png", NULL);
	ass[7].rec = configure_rect(0, 0, 134, 37);
	ass[7].texture = sfTexture_createFromFile("ext/img/life.png", NULL);
	ass[8].texture = sfTexture_createFromFile("ext/img/game_over.png", NULL);
	param->default_font = sfFont_createFromFile("ext/fonts/default.otf");
	param_textures(ass);

	return (ass);
}

void initiate_assets(param_t *param)
{
	assets_t *ass = configure_assets(param);

	for (int i = 0; i < ASSETS_CNT; i++) {
		if (ass[i].texture == NULL)
			exit(84);

		ass[i].sprite = sfSprite_create();
		sfSprite_setTexture(ass[i].sprite, ass[i].texture, sfTrue);
	}

	if (param->default_font == NULL)
		exit(84);

	sfSprite_setTextureRect(ass[2].sprite, *ass[2].rec);
	sfSprite_setTextureRect(ass[4].sprite, *ass[4].rec);
	param->assets = ass;
}

void destroy_assets(param_t *param)
{
	for (int i = 0; i < ASSETS_CNT; i++) {
		sfTexture_destroy(param->assets[i].texture);
		sfSprite_destroy(param->assets[i].sprite);

		if (param->assets[i].rec != NULL)
			free(param->assets[i].rec);
	}

	free(param->assets);
}