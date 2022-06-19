#include <ncurses.h>  
#include <unistd.h>
#include <locale.h>
#include "size.h"

int main(int argc, char **argv) {  
    int check = 1;
    int x,y;
    if(argc != 1){
        fprintf(stderr, "./typingのみ入力して下さい\n");
    }
    
    setlocale(LC_ALL,"");
    initscr();
    refresh();
    while(check != 0){
        clear();
        check = screen_size_check();
        refresh();
        sleep (1);
    }
    endwin();
    return 0;  
}

