/*
** EPITECH PROJECT, 2023
** bassirou
** File description:
** init_button.c
*/

#include "../../includes/myrpg.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

static const char *button_path[35] = {
    "assets/redlarge/New Game  col_Button.png",
    "assets/redlarge/New Game  col_Button.png",
    "assets/redlarge/options.png",
    "assets/redlarge/options.png",
    "assets/redlarge/quit.png",
    "assets/redlarge/quit.png",
    "assets/redlarge/Load  col_Button.png",
    "assets/redlarge/Load  col_Button.png",
    "assets/redsquare/help.png",
    "assets/redsquare/help.png",
    "assets/redlarge/options.png",
    "assets/redlarge/options.png",
    "assets/redsquare/Audio col_Square Button.png",
    "assets/redsquare/Audio col_Square Button.png",
    "assets/redsquare/Up col_Square Button.png",
    "assets/redsquare/Up col_Square Button.png",
    "assets/redsquare/Down col_Square Button.png",
    "assets/redsquare/Down col_Square Button.png",
    "assets/redsquare/Home col_Square Button.png",
    "assets/redsquare/Home col_Square Button.png",
    "assets/redsquare/Up col_Square Button.png",
    "assets/redsquare/Up col_Square Button.png",
    "assets/redsquare/Down col_Square Button.png",
    "assets/redsquare/Down col_Square Button.png",
    "assets/redlarge/Continue  col_Button.png",
    "assets/redlarge/Continue  col_Button.png",
    "assets/redlarge/options.png",
    "assets/redlarge/options.png",
    "assets/redlarge/Exit  col_Button.png",
    "assets/redlarge/Exit  col_Button.png",
    "assets/redlarge/save.png",
    "assets/redlarge/save.png",
    "assets/redlarge/Load  col_Button.png",
    "assets/redlarge/Load  col_Button.png"
};

static const sfVector2f button_pos[35] = {
    {650, 250},
    {658, 248},
    {1250, 50},
    {1258, 48},
    {650, 800},
    {658, 798},
    {650, 500},
    {658, 498},
    {10, 40},
    {18, 38},
    {1250, 50},
    {1258, 48},
    {650, 450},
    {658, 448},
    {850, 450},
    {858, 448},
    {1050, 450},
    {1058, 448},
    {650, 750},
    {658, 748},
    {850, 750},
    {858, 748},
    {1050, 750},
    {1058, 748},
    {650, 10},
    {658, 8},
    {650, 640},
    {658, 638},
    {650, 850},
    {658, 848},
    {650, 220},
    {658, 218},
    {650, 430},
    {658, 428}
};

static void create_button(global_t *globals, const char *path, int i)
{
    button_t *button = malloc(sizeof(button_t));

    button->Texture = sfTexture_createFromFile(path, NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->Texture, sfTrue);
    sfSprite_setPosition(button->sprite, button_pos[i]);
    globals->buttons[i] = button;
    globals->nb_button += 1;
}

static void create_all_buttons(global_t *globals)
{
    for (int i = 0; i < 34; i++)
        create_button(globals, button_path[i], i);
}

void call_buttons(global_t *globals)
{
    create_all_buttons(globals);
}
