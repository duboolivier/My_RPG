/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "../includes/myrpg.h"
#include <SFML/Graphics/RenderWindow.h>

int main(int ac, char **av, char **env)
{
    global_t *globals = NULL;

    if (env_display_find(env) == 0 || file_check())
        return (84);
    if (dash_h(ac, av))
        return (0);
    if (ac != 1 || av == NULL || env == NULL)
        return 84;
    globals = setup_globals();
    menu_music(globals);
    splash_screen(globals);
    while (sfRenderWindow_isOpen(globals->window->window)) {
        main_menu_loop(globals);
    }
    destroy_globals(globals);
    return (0);
}
