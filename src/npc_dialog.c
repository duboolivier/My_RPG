/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

static char *read_line_from_dialog_file(int line)
{
    FILE *file = fopen("assets/dialog.npc", "r");
    char *buffer = NULL;
    size_t len = 0;
    int i = 0;

    if (file == NULL)
        return (NULL);
    while (i < line) {
        if (getline(&buffer, &len, file) == -1)
            return (NULL);
        i++;
    }
    fclose(file);
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '~')
            buffer[i] = '\n';
    return (buffer);
}

static char *npc_dialog_text(global_t *globals, int line)
{
    sfText *text = sfText_create();
    sfVector2f pos = {globals->window->width / 4 + 30,
        globals->window->height / 4 + 80};
    char *str = read_line_from_dialog_file(line);
    char *base_str = strdup(str);

    if (str[strlen(str) - 2] == '%') {
        memset(str + strlen(str) - 2, 0, 2);
        sfText_setString(text, str);
    } else
        sfText_setString(text, str);
    sfText_setFont(text, globals->dialog_font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(globals->window->window, text, NULL);
    sfText_destroy(text);
    free(str);
    return base_str;
}

static char *npc_dialog_box(global_t *globals, int line)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f size = {globals->window->width / 2,
        globals->window->height / 4};
    sfVector2f pos = {globals->window->width / 4, globals->window->height / 4};
    char *str = NULL;

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setTexture(rect, globals->dialog_texture, sfTrue);
    sfRenderWindow_drawRectangleShape(globals->window->window, rect, NULL);
    str = npc_dialog_text(globals, line);
    sfRenderWindow_display(globals->window->window);
    while (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue &&
        sfRenderWindow_isOpen(globals->window->window) == sfTrue)
        handle_event(globals, globals->window->event);
    while (sfKeyboard_isKeyPressed(sfKeyE) == sfFalse &&
        sfRenderWindow_isOpen(globals->window->window) == sfTrue)
        handle_event(globals, globals->window->event);
    sfRectangleShape_destroy(rect);
    return str;
}

static void npc_dialog_start(global_t *globals)
{
    int line = 0;
    char *str = NULL;

    globals->player->is_talking = 1;
    line = globals->sprite[globals->player->is_looking_sprite - 1]->line;
    str = npc_dialog_box(globals, line);
    while (str != NULL && str[strlen(str) - 2] == '%') {
        free(str);
        line++;
        str = npc_dialog_box(globals, line);
    }
    free(str);
}

void npc_dialog_ending_update(global_t *globals, sprite_t *sprite)
{
    if (sprite->type == PAUL) {
        globals->player->quest |= 3 << 1;
        quest_update_texture(globals, 2);
        sprite->type = PAUL_FOLLOWING;
        globals->has_paul = 1;
        return;
    }
    if (sprite->type == PAUL_FOLLOWING)
        sprite->line = 12;
    if ((sprite->type == MAGE && globals->has_paul == 1)
        || sfKeyboard_isKeyPressed(sfKeyB)) {
        globals->player->quest |= 4 << 1;
        quest_update_texture(globals, 3);
        sprite->line = 13;
    }
}

static void npc_dialog_update(global_t *globals)
{
    sprite_t *sprite = globals->sprite[globals->player->is_looking_sprite - 1];

    if (sprite->type == MAGE) {
        globals->player->quest |= 1 << 1;
        quest_update_texture(globals, 0);
    }
    if (sprite->type == CHEST) {
        globals->player->items |= 1 << 1;
        globals->player->quest |= 2 << 1;
        quest_update_texture(globals, 1);
        sfTexture_destroy(sprite->texture);
        sprite->texture = sfTexture_createFromFile(
            "assets/img/Coffre_open.png", NULL);
        sprite->type = DECO;
    }
    npc_dialog_ending_update(globals, sprite);
}

void npc_dialog(global_t *globals)
{
    if (globals->player->is_looking_sprite == 0 ||
        sfKeyboard_isKeyPressed(sfKeyE) == sfFalse) {
        globals->player->is_talking = 0;
        return;
    }
    if (globals->sprite[globals->player->is_looking_sprite - 1]->type >
        ZOMBIE && globals->player->is_talking == 0) {
        npc_dialog_update(globals);
        npc_dialog_start(globals);
    }
    if (globals->sprite[globals->player->is_looking_sprite - 1]->line == 13)
        ending_loop(globals);
}
