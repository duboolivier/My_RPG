/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

static math_t floor_casting_maths(math_t math, global_t *globals, int y)
{
    math.p = y - globals->window->height / 2;
    math.rowDistance = math.posZ / math.p;
    math.rayDirX0 = globals->player->dir.x - globals->player->plane.x;
    math.rayDirY0 = globals->player->dir.y - globals->player->plane.y;
    math.rayDirX1 = globals->player->dir.x + globals->player->plane.x;
    math.rayDirY1 = globals->player->dir.y + globals->player->plane.y;
    math.floorStepX = math.rowDistance * (math.rayDirX1 - math.rayDirX0)
        / (globals->window->width / globals->quality);
    math.floorStepY = math.rowDistance * (math.rayDirY1 - math.rayDirY0)
        / (globals->window->width / globals->quality);
    math.floorX = globals->player->pos.x + math.rowDistance * math.rayDirX0;
    math.floorY = globals->player->pos.y + math.rowDistance * math.rayDirY0;
    return math;
}

static void floor_casting_append_ray(global_t *globals, math_t math)
{
    sfColor t_white = {100, 100, 100, 120};

    sfVertexArray_append(globals->ray, (sfVertex){(sfVector2f)
        {0, globals->window->height}, t_white, (sfVector2f){0, 0}});
    sfVertexArray_append(globals->ray, (sfVertex){(sfVector2f)
        {0, math.posZ}, sfBlack, (sfVector2f){0, 0}});
    sfVertexArray_append(globals->ray, (sfVertex){(sfVector2f){globals->
        window->width, math.posZ}, sfBlack, (sfVector2f){0, 0}});
    sfVertexArray_append(globals->ray, (sfVertex){(sfVector2f){globals->window
        ->width, globals->window->height}, t_white, (sfVector2f){0, 0}});
}

static void floor_casting_draw(global_t *globals, sfUint8 *floor_pixels,
    math_t math)
{
    floor_casting_append_ray(globals, math);
    sfTexture_updateFromPixels(globals->floor_texture, floor_pixels, globals->
        window->width, globals->window->height, 0, 0);
    sfRenderWindow_drawSprite(globals->window->window,
        globals->floor_sprite, NULL);
    sfRenderWindow_drawVertexArray(globals->window->window,
        globals->ray, NULL);
    if (globals->draw_ceilling) {
        sfSprite_setScale(globals->floor_sprite, (sfVector2f){1, -1});
        sfRenderWindow_drawSprite(globals->window->window,
            globals->floor_sprite, NULL);
        sfSprite_setScale(globals->floor_sprite, (sfVector2f){1, 1});
    }
}

static void floor_casting_horizontal(global_t *globals, sfUint8 *floor_pixels,
    math_t math, int y)
{
    int tx = 0;
    int ty = 0;

    for (int x = 0; x < globals->window->width; x += globals->quality) {
        tx = (int)(TEXHEIGHT * (math.floorX -
            (int)math.floorX)) & (TEXHEIGHT - 1);
        ty = (int)(TEXHEIGHT * (math.floorY -
            (int)math.floorY)) & (TEXHEIGHT - 1);
        math.floorX += math.floorStepX;
        math.floorY += math.floorStepY;
        floor_pixels[(x + y * globals->window->width) * 4] =
            globals->floor_texture_pixels[(ty * TEXHEIGHT + tx) * 4];
        floor_pixels[(x + y * globals->window->width) * 4 + 1] =
            globals->floor_texture_pixels[(ty * TEXHEIGHT + tx) * 4 + 1];
        floor_pixels[(x + y * globals->window->width) * 4 + 2] =
            globals->floor_texture_pixels[(ty * TEXHEIGHT + tx) * 4 + 2];
        floor_pixels[(x + y * globals->window->width) * 4 + 3] =
            globals->floor_texture_pixels[(ty * TEXHEIGHT + tx) * 4 + 3];
    }
}

void floor_casting(global_t *globals,
    __attribute__((unused)) sfRenderStates *states, math_t math)
{
    sfUint8 *floor_pixels = malloc(sizeof(sfUint8) *
        globals->window->width * globals->window->height * 4);

    math.posZ = 0.5 * globals->window->height;
    memset(floor_pixels, 0, sizeof(sfUint8) *
        globals->window->width * globals->window->height * 4);
    for (int y = math.posZ;
        y < globals->window->height; y += globals->quality) {
        math = floor_casting_maths(math, globals, y);
        floor_casting_horizontal(globals, floor_pixels, math, y);
    }
    sfVertexArray_clear(globals->ray);
    sfVertexArray_destroy(globals->ray);
    globals->ray = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(globals->ray, sfQuads);
    floor_casting_draw(globals, floor_pixels, math);
    free(floor_pixels);
}
