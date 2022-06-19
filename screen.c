#include "screen.h"


void menu_screen(void){
    clear();
    mvprintw(5, 70, "TYPING");
    mvprintw(12, 70, "1.Start");
    mvprintw(14, 70, "2.Ranking");
    mvprintw(16, 70, "3.Level");
    mvprintw(18, 70, "4.Exit");
    mvprintw(22, 65, "番号を選択してください");
    refresh();
}


void end_screen(void){
    clear();
    mvprintw(15, 70, "ゲームを終了します");
    refresh();
}






