/*
** EPITECH PROJECT, 2023
** bassirou2
** File description:
** button_status.c
*/

#include "../../includes/myrpg.h"
#include <SFML/Config.h>
#include <SFML/Graphics/RenderWindow.h>

sfBool is_button_hovered(global_t *globals, sfSprite *sprite)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(globals->window->
        window);
    sfVector2u win_size = sfRenderWindow_getSize(globals->window->window);

    mousePos.x = mousePos.x * globals->window->width / win_size.x;
    mousePos.y = mousePos.y * globals->window->height / win_size.y;
    if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y))
        return sfTrue;
    return sfFalse;
}

void check_button(global_t *globals, button_t *buttons, sfSprite *sprite)
{
    if (is_button_hovered(globals, sprite) == sfTrue) {
        buttons->status = BTN_HOVER;
    } else {
        buttons->status = BTN_NORMAL;
    }
}
