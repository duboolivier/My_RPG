/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

static void weapon_collision(global_t *globals)
{
    sprite_t *sprite = globals->sprite[globals->player->is_looking_sprite - 1];

    if (globals->player->is_firing == 0 || globals->player->is_looking_sprite
        == 0 || sprite->type != ZOMBIE)
        return;
    if (sprite->damage > 100) {
        sprite->pos.x = -1000;
        sprite->pos.y = -1000;
        globals->player->xp += 5;
        sfSound_play(globals->sounds[1]);
    } else {
        if (globals->player->weapon_id == 0)
            sprite->damage += 15 + globals->player->xp / 10;
        if (globals->player->weapon_id == 1)
            sprite->damage += 20 + globals->player->xp / 10;
    }
}

static void weapon_click(global_t *globals)
{
    globals->player->is_firing = 1;
    sfSprite_setTexture(globals->weapon->sprite,
        globals->weapon->fired_texture, sfTrue);
    weapon_collision(globals);
    if (globals->player->weapon_id == 1)
        sfSound_play(globals->sounds[0]);
    if (sfClock_getElapsedTime(globals->weapon->clock).microseconds < 100000)
        sfSprite_setTexture(globals->weapon->sprite,
            globals->weapon->texture, sfTrue);
    if (sfClock_getElapsedTime(globals->weapon->clock).microseconds > 300000) {
        globals->player->is_firing = 0;
        sfClock_restart(globals->weapon->clock);
    }
}

static void weapon_shoot(global_t *globals)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfFalse ||
        (sfClock_getElapsedTime(globals->weapon->clock).microseconds < 300000
            && globals->player->is_firing == 1)) {
        sfSprite_setTexture(globals->weapon->sprite,
            globals->weapon->texture, sfTrue);
        if (sfClock_getElapsedTime(globals->weapon->clock).microseconds
            < 100000 && globals->player->is_firing == 1)
            sfSprite_setTexture(globals->weapon->sprite,
                globals->weapon->fired_texture, sfTrue);
        return;
    }
    weapon_click(globals);
}

void weapon_switch(global_t *globals, char *img1, char *img2, int type)
{
    sfSprite_setTexture(globals->weapon->sprite,
        globals->weapon->texture, sfTrue);
    sfTexture_destroy(globals->weapon->texture);
    sfTexture_destroy(globals->weapon->fired_texture);
    globals->weapon->texture = sfTexture_createFromFile(img1, NULL);
    globals->weapon->fired_texture = sfTexture_createFromFile(img2, NULL);
    sfSprite_setTexture(globals->weapon->sprite,
        globals->weapon->texture, sfTrue);
    globals->player->weapon_id = type;
}

void weapon_create(global_t *globals, char *img1, char *img2)
{
    globals->weapon = malloc(sizeof(weapon_t));
    globals->weapon->texture = sfTexture_createFromFile(img1, NULL);
    globals->weapon->fired_texture = sfTexture_createFromFile(img2, NULL);
    globals->weapon->sprite = sfSprite_create();
    globals->weapon->pos = (sfVector2f){globals->window->width / 3,
        globals->window->height / 3};
    globals->weapon->scale = (sfVector2f){4, 4};
    globals->weapon->clock = sfClock_create();
    sfSprite_setTexture(globals->weapon->sprite,
        globals->weapon->texture, sfTrue);
    sfSprite_setPosition(globals->weapon->sprite,
        globals->weapon->pos);
    sfSprite_setScale(globals->weapon->sprite, globals->weapon->scale);
}

void weapon_draw(global_t *globals)
{
    weapon_shoot(globals);
    sfRenderWindow_drawSprite(globals->window->window,
        globals->weapon->sprite, NULL);
}
