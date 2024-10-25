/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

static void destroy_final_save(global_t *globals)
{
    save_settings(globals);
}

static void destroy_global_sfml(global_t *globals)
{
    sfRenderWindow_close(globals->window->window);
    sfRenderWindow_destroy(globals->window->window);
    for (int i = 0; i < 4; i++)
        sfTexture_destroy(globals->wall_texture[i]);
    sfTexture_destroy(globals->bassirou_texture);
    sfTexture_destroy(globals->grass_texture);
    sfTexture_destroy(globals->floor_texture);
    sfSprite_destroy(globals->floor_sprite);
    sfFont_destroy(globals->dialog_font);
    sfSprite_destroy(globals->weapon->sprite);
    for (int i = 0; i < 4; i++) {
        sfTexture_destroy(globals->inven[i]->texture);
        sfSprite_destroy(globals->inven[i]->sprite);
        free(globals->inven[i]);
    }
}

static void destroy_free_arrays(global_t *globals)
{
    free(globals->zbuffer);
    free(globals->floor_texture_pixels);
    for (int i = 0; i < globals->map->height; i++)
        free(globals->map->map[i]);
    free(globals->map->map);
    free(globals->map);
    for (int i = 0; i < globals->nb_button && globals->buttons[i]; i++) {
        sfTexture_destroy(globals->buttons[i]->Texture);
        sfSprite_destroy(globals->buttons[i]->sprite);
        free(globals->buttons[i]);
    }
    for (int i = 0; i < globals->nb_sprite && globals->sprite[i]; i++) {
        sfTexture_destroy(globals->sprite[i]->texture);
        sfSprite_destroy(globals->sprite[i]->sprite);
        free(globals->sprite[i]);
    }
    for (int i = 0; i < 2; i++) {
        sfSoundBuffer_destroy(globals->sound_buffers[i]);
        sfSound_destroy(globals->sounds[i]);
    }
}

static void destroy_globals_player(global_t *globals)
{
    sfText_destroy(globals->player->xp_text);
    sfText_destroy(globals->player->hp_text);
    sfClock_destroy(globals->player->damage_clock);
    free(globals->player);
    sfTexture_destroy(globals->inventory->texture);
    sfSprite_destroy(globals->inventory->sprite);
    free(globals->inventory);
    sfTexture_destroy(globals->gun->texture);
    sfSprite_destroy(globals->gun->sprite);
    sfClock_destroy(globals->speedrun_clock);
    free(globals->gun);
}

void destroy_globals(global_t *globals)
{
    destroy_final_save(globals);
    destroy_free_arrays(globals);
    destroy_global_sfml(globals);
    destroy_globals_player(globals);
    sfTexture_destroy(globals->dialog_texture);
    free(globals->window);
    sfVertexArray_destroy(globals->ray);
    if (globals->math != NULL)
        free(globals->math);
    sfClock_destroy(globals->main_clock);
    sfTexture_destroy(globals->weapon->texture);
    sfTexture_destroy(globals->weapon->fired_texture);
    if (globals->weapon->clock != NULL)
        sfClock_destroy(globals->weapon->clock);
    free(globals->weapon);
    free(globals);
}
