/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

static void time_to_str(char *str, sfInt64 time)
{
    int hours = time / 3600000000;
    int minutes = (time - hours * 3600000000) / 60000000;
    int seconds = (time - hours * 3600000000 - minutes * 60000000) / 1000000;

    sprintf(str, "%02d:%02d:%02d", hours, minutes, seconds);
}

static void ending_draw(global_t *globals, sfText *text, sfSprite *end_sp)
{
    sfRenderWindow_clear(globals->window->window, sfBlack);
    draw_particle(globals);
    while (sfRenderWindow_pollEvent(globals->window->window,
        &globals->event)) {
        if (globals->event.type == sfEvtClosed)
            sfRenderWindow_close(globals->window->window);
    }
    sfRenderWindow_drawSprite(globals->window->window, end_sp, NULL);
    sfRenderWindow_drawText(globals->window->window, text, NULL);
    sfRenderWindow_display(globals->window->window);
}

static void ending_setup_text(global_t *globals, sfText *text, char *str)
{
    time_to_str(str,
        sfClock_getElapsedTime(globals->speedrun_clock).microseconds);
    sfText_setString(text, str);
    sfText_setFont(text, globals->dialog_font);
    sfText_setColor(text, sfRed);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, (sfVector2f){1600, 900});
}

void ending_loop(global_t *globals)
{
    sfText *text = sfText_create();
    char *str = malloc(sizeof(char) * 9);
    sfTexture *end_tx = sfTexture_createFromFile(
        "assets/img/ending.png", NULL);
    sfSprite *end_sp = sfSprite_create();

    ending_setup_text(globals, text, str);
    sfSprite_setTexture(end_sp, end_tx, sfTrue);
    sfSprite_setScale(end_sp, (sfVector2f){1.42, 1.126});
    free(globals->math);
    while (sfRenderWindow_isOpen(globals->window->window) &&
        !sfKeyboard_isKeyPressed(sfKeyEscape))
        ending_draw(globals, text, end_sp);
    globals->math = malloc(sizeof(math_t) + 1);
    sfText_destroy(text);
    free(str);
    sfSprite_destroy(end_sp);
    sfTexture_destroy(end_tx);
}
