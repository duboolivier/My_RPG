/*
** EPITECH PROJECT, 2023
** bassirou
** File description:
** main_menu.c
*/

#include "../../includes/myrpg.h"
#include "SFML/Audio.h"
#include <SFML/Audio/Music.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>

int check_button_pressed(global_t *globals, int id)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(globals->
        window->window);
    sfFloatRect startBounds = sfSprite_getGlobalBounds(globals->
        buttons[id]->sprite);
    sfVector2u win_size = sfRenderWindow_getSize(globals->window->window);

    mousePos.x = mousePos.x * globals->window->width / win_size.x;
    mousePos.y = mousePos.y * globals->window->height / win_size.y;
    if (globals->event.type == sfEvtMouseButtonReleased) {
        if (sfFloatRect_contains(&startBounds, mousePos.x, mousePos.y)) {
            globals->buttons[id]->status = BTN_PRESSED;
            return 1;
        }
    }
    return 0;
}

static void check_buttons_start(global_t *globals)
{
    if (check_button_pressed(globals, 1) || check_button_pressed(globals, 7)) {
        sfMusic_stop(globals->music_menu);
        sfMusic_destroy(globals->music_menu);
        sfRenderWindow_close(globals->window->window);
        destroy_globals(globals);
        globals = setup_globals();
        game_music(globals);
        sfMusic_play(globals->music_game);
        if (check_button_pressed(globals, 7))
            load_game(globals);
        raycasting(globals);
        exit(0);
    }
}

void check_buttons(global_t *globals)
{
    check_buttons_start(globals);
    if (check_button_pressed(globals, 3)) {
        while (check_button_pressed(globals, 3) == 1
            && sfRenderWindow_isOpen(globals->window->window))
            options_loop(globals);
        while (check_button_pressed(globals, 3) == 0
            && sfRenderWindow_isOpen(globals->window->window))
            options_loop(globals);
    }
    if (check_button_pressed(globals, 9)) {
        help_anim(globals);
    }
    if (check_button_pressed(globals, 5))
        sfRenderWindow_close(globals->window->window);
}

static
void background_menu(sfTexture **textures)
{
    textures[0] = sfTexture_createFromFile("assets/mnu/blood_1.jpg", NULL);
    textures[1] = sfTexture_createFromFile("assets/mnu/blood_2.jpg", NULL);
    textures[2] = sfTexture_createFromFile("assets/mnu/blood_3.jpg", NULL);
    textures[3] = sfTexture_createFromFile("assets/mnu/blood_4.jpg", NULL);
    textures[4] = sfTexture_createFromFile("assets/mnu/blood_5.jpg", NULL);
    textures[5] = sfTexture_createFromFile("assets/mnu/blood_6.jpg", NULL);
    textures[6] = sfTexture_createFromFile("assets/mnu/blood_7.jpg", NULL);
    textures[7] = sfTexture_createFromFile("assets/mnu/blood_8.jpg", NULL);
}

void draw_particle(global_t *globals)
{
    static sfTexture *textures[8] = {NULL, NULL, NULL};
    static sfSprite *sprite = NULL;
    static sfClock *clock = NULL;
    static int index = 0;

    if (sprite == NULL) {
        background_menu(textures);
        sprite = sfSprite_create();
        clock = sfClock_create();
    }
    if (sfClock_getElapsedTime(clock).microseconds > 160000) {
        sfSprite_setTexture(sprite, textures[index], sfTrue);
        index++;
        if (index == 8)
            index = 0;
        sfClock_restart(clock);
    }
    sfRenderWindow_drawSprite(globals->window->window, sprite, NULL);
}
