/*
** EPITECH PROJECT, 2023
** bassirou
** File description:
** env_error.c
*/

#include "../../includes/myrpg.h"

int env_display_find(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        if (strncmp(env[i], "DISPLAY", 7) == 0)
            return (1);
        i++;
    }
    return (0);
}
