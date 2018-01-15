/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** anim_utils functions
*/

# include "hunter.h"
# include "my.h"
# include "utils.h"

void configure_animations(param_t *param)
{
	anim_t *anim = my_malloc(sizeof(anim_t));

	anim[0].clock = sfClock_create();
	anim[0].sprite = NULL;
	anim[0].max_duration = sfTime_asMilliseconds(sfMilliseconds(600));
	anim[0].update = sfTime_asMilliseconds(sfMilliseconds(200));

	param->anim = anim;
}

void destroy_animations(param_t *param)
{
	if (param->state != gameWait) {
		for (int i = 0; i < ANNIMA_CNT; i++) {
			sfClock_destroy(param->anim[i].clock);
		}

		free(param->anim);
	}
}
