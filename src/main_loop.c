/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "../includes/myrpg.h"

static void main_menu_update_buttons(global_t *globals)
{
    for (int i = 0; i < 10; i++) {
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

void main_menu_loop(global_t *globals)
{
    sfRenderWindow_clear(globals->window->window, sfBlack);
    draw_particle(globals);
    main_menu_update_buttons(globals);
    while (sfRenderWindow_pollEvent(globals->window->window,
                                    &globals->event)) {
        if (globals->event.type == sfEvtClosed)
            sfRenderWindow_close(globals->window->window);
        check_buttons(globals);
    }
    sfRenderWindow_display(globals->window->window);
}
