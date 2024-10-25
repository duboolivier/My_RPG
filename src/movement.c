/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

void draw_crosshair(global_t *globals)
{
    sfColor col = (globals->player->is_looking_sprite > 0) ? sfRed : sfWhite;

    sfVertexArray_append(globals->ray, (sfVertex){(sfVector2f){globals->
        window->width / 2 - 10, globals->window->height / 2}, col, {0, 0}});
    sfVertexArray_append(globals->ray, (sfVertex){(sfVector2f){globals->
        window->width / 2 + 10, globals->window->height / 2}, col, {0, 0}});
    sfVertexArray_append(globals->ray, (sfVertex){(sfVector2f){globals->
        window->width / 2, globals->window->height / 2 - 10}, col, {0, 0}});
    sfVertexArray_append(globals->ray, (sfVertex){(sfVector2f){globals->
        window->width / 2, globals->window->height / 2 + 10}, col, {0, 0}});
    sfRenderWindow_drawVertexArray(globals->window->window,
        globals->ray, NULL);
    globals->player->is_looking_sprite = 0;
}

void mouse_movement(global_t *globals)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(globals->window->
        window);
    sfVector2i window_center = (sfVector2i){globals->window->width / 2,
        globals->window->height / 2};
    double dist = (window_center.x - mouse_pos.x) * 0.001;
    double oldDirX = globals->player->dir.x;
    double oldPlaneX = globals->player->plane.x;

    globals->player->dir.x = globals->player->dir.x * cos(dist) -
        globals->player->dir.y * sin(dist);
    globals->player->dir.y = oldDirX * sin(dist) + globals->player->dir.y *
        cos(dist);
    globals->player->plane.x = globals->player->plane.x * cos(dist) -
        globals->player->plane.y * sin(dist);
    globals->player->plane.y = oldPlaneX * sin(dist) +
        globals->player->plane.y * cos(dist);
}

void zqsd_movement(global_t *globals)
{
    double moveSpeed = (sfKeyboard_isKeyPressed(sfKeyZ)) ? 0.04 : -0.04;

    if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyS)) {
        if (globals->map->map[(int)(globals->player->pos.x + globals->player->
            dir.x * moveSpeed)][(int)(globals->player->pos.y)] == sfFalse)
            globals->player->pos.x += globals->player->dir.x * moveSpeed;
        if (globals->map->map[(int)(globals->player->pos.x)][(int)(globals->
            player->pos.y + globals->player->dir.y * moveSpeed)] == sfFalse)
            globals->player->pos.y += globals->player->dir.y * moveSpeed;
    }
    moveSpeed = (sfKeyboard_isKeyPressed(sfKeyD)) ? 0.04 : -0.04;
    if (sfKeyboard_isKeyPressed(sfKeyD) || sfKeyboard_isKeyPressed(sfKeyQ)) {
        if (globals->map->map[(int)(globals->player->pos.x + globals->player->
            plane.x * moveSpeed)][(int)(globals->player->pos.y)] == sfFalse)
            globals->player->pos.x += globals->player->plane.x * moveSpeed;
        if (globals->map->map[(int)(globals->player->pos.x)][(int)(globals->
            player->pos.y + globals->player->plane.y * moveSpeed)] == sfFalse)
            globals->player->pos.y += globals->player->plane.y * moveSpeed;
    }
}
