/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "myrpg.h"

const char *img_paths[] = {
    "assets/font/quest_1.jpg",
    "assets/font/quest_2.jpg",
    "assets/font/quest_3.jpg",
    "assets/font/quest_4.jpg",
    "assets/font/quest_done_1.jpg",
    "assets/font/quest_done_2.jpg",
    "assets/font/quest_done_3.jpg",
    "assets/font/quest_done_4.jpg",
    "assets/font/inventory.jpg",
    "assets/font/gun.png",
    "assets/redlarge/save_completed.png",
    "assets/dialog.npc",
    "assets/font/dialog_back.jpg",
    "assets/font/dialog.ttf",
    "assets/img/zombie.png",
    "assets/img/Coffre.png",
    "assets/img/mage.png",
    "assets/img/paul.png",
    "assets/img/paul.png",
    "assets/img/skulls.png",
    "assets/img/grave.png",
    "assets/img/Chimeny.JPG",
    "assets/img/brick_discolored.jpg",
    "assets/img/brick_discolored2.jpg",
    "assets/img/brick_vine.jpg",
    "assets/img/bassirou256.jpg",
    "assets/img/pitted.png",
    "assets/img/dialog_box.png",
    "assets/redlarge/New Game  col_Button.png",
    "assets/redlarge/options.png",
    "assets/redlarge/quit.png",
    "assets/redlarge/Load  col_Button.png",
    "assets/redsquare/help.png",
    "assets/redlarge/options.png",
    "assets/redsquare/Audio col_Square Button.png",
    "assets/redsquare/Up col_Square Button.png",
    "assets/redsquare/Down col_Square Button.png",
    "assets/redsquare/Home col_Square Button.png",
    "assets/redsquare/Up col_Square Button.png",
    "assets/redsquare/Down col_Square Button.png",
    "assets/redlarge/Continue  col_Button.png",
    "assets/redlarge/options.png",
    "assets/redlarge/options.png",
    "assets/redlarge/Exit  col_Button.png",
    "assets/redlarge/save.png",
    "assets/redlarge/Load  col_Button.png"
};

int file_check(void)
{
    for (int i = 0; i < 45; i++) {
        if (access(img_paths[i], F_OK) == -1) {
            return (1);
        }
    }
    return (0);
}
