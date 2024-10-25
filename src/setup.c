/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

const int worldMap[43][42] = {
    {1, 3, 2, 1, 1, 3, 2, 1, 1, 3, 2, 1, 1, 3, 2, 1,
        1, 3, 2, 1, 1, 3, 2, 1, 1, 3, 2, 1, 1, 3, 2, 1,
        1, 3, 2, 1, 1, 3, 2, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 3, 2, 2, 0, 4, 0, 4, 0, 0, 3, 3, 2, 1, 1, 1,
        1, 1, 4, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 2, 0, 4, 1, 1, 0, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 0, 0, 3, 0, 1, 3, 2, 1,
        1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 3, 2, 4, 0, 0, 3},
    {1, 3, 2, 2, 0, 4, 0, 0, 0, 4, 0, 0, 3, 0, 1, 0, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        1, 0, 0, 0, 1, 3, 2, 1, 1, 1, 0, 0, 0, 4, 0, 0, 3},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 1, 0, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        1, 3, 2, 1, 1, 0, 0, 0, 0, 2, 0, 4, 1, 4, 0, 0, 3},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        1, 3, 2, 1, 2, 0, 4, 2, 0, 4, 0, 1, 0, 0, 0, 0, 1},
    {1, 2, 0, 4, 3, 2, 1, 1, 1, 4, 0, 0, 3, 0, 0, 0, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        1, 3, 2, 1, 1, 0, 4, 0, 0, 3, 1, 4, 0, 0, 3, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        1, 3, 2, 1, 2, 0, 4, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {4, 0, 0, 3, 0, 1, 3, 2, 1, 1, 3, 2, 1, 0, 0, 0, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        1, 3, 2, 1, 1, 1, 1, 0, 0, 0, 0, 1, 3, 2, 1, 1, 1},
    {4, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        4, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 4, 1},
    {4, 0, 0, 3, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        4, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 4, 1},
    {4, 0, 0, 3, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        4, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 4, 1},
    {4, 0, 0, 3, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        4, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 3, 2, 2, 0, 4, 3, 2, 1, 1, 3, 2, 1, 1, 3, 2, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        4, 0, 0, 3, 3, 2, 1, 1, 0, 0, 0, 0, 1, 3, 2, 1, 1},
    {4, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {4, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        1, 3, 2, 1, 1, 3, 2, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {4, 0, 0, 3, 0, 1, 3, 2, 1, 1, 3, 2, 1, 1, 3, 2, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {4, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1},
    {4, 0, 0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 2, 0, 4, 3, 2, 1, 1, 0, 0, 0, 0, 1, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        1, 3, 2, 1, 1, 0, 0, 0, 0, 0, 0, 1, 3, 2, 1, 1, 1},
    {1, 0, 0, 0, 2, 0, 4, 3, 2, 1, 1, 0, 0, 0, 0, 1, 4, 0, 0, 3, 0, 1, 0, 0, 0,
        1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 3},
    {1, 0, 0, 0, 2, 0, 4, 3, 2, 1, 1, 0, 0, 0, 0, 1, 2, 0, 4, 2, 0, 4, 1, 0, 0,
        1, 0, 0, 0, 0, 0, 1, 3, 2, 1, 4, 0, 0, 3, 0, 0, 1},
    {1, 0, 0, 0, 2, 0, 4, 3, 2, 1, 1, 0, 0, 0, 0, 1, 2, 0, 4, 0, 0, 0, 1, 0, 0,
        1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 2, 1},
    {1, 3, 2, 1, 2, 0, 4, 3, 2, 1, 1, 3, 2, 1, 1, 1, 2, 0, 4, 0, 0, 0, 1, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 3, 2, 1, 2, 0, 4, 3, 2, 1, 1, 3, 2, 1, 1, 1, 2, 0, 4, 0, 0, 0, 1, 0, 0,
        1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 3, 2, 1, 2, 0, 4, 3, 2, 1, 1, 3, 2, 1, 1, 1, 2, 0, 4, 0, 0, 0, 1, 0, 0,
        2, 0, 4, 3, 2, 1, 0, 0, 0, 0, 4, 0, 0, 3, 3, 2, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 2, 1, 1, 3, 2, 2, 0, 4, 0, 0, 0, 1, 0, 0,
        2, 0, 4, 1, 0, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 0, 2, 0, 4, 3, 2, 1, 1, 0, 0,
        2, 0, 4, 1, 0, 0, 0, 4, 0, 0, 3, 0, 0, 1, 3, 2, 1},
    {1, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        2, 0, 4, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        2, 0, 4, 2, 0, 4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 0, 1, 3, 2, 1, 1, 3, 2, 1, 1,
        2, 0, 4, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        2, 0, 4, 1, 0, 0, 0, 0, 0, 0, 4, 0, 0, 3, 3, 2, 1},
    {1, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 4, 0, 0, 3},
    {4, 0, 0, 3, 3, 2, 4, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 3, 2, 1, 1, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 1},
    {4, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 2, 1},
    {4, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 3, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {4, 0, 0, 3, 3, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 3, 2, 1, 1, 3, 2, 1, 1,
        1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 3, 2, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 3, 0, 0, 0, 1},
    {1, 3, 2, 1, 1, 3, 2, 1, 1, 3, 2, 1, 1, 3, 2, 1, 1, 3, 2, 1, 1, 3, 2, 1, 1,
        1, 3, 2, 1, 1, 3, 2, 1, 1, 3, 2, 1, 1, 3, 2, 1, 1}};

const dict_t sprite_textures[8] = {
        {ZOMBIE, "assets/img/zombie.png"},
        {CHEST, "assets/img/Coffre.png"},
        {MAGE, "assets/img/mage.png"},
        {PAUL, "assets/img/paul.png"},
        {PAUL_FOLLOWING, "assets/img/paul.png"},
        {SKULLS, "assets/img/skulls.png"},
        {GRAVE, "assets/img/grave.png"}};

const int sprites_list[56][4] = {
        {38, 2, ZOMBIE}, {40, 5, ZOMBIE}, {41, 6, ZOMBIE},
        {41, 7, ZOMBIE}, {41, 9, ZOMBIE}, {41, 10, ZOMBIE}, {42, 7, ZOMBIE},
        {41, 9, ZOMBIE}, {40, 10, ZOMBIE}, {36, 23, ZOMBIE}, {34, 21, ZOMBIE},
        {36, 20, ZOMBIE}, {40, 29, ZOMBIE}, {39, 31, ZOMBIE}, {39, 31, ZOMBIE},
        {30, 31, ZOMBIE}, {28, 31, ZOMBIE}, {28, 34, ZOMBIE}, {29, 32, ZOMBIE},
        {36, 23, ZOMBIE}, {34, 21, ZOMBIE}, {36, 20, ZOMBIE}, {40, 29, ZOMBIE},
        {39, 31, ZOMBIE}, {39, 31, ZOMBIE}, {30, 31, ZOMBIE}, {28, 31, ZOMBIE},
        {28, 34, ZOMBIE}, {29, 32, ZOMBIE}, {26, 32, ZOMBIE}, {26, 33, ZOMBIE},
        {28, 31, ZOMBIE}, {29, 31, ZOMBIE}, {24, 33, ZOMBIE}, {20, 31, ZOMBIE},
        {19, 34, ZOMBIE}, {15, 31, ZOMBIE}, {18, 33, ZOMBIE}, {12, 32, ZOMBIE},
        {11, 35, ZOMBIE}, {10, 39, ZOMBIE}, {9, 37, ZOMBIE}, {8, 35, ZOMBIE},
        {7, 35, ZOMBIE}, {6, 35, ZOMBIE}, {5, 35, ZOMBIE},
        {12, 12, CHEST, 1}, {2, 2, MAGE, 3}, {26, 20, PAUL, 10},
        {3, 7, SKULLS}, {20, 12, GRAVE}, {26, 21, SKULLS}, {41, 2, GRAVE},
        {20, 40, SKULLS}, {35, 35, GRAVE}};

    static void create_map(global_t *globals)
{
    globals->map = malloc(sizeof(map_t) + 1);
    globals->map->map = malloc(sizeof(int *) * 43);
    memset(globals->map->map, 0, sizeof(int *) * 42);
    globals->map->width = 42;
    globals->map->height = 43;
    for (int i = 0; i < 43; i++) {
        globals->map->map[i] = malloc(sizeof(int) * 42);
        memset(globals->map->map[i], 0, sizeof(int) * 42);
        for (int j = 0; j < 42; j++) {
            globals->map->map[i][j] = worldMap[i][j];
        }
    }
    }

    void create_sprite(global_t *globals, const char *path,
        sfVector2f pos, sfVector2i info)
{
    sprite_t *spr = malloc(sizeof(sprite_t));

    if (path == NULL)
        path = "assets/img/kevin.png";
    spr->texture = sfTexture_createFromFile(path, NULL);
    spr->sprite = sfSprite_create();
    sfSprite_setTexture(spr->sprite, spr->texture, sfTrue);
    spr->pos = pos;
    spr->type = info.x;
    spr->line = info.y;
    spr->damage = 0;
    globals->sprite[globals->nb_sprite] = spr;
    globals->nb_sprite += 1;
    }

    static void setup_all_sprites(global_t *globals)
{
    char *path = NULL;

    for (int i = 0; i < 54; i++) {
        for (int j = 0; j < 7; j++) {
            path = (sprites_list[i][2] == sprite_textures[j].key) ?
                sprite_textures[j].value : path;
        }
        create_sprite(globals, path, (sfVector2f)
            {sprites_list[i][0], sprites_list[i][1]}, (sfVector2i)
            {sprites_list[i][2], sprites_list[i][3]});
    }
    }

    static void create_floor_texure_pixels(global_t *globals)
{
    sfColor col;
    sfImage *floor_image = sfImage_createFromFile("assets/img/pitted.png");

    globals->floor_texture_pixels = malloc(sizeof(sfUint8) *
        TEXHEIGHT * TEXHEIGHT * 4);
    for (int y = 0; y < TEXHEIGHT; y++) {
        for (int x = 0; x < TEXHEIGHT; x++) {
            col = sfImage_getPixel(floor_image, x, y);
            globals->floor_texture_pixels[(y * TEXHEIGHT + x) * 4] = col.r;
            globals->floor_texture_pixels[(y * TEXHEIGHT + x) * 4 + 1] = col.g;
            globals->floor_texture_pixels[(y * TEXHEIGHT + x) * 4 + 2] = col.b;
            globals->floor_texture_pixels[(y * TEXHEIGHT + x) * 4 + 3] = col.a;
        }
    }
    sfImage_destroy(floor_image);
    }

    void setup_window(global_t *globals)
{
    globals->window = malloc(sizeof(window_t));
    globals->window->width = 1920;
    globals->window->height = 1080;
    globals->window->mode = (sfVideoMode){globals->window->width,
        globals->window->height, 32};
    globals->window->is_fullscreen = 1;
    globals->window->settings = sfFullscreen;
    globals->window->window = sfRenderWindow_create(globals->window->mode,
        "myrpg", globals->window->settings, NULL);
    sfRenderWindow_setFramerateLimit(globals->window->window, 120);
    }

    static void setup_player(global_t *globals)
{
    globals->player = malloc(sizeof(player_t));
    globals->player->pos = (sfVector2f){3, 2};
    globals->player->dir = (sfVector2f){-1, 0};
    globals->player->plane = (sfVector2f){0, 0.66};
    globals->player->rot_angle = 0;
    globals->player->is_looking_sprite = 0;
    globals->player->is_paused = 0;
    weapon_create(globals, "assets/img/punch1.png", "assets/img/punch2.png");
    globals->player->weapon_id = 0;
    globals->player->items = 0;
    health_create(globals);
    level_create(globals);
    globals->draw_ceilling = 0;
    globals->has_paul = 0;
    globals->quality = 1;
    globals->player->quest = 0;
    globals->speedrun_clock = sfClock_create();
    globals->ray = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(globals->ray, sfLines);
    }

    static void setup_floor(global_t *globals)
{
    globals->floor_texture = sfTexture_create(globals->window->width,
        globals->window->height);
    globals->floor_sprite = sfSprite_create();
    sfSprite_setOrigin(globals->floor_sprite, (sfVector2f){globals->window->
        width / 2, globals->window->height / 2});
    sfSprite_setPosition(globals->floor_sprite, (sfVector2f){globals->window->
        width / 2, globals->window->height / 2});
    sfSprite_setTexture(globals->floor_sprite, globals->floor_texture,
        sfFalse);
    create_floor_texure_pixels(globals);
    }

    void setup_wall_textures(global_t *globals)
{
    globals->wall_texture[0] = sfTexture_createFromFile(
        "assets/img/Chimeny.JPG", NULL);
    globals->wall_texture[1] = sfTexture_createFromFile(
        "assets/img/brick_discolored.jpg", NULL);
    globals->wall_texture[2] = sfTexture_createFromFile(
        "assets/img/brick_discolored2.jpg", NULL);
    globals->wall_texture[3] = sfTexture_createFromFile(
        "assets/img/brick_vine.jpg", NULL);
    globals->bassirou_texture = sfTexture_createFromFile(
            "assets/img/bassirou256.jpg", NULL);
    globals->grass_texture = sfTexture_createFromFile(
            "assets/img/pitted.png", NULL);
    globals->dialog_texture = sfTexture_createFromFile(
        "assets/img/dialog_box.png", NULL);
    }

    static void setup_sounds(global_t *globals)
{
    globals->volume = 50;
    globals->sound_buffers[0] = sfSoundBuffer_createFromFile(
        "assets/snd/gun_song.ogg");
    globals->sound_buffers[1] = sfSoundBuffer_createFromFile(
        "assets/snd/zombie_song.ogg");
    globals->sounds[0] = sfSound_create();
    globals->sounds[1] = sfSound_create();
    sfSound_setBuffer(globals->sounds[0], globals->sound_buffers[0]);
    sfSound_setBuffer(globals->sounds[1], globals->sound_buffers[1]);
    globals->zbuffer = malloc(sizeof(double) * globals->window->width);
    globals->math = malloc(sizeof(math_t));
    globals->dialog_font = sfFont_createFromFile("assets/font/dialog.ttf");
    globals->main_clock = sfClock_create();
    globals->fps = 120;
    }

    global_t *setup_globals(void)
{
    global_t *globals = malloc(sizeof(global_t));

    globals->nb_button = 0;
    globals->nb_sprite = 0;
    create_map(globals);
    call_buttons(globals);
    setup_window(globals);
    setup_player(globals);
    setup_wall_textures(globals);
    setup_all_sprites(globals);
    setup_floor(globals);
    setup_sounds(globals);
    init_inventory(globals);
    init_gun(globals);
    call_buttons_inven(globals);
    return (globals);
    }
