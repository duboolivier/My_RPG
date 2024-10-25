/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "../includes/myrpg.h"

static char *button_inven_path[5] = {
    "assets/font/quest_1.jpg",
    "assets/font/quest_2.jpg",
    "assets/font/quest_3.jpg",
    "assets/font/quest_4.jpg"
};

static const sfVector2f button_pos[5] = {
    {1475, 25},
    {1475, 275},
    {1475, 525},
    {1475, 775}
};

static void create_button(global_t *globals, char *path, int i)
{
    inventory_t *button = malloc(sizeof(inventory_t));
    sfVector2f size = {(float)0.1, (float)0.1};

    if (path == NULL)
        return;
    button->texture = sfTexture_createFromFile(path, NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setScale(button->sprite, size);
    sfSprite_setPosition(button->sprite, button_pos[i]);
    globals->inven[i] = button;
}

static void create_all_buttons(global_t *globals)
{
    for (int i = 0; i < 4; i++)
        create_button(globals, button_inven_path[i], i);
}

void call_buttons_inven(global_t *globals)
{
    create_all_buttons(globals);
}

void quest_update_texture(global_t *globals, int i)
{
    char *path_base = strdup("assets/font/quest_done_1.jpg");

    path_base[23] = i + '1';
    sfTexture_destroy(globals->inven[i]->texture);
    globals->inven[i]->texture = sfTexture_createFromFile(path_base, NULL);
    sfSprite_setTexture(globals->inven[i]->sprite,
        globals->inven[i]->texture, sfTrue);
    free(path_base);
}

void draw_quest(global_t *globals)
{
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(globals->window->window,
            globals->inven[i]->sprite, NULL);
    }
}
