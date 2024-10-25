/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

void splash_screen(global_t *globals)
{
    sfTexture *texture = sfTexture_createFromFile("assets/img/logo.png", NULL);
    sfSprite *sprite = sfSprite_create();
    int transparence = 0;

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){0, 0});
    sfSprite_setScale(sprite, (sfVector2f){1.79, 1.75});
    while ((sfRenderWindow_isOpen(globals->window->window) &&
        sfClock_getElapsedTime(globals->main_clock).microseconds < 3000000) &&
        !sfKeyboard_isKeyPressed(sfKeySpace)) {
        sfSprite_setColor(sprite, (sfColor){255, 255, 255, transparence});
        sfRenderWindow_clear(globals->window->window, sfBlack);
        sfRenderWindow_drawSprite(globals->window->window, sprite, NULL);
        sfRenderWindow_display(globals->window->window);
        if (transparence < 255)
            transparence += 1;
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}
