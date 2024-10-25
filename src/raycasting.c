/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

static void raycasting_draw_line(global_t *globals, sfRenderStates states,
    math_t math, int x)
{
    int lineHeight = abs((int)(globals->window->height / math.perpWallDist));
    int drawStart = -lineHeight / 2 + globals->window->height / 2;
    int drawEnd = lineHeight / 2 + globals->window->height / 2;
    sfColor color = (math.side == 1) ? (sfColor){127, 127, 127, 255} : sfWhite;

    states.texture = globals->wall_texture[globals->map->map[math.mapX]
        [math.mapY] - 1];
    math.disted = (1 - 0.05 * math.perpWallDist);
    math.disted = (math.disted < 0) ? 0 : math.disted;
    color = (sfColor){color.r * math.disted, color.g * math.disted,
        color.b * math.disted, 255};
    for (int i = 0; i < globals->quality; i++) {
        sfVertexArray_append(globals->ray, (sfVertex){{x + i, drawStart},
            color, {math.texX, 0}});
        sfVertexArray_append(globals->ray, (sfVertex){{x + i, drawEnd},
            color, {math.texX, TEXHEIGHT}});
    }
    sfRenderWindow_drawVertexArray(globals->window->window,
        globals->ray, &states);
    sfVertexArray_clear(globals->ray);
}

static math_t calculate_ray_direction(global_t *globals, int x, math_t math)
{
    math.cameraX = 2 * x / (double)(globals->window->width) - 1;
    math.rayPosX = globals->player->pos.x;
    math.rayPosY = globals->player->pos.y;
    math.rayDirX = globals->player->dir.x +
        globals->player->plane.x * math.cameraX;
    math.rayDirY = globals->player->dir.y +
        globals->player->plane.y * math.cameraX;
    math.mapX = math.rayPosX;
    math.mapY = math.rayPosY;
    math.deltaDistX = sqrt(1 + (math.rayDirY * math.rayDirY) /
        (math.rayDirX * math.rayDirX));
    math.deltaDistY = sqrt(1 + (math.rayDirX * math.rayDirX) /
        (math.rayDirY * math.rayDirY));
    return math;
}

static math_t calculate_step_and_side_dist(math_t math)
{
    if (math.rayDirX < 0) {
        math.stepX = -1;
        math.sideDistX = (math.rayPosX - math.mapX) * math.deltaDistX;
    } else {
        math.stepX = 1;
        math.sideDistX = (math.mapX + 1.0 - math.rayPosX) * math.deltaDistX;
    }
    if (math.rayDirY < 0) {
        math.stepY = -1;
        math.sideDistY = (math.rayPosY - math.mapY) * math.deltaDistY;
    } else {
        math.stepY = 1;
        math.sideDistY = (math.mapY + 1.0 - math.rayPosY) * math.deltaDistY;
    }
    return math;
}

static math_t perform_dda(global_t *globals, math_t math)
{
    math.hit = 0;
    while (math.hit == 0) {
        if (math.sideDistX < math.sideDistY) {
            math.sideDistX += math.deltaDistX;
            math.mapX += math.stepX;
            math.side = 0;
        } else {
            math.sideDistY += math.deltaDistY;
            math.mapY += math.stepY;
            math.side = 1;
        }
        if (globals->map->map[math.mapX][math.mapY] > 0)
            math.hit = 1;
    }
    return math;
}

static math_t calculate_wall_distance_and_texture(math_t math)
{
    if (math.side == 0)
        math.perpWallDist = fabs((math.mapX - math.rayPosX +
            (1 - math.stepX) / 2) / math.rayDirX);
    else
        math.perpWallDist = fabs((math.mapY - math.rayPosY +
            (1 - math.stepY) / 2) / math.rayDirY);
    if (math.side == 0)
        math.wallX = math.rayPosY + math.perpWallDist * math.rayDirY;
    else
        math.wallX = math.rayPosX + math.perpWallDist * math.rayDirX;
    math.wallX -= floor(math.wallX);
    math.texX = (math.wallX * TEXHEIGHT);
    if (math.side == 0 && math.rayDirX > 0)
        math.texX = TEXHEIGHT - math.texX - 1;
    if (math.side == 1 && math.rayDirY < 0)
        math.texX = TEXHEIGHT - math.texX - 1;
    return math;
}

static math_t raycasting_math_line(global_t *globals, int x, math_t math)
{
    math = calculate_ray_direction(globals, x, math);
    math = calculate_step_and_side_dist(math);
    math = perform_dda(globals, math);
    math = calculate_wall_distance_and_texture(math);
    return math;
}

static void main_loop_player(global_t *globals)
{
    mouse_movement(globals);
    zqsd_movement(globals);
    weapon_draw(globals);
    inventory(globals);
    health_draw(globals);
    level_draw(globals);
    npc_dialog(globals);
    if (((globals->player->items >> 1) & 1) && sfKeyboard_isKeyPressed(sfKeyI))
        sfRenderWindow_drawSprite(globals->window->window,
            globals->gun->sprite, NULL);
    draw_crosshair(globals);
}

static void main_loop(global_t *globals, sfRenderStates states, math_t math)
{
    sfRenderWindow_setMouseCursorGrabbed(globals->window->window, sfTrue);
    sfRenderWindow_setMouseCursorVisible(globals->window->window, sfFalse);
    update_enemies(globals);
    floor_casting(globals, &states, *globals->math);
    sfVertexArray_setPrimitiveType(globals->ray, sfLines);
    for (int x = 0; x < globals->window->width; x += globals->quality) {
        math = raycasting_math_line(globals, x, math);
        raycasting_draw_line(globals, states, math, x);
        for (int i = 0; i < globals->quality; i++)
            globals->zbuffer[x + i] = math.perpWallDist;
    }
    sprite_casting(globals, &states, *globals->math);
    main_loop_player(globals);
    sfRenderWindow_display(globals->window->window);
}

void raycasting(global_t *globals)
{
    sfRenderStates states = {0};

    states.blendMode = sfBlendAlpha;
    states.shader = NULL;
    states.transform = sfTransform_Identity;
    while (sfRenderWindow_isOpen(globals->window->window)) {
        while (sfTime_asMilliseconds(sfClock_getElapsedTime(globals->
            main_clock)) < 10)
            continue;
        sfClock_restart(globals->main_clock);
        sfRenderWindow_clear(globals->window->window, sfBlack);
        handle_event(globals, globals->window->event);
        main_loop(globals, states, *globals->math);
        if (globals->player->health <= 0) {
            destroy_globals(globals);
            globals = setup_globals();
        }
    }
    destroy_globals(globals);
}
