#include "game.h"

int score_init(int x){
    x = 0;
    return x; 
}

void load_q_file(int level_flag){
    char file_name[][12] = {"q_easy.txt", "q_nomal.txt", "q_hard.txt"};
    int i=0;
    
    if ((fp = fopen(file_name[level_flag], "r")) == NULL){
        mvprintw(15, 70, "ファイル%sがありません", file_name[level_flag]);
        refresh();
        sleep(1);
        clear();
        refresh();
        exit(1);
    }
    
    while(fscanf(fp,"%d %s", &question[i].q_num, question[i].question) != EOF ){
        i++;
    }
    /*clear();
    mvprintw(15, 70, "ファイルを%d個読み取りました", i);
    refresh();*/
}

void draw_before_game(int level_flag){
    int ch;
    char level_arr[][6] = {"easy", "nomal", "hard"};
    
    mvprintw(10, 70, "ゲームを開始します");
    mvprintw(15, 70, "このゲームの難易度は%sです", level_arr[level_flag]);
    mvprintw(20, 70, "準備ができたらEnterを押してください");
    refresh();
    ch = getch();
    while(ch != '\n'){
        ch = getch();
    }
}

void game_main(int level_flag){
    int score;
    
    score = score_init(score);
    load_q_file(level_flag);
    draw_before_game(level_flag);
}


void game_screen(int level_flag){
     game_main(level_flag);
}


