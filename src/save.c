/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

void save_settings(global_t *globals)
{
    FILE *file = fopen("settings", "w");

    if (file == NULL)
        return;
    fprintf(file, "%d\n", globals->volume);
    fprintf(file, "%d\n", globals->fps);
    fprintf(file, "%d\n", globals->window->is_fullscreen);
    fclose(file);
}

void load_settings(global_t *globals)
{
    FILE *file = fopen("settings", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    if (file == NULL)
        return;
    for (int i = 0; i < 2 && read != -1; i++) {
        read = getline(&line, &len, file);
        if (i == 0 && atoi(line) >= 0)
            globals->volume = atoi(line);
        if (i == 1 && atoi(line) >= 10)
            globals->fps = atoi(line);
        if (i == 2 && (atoi(line) == 0 || atoi(line) == 1))
            globals->window->is_fullscreen = atoi(line);
    }
    options_change_window(globals);
    fclose(file);
    if (line != NULL)
        free(line);
}

void save_game(global_t *globals)
{
    FILE *file = fopen("save", "w");

    if (file == NULL)
        return;
    fprintf(file, "%f\n", (float)globals->player->pos.x);
    fprintf(file, "%f\n", (float)globals->player->pos.y);
    fprintf(file, "%d\n", globals->player->health);
    fprintf(file, "%d\n", globals->player->items);
    fprintf(file, "%d\n", globals->player->quest);
    fclose(file);
    sfTexture_destroy(globals->buttons[31]->Texture);
    globals->buttons[31]->Texture = sfTexture_createFromFile(
        "assets/redlarge/save_completed.png", NULL);
    sfSprite_setTexture(globals->buttons[31]->sprite,
            globals->buttons[31]->Texture, sfTrue);
}

static void load_quests(global_t *globals)
{
    for (int i = 0; i < 4; i++) {
        if (globals->player->quest & (1 << i))
            quest_update_texture(globals, i);
    }
}

static void load_game_choose_line(global_t *globals, int i, char *line)
{
    if (i == 0 && atoi(line) >= 0)
        globals->player->pos.x = (float)atof(line);
    if (i == 1 && atoi(line) >= 0)
        globals->player->pos.y = (float)atof(line);
    if (i == 2 && atoi(line) >= 0)
        globals->player->health = atoi(line);
    if (i == 3)
        globals->player->items = atoi(line);
    if (i == 4)
        globals->player->quest = atoi(line);
}

void load_game(global_t *globals)
{
    FILE *file = fopen("save", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    if (file == NULL)
        return;
    for (int i = 0; i < 9 && read != -1; i++) {
        read = getline(&line, &len, file);
        load_game_choose_line(globals, i, line);
    }
    load_quests(globals);
    if (line != NULL)
        free(line);
    fclose(file);
}
