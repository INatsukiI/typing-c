#include "game.h"
#include "game_key_define.h"
/*スコアの初期化*/
int score_init(int x){
    x = 0;
    return x; 
}

void print_key(void){
    for(int i=0; i<=12; i++){
        mvprintw(15+i, MAX_SCREEN_X/2-(strlen(key[i])/2), "%s", key[i]);
    }
}

void key_flash(char x){
    int x_zahyo,y_zahyo;
    for(int i=0; i<26; i++){
        if(x==key2[i]){
            x_zahyo = key_zahyo[i][0];
            y_zahyo = key_zahyo[i][1];
        }
    }
    move(y_zahyo, x_zahyo);
    addch(x| COLOR_PAIR(COLOR_RED));
    
}

void input_name_screen(void){
    clear();
    mvprintw(10, MAX_SCREEN_X/2-(strlen(GAME_SC_9)/2)+6, "%s", GAME_SC_9);
    mvprintw(15, MAX_SCREEN_X/2-(strlen(GAME_SC_10)/2)+7, "%s", GAME_SC_10);
    refresh();
    move(20,MAX_SCREEN_X/2-3);
}
void input_name(char *user_name){
    char name[10];
    int flag=0;
    
    input_name_screen();
    curs_set(1);
    echo();
    getstr(name);
    for(int i=0; i<3; i++){
        if(name[i] < 'a' || name[i] > 'z'){
           flag=1;
        }
        user_name[i] = name[i];
    }
    user_name[3] = '\0';
    
    while(flag == 1){
        flag=0;
        input_name_screen();
        getstr(name);
        for(int i=0; i<3; i++){
            if(name[i] < 'a' || name[i] > 'z'){
                flag=1;
            }
            user_name[i] = name[i];
        }
        user_name[3] = '\0';
    }
}

/*ランキング書き込み処理に使う関数、ランキングファイルを読み込み、ユーザーがランクインした際に
  そのスコアを含めた6つのデータでソート処理を行い、上位5つのデータをランキングファイルに上書きする形で書き込む*/
int score_rank_check(int score, int level_flag){
    int i=0;
    int flag=0;
    char file_ranking_name[][20] = {"ranking_easy.txt", "ranking_nomal.txt", "ranking_hard.txt"};
    
    if ((fq_s = fopen(file_ranking_name[level_flag], "r")) == NULL){
        mvprintw(20, 70, "ファイル%sがありません", file_ranking_name[level_flag]);
        refresh();
        sleep(1);
        clear();
        refresh();
        exit(1);
    }
    
    while(fscanf(fq_s,"%s %d", rank_score[i].name, &rank_score[i].score) != EOF){
        i++;
    }
    
    /*元のランキングファイルのスコアより高ければフラグを立てる*/
    for(i=0; i<5; i++){
        if(score >= rank_score[i].score){
            flag = 1;
            break;
        }
    }
    
    fclose(fq_s);
    if(flag != 1){
        return 0;
    }else{
        return 1;
    }
}
    
int exist_file(const char* path){
    struct stat st;

    if (stat(path, &st) != 0) {
        return 0;
    }
    return (st.st_mode & S_IFMT) == S_IFREG;
}
    
void ranking_write(char *user_name, int score, int level_flag){
    /*ランキングファイルの5つとユーザ1つのスコアから上位5つをソート*/
    int index;
    memcpy(user_score.name, user_name, sizeof(user_name));
    user_score.score = score;
    int i;
    int j;
    
    for(i=0; i<5; i++){
        if(rank_score[i].score <= user_score.score){
            index = i;
            break;
        }
    }
    j=5;
    
    while(index+1 < j){
        rank_score[j].score = rank_score[j-1].score;
        memcpy(rank_score[j].name, rank_score[j-1].name, sizeof(rank_score[j-1].name));
        j--;
    }
    memcpy(rank_score[index].name, user_score.name, sizeof(user_score.name));
    rank_score[index].score = user_score.score;
    
    
    /*ランキングファイルを開いて書き込む処理を書く*/
    char file_ranking_name[][20] = {"ranking_easy.txt", "ranking_nomal.txt", "ranking_hard.txt"};
    
    /*ファイルが存在するかの処理を書く*/
    if (exist_file(file_ranking_name[level_flag])) {
        fq_s = fopen(file_ranking_name[level_flag], "w+");
    
        for(int k=0; k<5; k++){
            fprintf(fq_s, "%s %d\n",rank_score[k].name, rank_score[k].score);
        }
        fclose(fq_s);
    }else{
        mvprintw(15, 70, "ファイル%sがありません", file_ranking_name[level_flag]);
        refresh();
        sleep(1);
        clear();
        refresh();
        exit(1);
    }
}
/*完成の終了処理*/
/*ランキングファイルに書き込み処理を行う*/
void finish_game(int score, int level_flag){
    int flag=0;
    char user_name[4];
    clear();
    mvprintw(15, MAX_SCREEN_X/2-(strlen(GAME_SC_5)/2), "%s%dです!", GAME_SC_5,score);
    flag = score_rank_check(score, level_flag);
    if(flag==1){
        mvprintw(20, MAX_SCREEN_X/2-(strlen(GAME_SC_6)/2)+3,"%s",GAME_SC_6);
        mvprintw(21, MAX_SCREEN_X/2-(strlen(GAME_SC_7)/2)+5,"%s",GAME_SC_7);
        mvprintw(22, MAX_SCREEN_X/2-(strlen(GAME_SC_8)/2)+5,"%s",GAME_SC_8);
        refresh();
        sleep(2);
        input_name(user_name);
        ranking_write(user_name, score, level_flag);
        clear();
    }
}

void load_q_file(int level_flag){
    char file_name[][12] = {"q_easy.txt", "q_nomal.txt", "q_hard.txt"};
    int i=0;
    
    if ((fp_q = fopen(file_name[level_flag], "r")) == NULL){
        mvprintw(15, 70, "ファイル%sがありません", file_name[level_flag]);
        refresh();
        sleep(1);
        clear();
        refresh();
        exit(1);
    }
    
    while(fscanf(fp_q,"%d %s", &question[i].q_num, question[i].question) != EOF ){
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
        noecho();
        /*ランダムな数字を生成して問題を指定*/
        q_num= rand() % 30;
        p = question[q_num].question;
        
        /*テスト用*/
        clear();
        /*mvprintw(3, MAX_SCREEN_X/2,"%d",ed - st);*/
        mvprintw(3, MAX_SCREEN_X/2,"%d",score);
        mvprintw(10, MAX_SCREEN_X/2 - (strlen(p)/2),"%s",p);
        print_key();
        refresh();
        /*文字を入力させ、合っているか確認*/
        j=0;
        while(ed - st < GAME_TIME && (strlen(p) > j)){
            key_flash(p[j]);
            curs_set(0);
            refresh();
            ch = getch();
            if(ch == p[j]){
                move(10, (MAX_SCREEN_X/2 - (strlen(p)/2)) + j);
                addch(ch| COLOR_PAIR(COLOR_RED));
                j++;
                score++;
                print_key();
                
            }else{
                if(score != 0 ){
                    score--;
                }
            }
            mvprintw(3, MAX_SCREEN_X/2,"%d",score);
            refresh();
            ed = time(NULL);
        }
    }
    finish_game(score,level_flag);
}


void game_screen(int level_flag){
     game_main(level_flag);
}


