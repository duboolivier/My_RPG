/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

static void options_update_buttons(global_t *globals)
{
    for (int i = 8; i < 24; i++) {
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

static void options_display_text(global_t *globals)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font/dialog.ttf");
    char *str = my_itoa(globals->volume);

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, (sfVector2f){500, 500});
    sfRenderWindow_drawText(globals->window->window, text, NULL);
    free(str);
    str = my_itoa(globals->fps);
    sfText_setString(text, str);
    sfText_setPosition(text, (sfVector2f){500, 800});
    sfRenderWindow_drawText(globals->window->window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
    free(str);
}

static
void options_pause_volume(global_t *globals)
{
    if (check_button_pressed(globals, 13) && globals->player->is_paused == 1) {
        globals->volume = 0;
        sfMusic_setVolume(globals->music_game, globals->volume);
    }
    if (check_button_pressed(globals, 15) && globals->volume < 100 &&
        globals->player->is_paused == 1) {
        globals->volume += 10;
        sfMusic_setVolume(globals->music_game, globals->volume);
    }
    if (check_button_pressed(globals, 17) && globals->volume > 0 &&
        globals->player->is_paused == 1) {
        globals->volume -= 10;
        sfMusic_setVolume(globals->music_game, globals->volume);
    }
}

void options_sounds_update(global_t *globals)
{
    for (int i = 0; i < 2; i++) {
        if (globals->sounds[i] != NULL)
            sfSound_setVolume(globals->sounds[i], globals->volume);
    }
}

static void options_check_volume(global_t *globals)
{
    if (check_button_pressed(globals, 13)) {
        globals->volume = 0;
        sfMusic_setVolume(globals->music_menu, globals->volume);
        options_sounds_update(globals);
    }
    if (check_button_pressed(globals, 15) && globals->volume < 100) {
        globals->volume += 10;
        sfMusic_setVolume(globals->music_menu, globals->volume);
        options_sounds_update(globals);
    }
    if (check_button_pressed(globals, 17) && globals->volume > 0) {
        globals->volume -= 10;
        sfMusic_setVolume(globals->music_menu, globals->volume);
        options_sounds_update(globals);
    }
}

void options_change_window(global_t *globals)
{
    sfRenderWindow_close(globals->window->window);
    sfRenderWindow_destroy(globals->window->window);
    if (globals->window->is_fullscreen) {
        globals->window->settings = sfFullscreen;
    } else {
        globals->window->settings = sfClose;
    }
    globals->window->window = sfRenderWindow_create(globals->window->mode,
        "myrpg", globals->window->settings, NULL);
    if (globals->window->is_fullscreen) {
        sfRenderWindow_setSize(globals->window->window, (sfVector2u)
            {1920, 1080});
    } else {
        sfRenderWindow_setSize(globals->window->window, (sfVector2u)
            {1280, 720});
    }
    SETFRAMERATELIMIT(globals->window->window, globals->fps);
}

static void options_check_buttons(global_t *globals)
{
    if (globals->player->is_paused == 1)
        options_pause_volume(globals);
    else
        options_check_volume(globals);
    if (check_button_pressed(globals, 19)) {
        globals->window->is_fullscreen = !globals->window->is_fullscreen;
        options_change_window(globals);
    }
    if (check_button_pressed(globals, 21) && globals->fps < 240) {
        globals->fps += 10;
        SETFRAMERATELIMIT(globals->window->window, globals->fps);
    }
    if (check_button_pressed(globals, 23) && globals->fps > 10) {
        globals->fps -= 10;
        SETFRAMERATELIMIT(globals->window->window, globals->fps);
    }
    if (check_button_pressed(globals, 9))
        help_anim(globals);
}

void options_loop(global_t *globals)
{
    sfRenderWindow_clear(globals->window->window, sfBlack);
    draw_particle(globals);
    options_update_buttons(globals);
    options_display_text(globals);
    while (sfRenderWindow_pollEvent(globals->window->window,
        &globals->event)) {
        options_check_buttons(globals);
        if (globals->event.type == sfEvtClosed)
            sfRenderWindow_close(globals->window->window);
    }
    sfRenderWindow_display(globals->window->window);
}
