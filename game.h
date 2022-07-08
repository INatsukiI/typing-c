#include <stdlib.h>
#include <ncurses.h>  
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_SCREEN_X 150
#define MAX_SCREEN_Y 30
#define MAX_Q_SIZE 30
#define SCORE_CHECK_ST_SIZE 5
#define GAME_SC_1 "ゲームを開始します"
#define GAME_SC_2 "このゲームの難易度は"
#define GAME_SC_3 "準備ができたらEnterを押してください"
#define GAME_SC_4 "Enter以外が入力されました"
#define GAME_SC_5 "あなたのスコアは"
#define GAME_SC_6 "ランクインしました!"
#define GAME_SC_7 "ランキング登録するために"
#define GAME_SC_8 "名前入力画面に遷移します"
#define GAME_SC_9 "ランクインおめでとうございます！"
#define GAME_SC_10 "名前を3文字以内,半角英数字で入力して下さい"
#define GAME_TIME 10

typedef struct{
    char name[4];
    int score;
}SCORE_CHECK_ST;

typedef struct{
    int q_num;
    char question[20];
}QUESTION;

QUESTION question[MAX_Q_SIZE];
SCORE_CHECK_ST rank_score[SCORE_CHECK_ST_SIZE];
FILE *fp_q;
FILE *fq_s;


int score_init(int x);
int score_rankcheck(int score, int level_flag);
void input_name(char user_name[10]);
void finish_game(int score, int level_flag);
void load_q_file(int level_flag);
void game_main(int level_flag);
void game_screen(int level_flag);
void draw_before_game(int level_flag);
