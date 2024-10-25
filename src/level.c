/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

void level_create(global_t *global)
{
    global->player->xp = 0;
    global->player->xp_text = sfText_create();
    global->player->damage_clock = sfClock_create();
    sfText_setFont(global->player->xp_text, global->dialog_font);
    sfText_setCharacterSize(global->player->xp_text, 100);
    sfText_setPosition(global->player->xp_text, (sfVector2f){50,
        global->window->height - 200});
    sfText_setColor(global->player->xp_text, sfBlue);
    sfText_setString(global->player->xp_text, "0");
}

void level_draw(global_t *global)
{
    char *level = my_itoa(global->player->xp);

    if (global->player->xp < 0)
        global->player->xp = 0;
    if (global->player->xp > 100)
        global->player->xp = 100;
    sfText_setFont(global->player->xp_text, global->dialog_font);
    sfText_setString(global->player->xp_text, level);
    sfRenderWindow_drawText(global->window->window,
        global->player->xp_text, NULL);
    free(level);
}
