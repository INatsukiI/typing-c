#include <ncurses.h>
#include <stdlib.h>
#include <ncurses.h>  
#include <unistd.h>
#define MAX_Q_SIZE 30


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
