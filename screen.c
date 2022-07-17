#include "screen.h"

/*メニュー画面表示*/
void menu_screen(void){
    clear();
    mvprintw(5, 70, "TYPING");
    mvprintw(12, 70, "1.Start");
    mvprintw(14, 70, "2.Ranking");
    mvprintw(16, 70, "3.Level");
    mvprintw(18, 70, "4.Exit");
    mvprintw(22, 65, "番号を選択してください");
}

/*ランキング画面表示*/
void screen_rank(void){
    mvprintw(5, 32, "EASYのスコア");
    mvprintw(5, 72, "NOMALのスコア");
    mvprintw(5, 112, "HARDのスコア");
    mvprintw(10, 28, "rank");
    mvprintw(10, 68, "rank");
    mvprintw(10, 108, "rank");
    mvprintw(10, 35, "name");
    mvprintw(10, 75, "name");
    mvprintw(10, 115, "name");
    mvprintw(10, 43, "score");
    mvprintw(10, 83, "score");
    mvprintw(10, 123, "score");
}

void ranking_screen(void){
    int i=0;
    int ch;
    noecho();
    /*ファイルがない場合メッセージを表示して強制終了*/
    if ((fp1 = fopen("ranking_easy.txt", "r")) == NULL) {
        clear();
        refresh();
        mvprintw(15, 70, "ファイルranking_easy.txtがありません");
        exit(1);
    }
    
    if ((fp2 = fopen("ranking_nomal.txt", "r")) == NULL) {
        clear();
        refresh();
        mvprintw(15, 70, "ファイルranking_nomal.txtがありません");
        exit(1);
    }
    
    if ((fp3 = fopen("ranking_hard.txt", "r")) == NULL) {
        clear();
        refresh();
        mvprintw(15, 70, "ファイルranking_hard.txtがありません");
        exit(1);
    }
    /*ファイルがある場合読み取り,その表示*/
    while(fscanf(fp1,"%s %d", score_easy[i].name, &score_easy[i].score) != EOF && fscanf(fp2,"%s %d", score_nomal[i].name, &score_nomal[i].score) != EOF && fscanf(fp3,"%s %d", score_hard[i].name, &score_hard[i].score) != EOF){
        i++;
    }
    clear();
    screen_rank();
    for(i=0; i<5; i++){
        mvprintw(12+i*3, 30, "%d     %s     %3d",i+1,score_easy[i].name, score_easy[i].score);
        mvprintw(12+i*3, 70, "%d     %s     %3d",i+1,score_nomal[i].name, score_nomal[i].score);
        mvprintw(12+i*3, 110,"%d     %s     %3d",i+1,score_hard[i].name, score_hard[i].score);
        refresh();
    }
    mvprintw(27, 60, "戻る場合は0を入力して下さい");
    ch = getch();
    while(ch != '0'){
        mvprintw(28, 60, "0以外が入力されました");
        ch = getch();
    }
    
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

}

/*難易度選択画面表示*/
int level_screen(void){
    int ch;
    mvprintw(8, 71, "LEVEL");
    mvprintw(12, 70, "0.Easy");
    mvprintw(15, 70, "1.Nomal");
    mvprintw(18, 70, "2.hard");
    mvprintw(22, 53, "0,1,2のどれかを入力して難易度を決めて下さい");
    ch = getch();
    while(ch != '0' && ch != '1' && ch != '2'){
        mvprintw(24, 60, "0,1,2以外が入力されました");
        ch = getch();
    }
    if(ch == '0') return 0;
    if(ch == '1') return 1;
    if(ch == '2') return 2;
    
    return 0;
}

/*ゲーム終了画面表示*/
void end_screen(void){
    mvprintw(15, 70, "ゲームを終了します");
}






