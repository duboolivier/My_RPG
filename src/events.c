/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include <myrpg.h>
#include <stdbool.h>

static void handle_event_weaopn_switch(global_t *globals, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyNum2 &&
        (globals->player->items >> 1) & 1)
        weapon_switch(globals, "assets/img/pistol1.png",
            "assets/img/pistol3.png", 1);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyNum1)
        weapon_switch(globals, "assets/img/punch1.png",
            "assets/img/punch2.png", 0);
}

static void handle_event_setup_pause(global_t *globals)
{
    sfTexture_destroy(globals->buttons[31]->Texture);
    globals->buttons[31]->Texture = sfTexture_createFromFile(
        "assets/redlarge/save.png", NULL);
    sfSprite_setTexture(globals->buttons[31]->sprite,
        globals->buttons[31]->Texture, sfTrue);
    sfRenderWindow_setMouseCursorVisible(globals->window->window, sfTrue);
    sfRenderWindow_setMouseCursorGrabbed(globals->window->window, sfFalse);
    globals->player->is_paused = 1;
    while (sfKeyboard_isKeyPressed(sfKeyP) && globals->player->is_paused &&
        sfRenderWindow_isOpen(globals->window->window))
        pause_loop(globals);
    while (!sfKeyboard_isKeyPressed(sfKeyP) && globals->player->is_paused
        && sfRenderWindow_isOpen(globals->window->window))
        pause_loop(globals);
}

static void handle_event_pause(global_t *globals, sfEvent event)
{
    if (event.type != sfEvtKeyPressed || event.key.code != sfKeyP)
        return;
    if (globals->player->is_paused ||
        sfKeyboard_isKeyPressed(sfKeyP) == sfFalse) {
        globals->player->is_paused = 0;
        return;
    }
    if (globals->player->is_paused == 0) {
        handle_event_setup_pause(globals);
        free(globals->math);
        globals->math = malloc(sizeof(math_t) + 1);
    }
}

static
bool process_help_event(__attribute__((unused)) global_t *globals,
    sfEvent event)
{
    if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyEscape) ||
        sfMouse_isButtonPressed(sfMouseLeft)) {
        return true;
    }
    return false;
}

void help_anim(global_t *globals)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("assets/help.jpg", NULL);
    sfEvent event;

    sfSprite_setScale(sprite, (sfVector2f){0.547320, 0.435484});
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(globals->window->window)) {
        if (sfRenderWindow_pollEvent(globals->window->window, &event) &&
            process_help_event(globals, event)) {
            return;
        }
        sfRenderWindow_clear(globals->window->window, sfBlack);
        sfRenderWindow_drawSprite(globals->window->window, sprite, NULL);
        sfRenderWindow_display(globals->window->window);
    }
}

void handle_event(global_t *globals, sfEvent event)
{
    sfVector2i window_center = (sfVector2i){globals->window->width / 2,
        globals->window->height / 2};

    while (sfRenderWindow_pollEvent(globals->window->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(globals->window->window);
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(globals->window->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyC)
            globals->draw_ceilling = !globals->draw_ceilling;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEqual
            && globals->quality < 3)
            globals->quality++;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDash
            && globals->quality > 1)
            globals->quality--;
        handle_event_pause(globals, event);
        handle_event_weaopn_switch(globals, event);
    }
    sfMouse_setPositionRenderWindow(window_center, globals->window->window);
}
