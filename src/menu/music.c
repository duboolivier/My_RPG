/*
** EPITECH PROJECT, 2023
** bassirou
** File description:
** music.c
*/

#include "myrpg.h"
#include "SFML/Audio.h"
#include <SFML/Audio/Types.h>

int menu_music(global_t *globals)
{
    globals->music_menu = sfMusic_createFromFile("assets/img/Video.ogg");
    if (!globals->music_menu)
        return -1;
    sfMusic_setLoop(globals->music_menu, sfTrue);
    sfMusic_setVolume(globals->music_menu, (float)globals->volume);
    sfMusic_play(globals->music_menu);
    return 0;
}

int game_music(global_t *globals)
{
    globals->music_game = sfMusic_createFromFile("assets/img/game_song.ogg");
    if (!globals->music_game)
        return -1;
    sfMusic_setLoop(globals->music_game, sfTrue);
    sfMusic_setVolume(globals->music_game, (float)globals->volume);
    return 0;
}
