#include "game.h"

/*スコアの初期化*/
int score_init(int x){
    x = 0;
    return x; 
}
/*未完成の終了処理*/
void finish_game(int x){
    clear();
    mvprintw(15, (MAX_SCREEN_X/2-(strlen(GAME_SC_5)/2)) + 2, "%s%dです!", GAME_SC_5,x);
    refresh();
    sleep(2);
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
    
    mvprintw(10, MAX_SCREEN_X/2 - (strlen(GAME_SC_1)/2),"%s",GAME_SC_1);
    mvprintw(15, MAX_SCREEN_X/2 - ((strlen(GAME_SC_2) + strlen(level_arr[level_flag]) + 2)/2), "%s%sです",GAME_SC_2,level_arr[level_flag]);
    mvprintw(20, (MAX_SCREEN_X/2 - (strlen(GAME_SC_3)/2)+4),"%s",GAME_SC_3 );
    refresh();
    ch = getch();
    while(ch != '\n'){
        mvprintw(23, MAX_SCREEN_X /2- (strlen(GAME_SC_4)/2), "%s",GAME_SC_4);
        ch = getch();
    }
}

void game_main(int level_flag){
    int score;
    int ch;
    int q_num;
    int flag=0;
    int j=0;
    char *p;
    time_t st, ed;
    
    /*文字の色の割り当て*/
    start_color();
    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK); 
    
    /*スコアの初期化*/
    score = score_init(score);
    /*難易度に合わせた問題のファイル読み込み*/
    load_q_file(level_flag);
    /*ゲーム開始前画面表示*/
    draw_before_game(level_flag);
    /*3,2,1のカウントダウン*/
    for(int i=3; i>0; i--){
        clear();
        mvprintw(15, (MAX_SCREEN_X/2),"%d",i );
        refresh();
        sleep(1);
    }
    clear();
    /*タイマー開始*/
    st = time(NULL);
    ed = time(NULL);
    while(ed - st < GAME_TIME){
        /*ランダムな数字を生成して問題を指定*/
        q_num= rand() % 30;
        p = question[q_num].question;
        
        /*テスト用*/
        clear();
        /*mvprintw(3, MAX_SCREEN_X/2,"%d",ed - st);*/
        mvprintw(3, MAX_SCREEN_X/2,"%d",score);
        mvprintw(10, MAX_SCREEN_X/2 - (strlen(p)/2),"%s",p);
        refresh();
        /*文字を入力させ、合っているか確認*/
        j=0;
        while(ed - st < GAME_TIME && (strlen(p) > j)){
            ch = getch();
            if(ch == p[j]){
                move(10, (MAX_SCREEN_X/2 - (strlen(p)/2)) + j);
                addch(ch| COLOR_PAIR(COLOR_RED));
                j++;
                score++;
                
            }else{
                if(score != 0 ){
                    clear();
                    score--;
                    mvprintw(3, MAX_SCREEN_X/2,"%d",score);
                    refresh();
                }
            }
            mvprintw(3, MAX_SCREEN_X/2,"%d",score);
            refresh();
            ed = time(NULL);
        }
    }
    finish_game(score);
}


void game_screen(int level_flag){
     game_main(level_flag);
}


