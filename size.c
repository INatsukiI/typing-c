#include "size.h"

int screen_size_check(void){
    int x,y;
    
    getmaxyx(stdscr, y,x);
    if(y!=30 || x!=150){
        y = y/2;
        x = (x - strlen("画面サイズを150×30にして下さい"))/2;
        mvprintw(y, x, "画面サイズを150×30にして下さい");
        return 1;
    }else{
        y = y/2;
        x = (x - strlen("画面サイズ150×30なのでメニュー画面に遷移します"))/2;
        mvprintw(y, x, "画面サイズ150×30なのでメニュー画面に遷移します");
        return 0;
    }
}
