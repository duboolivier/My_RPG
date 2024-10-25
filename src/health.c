/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

int size_of_int(int temp, int num)
{
    int numDigits = 0;

    while (temp != 0) {
        temp /= 10;
        numDigits++;
    }
    numDigits = (num == 0) ? 1 : numDigits;
    return (numDigits);
}

char *my_itoa(int num)
{
    int temp = num;
    int numDigits = size_of_int(temp, num);
    char *str = malloc(sizeof(char) * numDigits + 1);
    int i;
    int digit;

    if (str != NULL) {
        i = numDigits - 1;
        temp = num;
        while (temp != 0) {
            digit = temp % 10;
            str[i] = digit + '0';
            temp /= 10;
            i--;
        }
        str[0] = (num == 0) ? '0' : str[0];
        str[numDigits] = '\0';
    }
    return str;
}

static int is_zombie_close(global_t *global)
{
    for (int i = 0; i < global->nb_sprite; i++) {
        if (global->sprite[i]->type == ZOMBIE &&
            global->sprite[i]->pos.x < global->player->pos.x + 0.5 &&
            global->sprite[i]->pos.x > global->player->pos.x - 0.5 &&
            global->sprite[i]->pos.y < global->player->pos.y + 0.5 &&
            global->sprite[i]->pos.y > global->player->pos.y - 0.5)
            return 1;
    }
    return 0;
}

static void health_damage(global_t *global)
{
    sfRectangleShape *rect = {0};
    sfVector2f size = {0, 0};

    if (is_zombie_close(global) == 0)
        return;
    if (sfClock_getElapsedTime(global->player->damage_clock).microseconds <
        1000000) {
        rect = sfRectangleShape_create();
        size = (sfVector2f){global->window->width, global->window->height};
        sfRectangleShape_setSize(rect, size);
        sfRectangleShape_setFillColor(rect, (sfColor){255, 0, 0, 100});
        sfRenderWindow_drawRectangleShape(global->window->window, rect, NULL);
        sfRectangleShape_destroy(rect);
        return;
    }
    sfClock_restart(global->player->damage_clock);
    global->player->health -= 10;
}

void health_create(global_t *global)
{
    global->player->health = 100;
    global->player->hp_text = sfText_create();
    sfText_setFont(global->player->hp_text, global->dialog_font);
    sfText_setCharacterSize(global->player->hp_text, 100);
    sfText_setPosition(global->player->hp_text, (sfVector2f){50,
        global->window->height - 300});
    sfText_setColor(global->player->hp_text, sfRed);
    sfText_setString(global->player->hp_text, "100");
}

void health_draw(global_t *global)
{
    char *hp = my_itoa(global->player->health);

    health_damage(global);
    if (global->player->health < 0)
        global->player->health = 0;
    if (global->player->health > 100)
        global->player->health = 100;
    sfText_setFont(global->player->hp_text, global->dialog_font);
    sfText_setString(global->player->hp_text, hp);
    sfRenderWindow_drawText(global->window->window,
        global->player->hp_text, NULL);
    free(hp);
}
