#include "screen.h"


void menu_screen(void){
    clear();
    mvprintw(5, 70, "TYPING");
    mvprintw(12, 70, "1.Start");
    mvprintw(14, 70, "2.Ranking");
    mvprintw(16, 70, "3.Level");
    mvprintw(18, 70, "4.Exit");
    mvprintw(22, 65, "番号を選択してください");
}

int level_screen(void){
    int ch;
    mvprintw(12, 70, "0.Easy");
    mvprintw(15, 70, "1.Nomal");
    mvprintw(18, 70, "2.hard");
    ch = getch();
    while(ch != '0' && ch != '1' && ch != '2'){
        mvprintw(22, 60, "0,1,2のどれかを入力して下さい");
        ch = getch();
    }
    return ch;
}
void end_screen(void){
    mvprintw(15, 70, "ゲームを終了します");
}






