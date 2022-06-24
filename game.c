#include "game.h"

void game_screen(int level_flag){
     char level_arr[][6] = {"easy", "nomal", "hard"};
     mvprintw(10, 70, "ゲームを開始します");
     mvprintw(15, 70, "このゲームの難易度は%sです", level_arr[level_flag]);
     refresh();
    /*game_main();*/
}


