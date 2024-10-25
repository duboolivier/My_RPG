/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

int dash_h(int argc, char **argv)
{
    if (argc < 1 || argc > 2 || argv[0] == NULL || argv[1] == NULL)
        return 0;
    if (strncmp(argv[1], "-h", 2) != 0 || strlen(argv[1]) != 2)
        return 0;
    puts("\t\"Labyrinthe des ombres\"\n\n"
        "A RPG game made with the CSFML library.\n"
        "Made By Robin CHASSAGNE, Olivier DUBO, Tiziano BLANC, Arthur COMET\n"
        "Epitech 2023-2024\n"
        "USAGE\n\t./my_rpg [-h]\n"
        "DESCRIPTION\n\t-h\tprint the usage and quit.");
    return 1;
}
