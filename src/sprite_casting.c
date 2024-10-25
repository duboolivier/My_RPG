/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

static int compare(const void *a, const void *b)
{
    wrapper_t *wrap_a = (wrapper_t *)a;
    wrapper_t *wrap_b = (wrapper_t *)b;

    if (wrap_a->val_b < wrap_b->val_b)
        return 1;
    return -1;
}

static void sort_sprites(global_t *globals, int *order,
    double *distance, int amount)
{
    wrapper_t *wrap = malloc(sizeof(wrapper_t) * amount);

    for (int i = 0; i < globals->nb_sprite; i++) {
        globals->spriteOrder[i] = i;
        globals->spriteDistance[i] = ((globals->player->pos.x - globals->
            sprite[i]->pos.x) * (globals->player->pos.x - globals->sprite[i]->
            pos.x) + (globals->player->pos.y - globals->sprite[i]->pos.y) *
            (globals->player->pos.y - globals->sprite[i]->pos.y));
    }
    for (int i = 0; i < amount; i++) {
        wrap[i].val_a = (double)order[i];
        wrap[i].val_b = distance[i];
    }
    qsort(wrap, amount, sizeof(wrapper_t), compare);
    for (int i = 0; i < amount; i++) {
        order[i] = wrap[i].val_a;
        distance[i] = wrap[i].val_b;
    }
    free(wrap);
}

static math_t sprite_casting_maths(global_t *globals, math_t math, int i)
{
    math.spriteX = globals->sprite[globals->spriteOrder[i]]->pos.x -
        globals->player->pos.x;
    math.spriteY = globals->sprite[globals->spriteOrder[i]]->pos.y -
        globals->player->pos.y;
    math.invDet = 1.0 / (globals->player->plane.x * globals->player->dir.y -
        globals->player->dir.x * globals->player->plane.y);
    math.transformX = math.invDet * (globals->player->dir.y * math.spriteX -
        globals->player->dir.x * math.spriteY);
    math.transformY = math.invDet * (-(globals->player->plane.y) * math.spriteX
        + globals->player->plane.x * math.spriteY);
    math.spriteScreenX = (int)((globals->window->width / 2) *
        (1 + math.transformX / math.transformY));
    math.spriteHeight = abs((int)(globals->window->height /
        (math.transformY)));
    math.drawStartY = -math.spriteHeight / 2 + globals->window->height / 2;
    math.drawEndY = math.spriteHeight / 2 + globals->window->height / 2;
    math.spriteWidth = abs((int)(globals->window->height / (math.transformY)));
    math.drawStartX = -math.spriteWidth / 2 + math.spriteScreenX;
    math.drawEndX = math.spriteWidth / 2 + math.spriteScreenX;
    return math;
}

static int sprite_casting_is_close(global_t *globals,
    __attribute__((unused)) math_t math, int i)
{
    if (globals->sprite[globals->spriteOrder[i]]->type == DECO)
        return 0;
    if (globals->sprite[globals->spriteOrder[i]]->type == ZOMBIE) {
        if (globals->player->weapon_id == 0 && globals->spriteDistance[i] < 1)
            return 1;
        if (globals->player->weapon_id == 1)
            return 1;
        return 0;
    }
    if (globals->sprite[globals->spriteOrder[i]]->type > ZOMBIE) {
        if (globals->spriteDistance[i] < 1)
            return 1;
        return 0;
    }
    return 0;
}

static void sprite_casting_stripe(global_t *globals, math_t math,
    sfVector2i infos, sfRenderStates *states)
{
    int i = infos.x;
    int stripe = infos.y;

    math.texX = (int)(TEXHEIGHT * (stripe - (-math.spriteWidth / 2 +
        math.spriteScreenX)) * TEXHEIGHT / math.spriteWidth) / 256;
    states->texture = globals->sprite[globals->spriteOrder[i]]->texture;
    if (math.transformY > 0 && stripe > 0 && stripe < globals->window->width
        && math.transformY < globals->zbuffer[stripe]) {
        if (stripe == globals->window->width / 2 &&
            sprite_casting_is_close(globals, math, i))
            globals->player->is_looking_sprite = globals->spriteOrder[i] + 1;
        sfVertexArray_append(globals->ray, (sfVertex){(sfVector2f){stripe,
            math.drawStartY}, sfWhite, (sfVector2f){math.texX, 0}});
        sfVertexArray_append(globals->ray, (sfVertex){(sfVector2f){stripe,
            math.drawEndY}, sfWhite, (sfVector2f){math.texX, TEXHEIGHT}});
        sfRenderWindow_drawVertexArray(globals->window->window, globals->ray,
            states);
        sfVertexArray_clear(globals->ray);
    }
}

void sprite_casting(global_t *globals, sfRenderStates *states, math_t math)
{
    sfVertexArray_setPrimitiveType(globals->ray, sfLines);
    sort_sprites(globals, globals->spriteOrder,
        globals->spriteDistance, globals->nb_sprite);
    for (int i = 0; i < globals->nb_sprite; i++) {
        math = sprite_casting_maths(globals, math, i);
        if (math.drawStartX < 0)
            math.drawStartX = 0;
        if (math.drawEndX >= globals->window->width)
            math.drawEndX = globals->window->width - 1;
        for (int stripe = math.drawStartX; stripe < math.drawEndX; stripe++) {
            sprite_casting_stripe(globals, math,
                (sfVector2i){i, stripe}, states);
        }
    }
}
