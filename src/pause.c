/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

static void pause_update_buttons(global_t *globals)
{
    for (int i = 24; i < 34; i++) {
        check_button(globals, globals->buttons[i],
            globals->buttons[i]->sprite);
        if (globals->buttons[i]->status != BTN_HOVER || i % 2 == 1)
            sfRenderWindow_drawSprite(globals->window->window,
                globals->buttons[i]->sprite, NULL);
        else
            sfRenderWindow_drawSprite(globals->window->window,
                globals->buttons[i + 1]->sprite, NULL);
    }
}

void handle_volume(global_t *globals)
{
    if (check_button_pressed(globals, 15) && globals->volume < 100) {
        globals->volume += 10;
        sfMusic_setVolume(globals->music_game, globals->volume);
    }
    if (check_button_pressed(globals, 17) && globals->volume > 0) {
        globals->volume -= 10;
        sfMusic_setVolume(globals->music_game, globals->volume);
    }
}

static void pause_check_buttons(global_t *globals)
{
    if (check_button_pressed(globals, 25))
        globals->player->is_paused = 0;
    if (check_button_pressed(globals, 27)) {
        while (check_button_pressed(globals, 3) == 1
            && sfRenderWindow_isOpen(globals->window->window))
            options_loop(globals);
        while (check_button_pressed(globals, 3) == 0
            && sfRenderWindow_isOpen(globals->window->window))
            options_loop(globals);
    }
    if (check_button_pressed(globals, 29)) {
        destroy_globals(globals);
        exit(0);
    }
    if (check_button_pressed(globals, 31))
        save_game(globals);
    if (check_button_pressed(globals, 33)) {
        load_game(globals);
        globals->player->is_paused = 0;
    }
}

void pause_loop(global_t *globals)
{
    sfRenderWindow_clear(globals->window->window, sfBlack);
    draw_particle(globals);
    pause_update_buttons(globals);
    while (sfRenderWindow_pollEvent(globals->window->window,
        &globals->event)) {
        pause_check_buttons(globals);
        if (globals->event.type == sfEvtClosed)
            sfRenderWindow_close(globals->window->window);
        if (globals->event.key.code == sfKeyEscape)
            sfRenderWindow_close(globals->window->window);
    }
    sfRenderWindow_display(globals->window->window);
}
