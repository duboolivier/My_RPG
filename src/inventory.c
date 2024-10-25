/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "../includes/myrpg.h"

void init_gun(global_t *global)
{
    sfVector2f size = {0.55, 0.55};
    sfVector2f pos = {global->window->width / 2.4,
    global->window->height / 3.35};

    global->gun = malloc(sizeof(gun_t));
    if (!global->gun)
        return;
    global->gun->texture =
            sfTexture_createFromFile("assets/font/gun.png", NULL);
    global->gun->sprite = sfSprite_create();
    sfSprite_setScale(global->gun->sprite, size);
    sfSprite_setTexture(global->gun->sprite,
                        global->gun->texture, sfTrue);
    sfSprite_setPosition(global->gun->sprite, pos);
}

void init_inventory(global_t *global)
{
    sfVector2f size = {0.40, 0.40};
    sfVector2f pos = {global->window->width / 3.5,
        global->window->height / 8.5};

    global->inventory = malloc(sizeof(inventory_t));
    if (!global->inventory)
        return;
    global->inventory->texture =
            sfTexture_createFromFile("assets/font/inventory.jpg", NULL);
    global->inventory->sprite = sfSprite_create();
    sfSprite_setScale(global->inventory->sprite, size);
    sfSprite_setTexture(global->inventory->sprite,
                        global->inventory->texture, sfTrue);
    sfSprite_setPosition(global->inventory->sprite, pos);
    load_settings(global);
}

void inventory(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        sfRenderWindow_drawSprite(global->window->window,
            global->inventory->sprite, NULL);
        draw_quest(global);
    }
}
