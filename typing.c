#include <ncurses.h>  
#include <unistd.h>
#include <locale.h>
#include <stdlib.h>
#include "size.h"
#include "screen.h"

/*現在のコンパイル方法gcc typing.c size.c screen.c -o typing.exe -lncursesw*/

int main(int argc, char **argv) {  
    int check = 1;
    
    /*./typing以外で実行した場合エラー*/
    if(argc != 1){
        fprintf(stderr, "./typingのみ入力して下さい\n");
        exit(1);
    }
    
    /*画面サイズチェック処理*/
    setlocale(LC_ALL,"");
    initscr();
    refresh();
    while(check != 0){
        clear();
        check = screen_size_check();
        refresh();
        sleep (1);
    }
    
    /*メニュー画面表示*/
    menu_screen();
    
    /*メニュー画面処理(まだメニューを表示するだけ)*/
    /* 文字をバッファーに溜めない */  
    crmode();  
  
    /* 入力文字を出力しない */  
    noecho(); 
    while(true){
        int ch = getch();
        if(ch == '1'){
            /*ゲーム開始処理*/
            clear();
            mvprintw(12, 70, "1.Start");
            refresh();
            sleep (1);
            break;
        }else if(ch == '2'){
            /*ランキング画面表示*/
            clear();
            mvprintw(14, 70, "2.Ranking");
            refresh();
            sleep (1);
            break;
        }else if(ch == '3'){
            /*難易度選択画面表示*/
            clear();
            mvprintw(16, 70, "3.Level");
            refresh();
            sleep (1);
            break;
        }else if(ch == '4'){
            /*ゲーム終了画面表示*/
            end_screen();
            sleep (1);
            break;
        }
    }
    
    
    
    endwin();
    return 0;  
}

