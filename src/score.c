/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** score functions
*/

# include "my.h"
# include "hunter.h"

int abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int dcnt(int n)
{
	int result = 0;
	int begin = 1;

	while (begin == 1 || n != 0) {
		begin = 0;
		n = n / 10;
		result = result + 1;
	}

	return (result);
}

int power10(int n)
{
	int power = 1;

	while (n > 1) {
		power = power * 10;
		n = n - 1;
	}

	return (power);
}

char *score_to_string(int score)
{
	int is_neg = 0, mod, tmp, offset = 0;
	int digit_count = dcnt(abs(score + ((score < -2147483647) ? 1 : 0)));
	char *res = my_malloc(sizeof(*res) * (digit_count + 1));

	if (score < 0) {
		is_neg = 1;
		res[(offset++)] = '-';
	}

	while (digit_count > 0) {
		tmp = score / power10(digit_count);
		mod = tmp % 10;
		mod *= ((is_neg) ? -1 : 1);
		res[(offset++)] = '0' + mod;
		digit_count -= 1;
	}

	res[(offset++)] = 0;
	return (res);
}

void display_score(param_t *param)
{
	sfText *text = param->text;
	sfColor orange = sfColor_fromRGB(255, 204, 0);
	sfVector2f pos = { 1024 - (169 + 12), 495 + 12 };

	sfRenderWindow_drawSprite(param->window, param->assets[5].sprite, NULL);
	sfSprite_setPosition(param->assets[5].sprite, pos);
	pos.x += 80;
	pos.y += 2;
	sfText_setPosition(text, pos);
	sfText_setString(text, score_to_string(param->player->score));
	sfText_setFont(text, param->default_font);
	sfText_setCharacterSize(text, 40);
	sfText_setColor(text, orange);
	sfRenderWindow_drawText(param->window, text, NULL);
}