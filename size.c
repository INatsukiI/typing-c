#include "size.h"


int screen_check(int x, int y){
    char *str1 = "画面サイズを150×30にして下さい";
    char *str2 = "画面サイズ150×30なのでメニュー画面に遷移します";
    
    if(y!=30 || x!=150){
        y = y/2;
        x = (x - strlen(str1))/2;
        mvprintw(y, x, str1);
        return 1;
    }else{
        y = y/2;
        x = (x - strlen(str2))/2;
        mvprintw(y, x, str2);
        return 0;
    }
}


int screen_size_check(void){
    int x,y;
    
    getmaxyx(stdscr, y,x);
    return screen_check(x,y);
}
