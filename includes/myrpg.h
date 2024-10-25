/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#ifndef AZE_
    #define AZE_

    #include <SFML/Audio/Types.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <time.h>

    #define M_PI 3.14159265358979323846
    #define TEXHEIGHT 256
    #define PRECISION 1
    #define MAX_BUTTONS 100
    #define MAX_SPRITES 100
    #define MAX_TEXTURES 100
    #define MAX_SOUNDS 100
    #define SETFRAMERATELIMIT sfRenderWindow_setFramerateLimit

typedef struct window_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    sfUint32 settings;
    int width;
    int height;
    int is_fullscreen;
} window_t;

typedef struct sprite_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int type;
    int line;
    int damage;
} sprite_t;

typedef struct map_s {
    int **map;
    int width;
    int height;
} map_t;

typedef struct weapon_s {
    sfTexture *texture;
    sfTexture *fired_texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
    sfClock *clock;
} weapon_t;

typedef struct player_s {
    sfVector2f pos;
    sfVector2f dir;
    float rot_angle;
    sfVector2f plane;
    int is_looking_sprite;
    int is_firing;
    int is_talking;
    int is_paused;
    int weapon_id;
    int health;
    sfText *hp_text;
    sfClock *damage_clock;
    int items;
    int xp;
    sfText *xp_text;
    int quest;
} player_t;

enum BUTTON_STATE {
    BTN_NORMAL,
    BTN_HOVER,
    BTN_PRESSED
};

typedef struct button_s {
    enum BUTTON_STATE status;
    sfVector2f pos;
    sfVector2f scale;
    sfSprite *sprite;
    sfTexture *Texture;
} button_t;

enum SPRITE_TYPE {
    DECO,
    SKULLS,
    GRAVE,
    ZOMBIE,
    CHEST,
    MAGE,
    PAUL,
    PAUL_FOLLOWING
};

typedef struct math_s {
    float rayDirX0;
    float rayDirY0;
    float rayDirX1;
    float rayDirY1;
    int p;
    float posZ;
    float rowDistance;
    float floorStepX;
    float floorStepY;
    float floorX;
    float floorY;
    double spriteX;
    double spriteY;
    double invDet;
    double transformX;
    double transformY;
    int spriteScreenX;
    int spriteHeight;
    int drawStartY;
    int drawEndY;
    int spriteWidth;
    int drawStartX;
    int drawEndX;
    int texX;
    double cameraX;
    double rayPosX;
    double rayPosY;
    double rayDirX;
    double rayDirY;
    int mapX;
    int mapY;
    double sideDistX;
    double sideDistY;
    double deltaDistX;
    double deltaDistY;
    double perpWallDist;
    int stepX;
    int stepY;
    int hit;
    int side;
    double wallX;
    double disted;
} math_t;

typedef struct button_inven_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
} button_inven_t;

typedef struct inventory_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
} inventory_t;

typedef struct gun_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
} gun_t;

typedef struct end_s {
    sfTexture *texture;
    sfSprite *sprite;
} end_t;

typedef struct global_s {
    window_t *window;
    map_t *map;
    player_t *player;
    sfVertexArray *ray;
    sfEvent event;
    math_t *math;
    inventory_t *inven[MAX_BUTTONS];
    sfTexture *wall_texture[MAX_TEXTURES];
    sfTexture *bassirou_texture;
    sfTexture *grass_texture;
    int draw_ceilling;
    int quality;
    button_t *buttons[MAX_BUTTONS];
    inventory_t *inventory;
    gun_t *gun;
    end_t *end;
    int nb_button;
    sfMusic *music_menu;
    sprite_t *sprite[MAX_SPRITES];
    int nb_sprite;
    double *zbuffer;
    int spriteOrder[MAX_SPRITES];
    double spriteDistance[MAX_SPRITES];
    sfTexture *floor_texture;
    sfSprite *floor_sprite;
    sfUint8 *floor_texture_pixels;
    weapon_t *weapon;
    sfFont *dialog_font;
    sfClock *main_clock;
    sfSprite *helpsprite;
    sfTexture *helptexture;
    sfTexture *dialog_texture;
    int volume;
    int fps;
    sfMusic *music_game;
    int has_paul;
    sfSoundBuffer *sound_buffers[MAX_SOUNDS];
    sfSound *sounds[MAX_SOUNDS];
    sfClock *speedrun_clock;
} global_t;

typedef struct wrapper_s {
    double val_a;
    double val_b;
} wrapper_t;

typedef struct dict_s {
    int key;
    char *value;
} dict_t;

int env_display_find(char **env);
global_t *setup_globals(void);
void destroy_globals(global_t *globals);
void raycasting(global_t *globals);
void check_start_game(global_t *globals);
void check_quit_game(global_t *globals);
void button_play(global_t *globals);
void button_options(global_t *globals);
void call_buttons(global_t *globals);
int menu_music(global_t *gobals);
sfBool is_button_clicked(sfSprite *sprite, sfMouseButtonEvent mouse_event);
sfBool is_button_hovered(global_t *globals, sfSprite *sprite);
void check_button(global_t *globals, button_t *buttons, sfSprite *sprite);
void btn_play_anim(global_t *globals);
void btn_quit_anim(global_t *globals);
void btn_option_anim(global_t *globals);
void draw_particle(global_t *globals);
void update_enemies(global_t *globals);
void floor_casting(global_t *globals, sfRenderStates *states, math_t math);
void sprite_casting(global_t *globals, sfRenderStates *states, math_t maths);
void handle_event(global_t *globals, sfEvent event);
void mouse_movement(global_t *globals);
void draw_crosshair(global_t *globals);
void zqsd_movement(global_t *globals);
void weapon_create(global_t *globals, char *img1, char *img2);
void weapon_draw(global_t *globals);
void weapon_switch(global_t *globals, char *img1, char *img2, int type);
void npc_dialog(global_t *globals);
void health_draw(global_t *global);
void health_create(global_t *global);
void btn_help_anim(global_t *globals);
void check_help_game(global_t *globals);
void check_buttons(global_t *globals);
void options_loop(global_t *globals);
int size_of_int(int temp, int num);
char *my_itoa(int num);
int check_button_pressed(global_t *globals, int id);
void pause_loop(global_t *globals);
void inventory(global_t *global);
void init_inventory(global_t *global);
void cleanup_inventory(global_t *global);
void save_settings(global_t *globals);
void load_settings(global_t *globals);
void save_game(global_t *globals);
void load_game(global_t *globals);
int game_music(global_t *globals);
void init_gun(global_t *global);
void ending_loop(global_t *globals);
void help_anim(global_t *globals);
void level_create(global_t *global);
void level_draw(global_t *global);
void options_change_window(global_t *globals);
void call_buttons_inven(global_t *globals);
void splash_screen(global_t *globals);
void draw_quest(global_t *globals);
void quest_update_texture(global_t *globals, int i);
int file_check(void);
int dash_h(int argc, char **argv);
void main_menu_loop(global_t *globals);

#endif /* !AZE_ */
