#include <stdlib.h>
#include <ncurses.h>  
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_SCREEN_X 150
#define MAX_SCREEN_Y 30
#define MAX_Q_SIZE 30
#define GAME_SC_1 "ゲームを開始します"
#define GAME_SC_2 "このゲームの難易度は"
#define GAME_SC_3 "準備ができたらEnterを押してください"
#define GAME_SC_4 "Enter以外が入力されました"
#define GAME_SC_5 "あなたのスコアは"
#define GAME_TIME 20

typedef struct{
    int q_num;
    char question[20];
}QUESTION;


QUESTION question[MAX_Q_SIZE];
FILE *fp;


int score_init(int x);
void game_main(int level_flag);
void game_screen(int level_flag);
void draw_before_game(int level_flag);
void finish_game(int x);
