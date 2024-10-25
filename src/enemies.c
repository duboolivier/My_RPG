/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

void update_single_enemy(global_t *globals, int i)
{
    float vec_x = globals->player->pos.x - globals->sprite[i]->pos.x;
    float vec_y = globals->player->pos.y - globals->sprite[i]->pos.y;
    float dist = sqrt(vec_x * vec_x + vec_y * vec_y);
    float normalized_x = vec_x / dist * 0.02;
    float normalized_y = vec_y / dist * 0.02;

    if (globals->sprite[i]->type == PAUL_FOLLOWING) {
        normalized_x *= 2;
        normalized_y *= 2;
    }
    if ((globals->sprite[i]->type == ZOMBIE && dist > 5) || dist < 0.5)
        return;
    if (globals->map->map[(int)(globals->sprite[i]->pos.x + normalized_x)]
        [(int)(globals->sprite[i]->pos.y)] == sfFalse)
        globals->sprite[i]->pos.x += normalized_x;
    if (globals->map->map[(int)(globals->sprite[i]->pos.x)]
        [(int)(globals->sprite[i]->pos.y + normalized_y)] == sfFalse)
        globals->sprite[i]->pos.y += normalized_y;
    if (globals->sprite[i]->type == PAUL_FOLLOWING)
        globals->has_paul = (dist < 8) ? 1 : 0;
}

void update_enemies(global_t *globals)
{
    for (int i = 0; i < globals->nb_sprite; i++) {
        if (globals->sprite[i]->type == ZOMBIE ||
            globals->sprite[i]->type == PAUL_FOLLOWING)
            update_single_enemy(globals, i);
    }
}
