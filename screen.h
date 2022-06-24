#include <ncurses.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct{
    char name[4];
    int score;
}SCORE;

SCORE score_easy[MAX_SIZE];
SCORE score_nomal[MAX_SIZE];
SCORE score_hard[MAX_SIZE];


FILE *fp1;
FILE *fp2;
FILE *fp3;

void menu_screen(void);
void ranking_screen(void);
int level_screen(void);
void end_screen(void);