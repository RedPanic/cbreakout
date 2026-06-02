#ifndef GAME_STATE_H
#define GAME_STATE_H
#include<stdlib.h>
#include<stdbool.h>

typedef struct GameState{
    char lives;
    int score;
    int bricks;
    bool is_over;
    bool need_freeze;

}GameState;


void set_bricks(GameState* state, int bricks);
void set_score(GameState* state, char score);
void set_lives(GameState* state, char lives);
char get_lives(const GameState* state);
char get_score(const GameState* state);
int get_bricks(const GameState* state);


GameState *create_game_state(int bricks);
void destroy_game_state(GameState* state);



#endif // GAME_STATE_H