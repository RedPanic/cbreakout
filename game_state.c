#include "game_state.h"


GameState* create_game_state(int bricks) {
	GameState* state = malloc(sizeof(GameState));
	if (state) {
		state->bricks = bricks;
		state->score = 0;
		state->lives = 3;
		state->is_over = false;
		state->need_freeze = true;
	}
	return state;
}

void set_bricks(GameState* state, int bricks){
	state->bricks = bricks;
}
void set_score(GameState* state, char score){
	state->score = score;
}
void set_lives(GameState* state, char lives){
	state->lives = lives;
}
char get_lives(const GameState* state){
	return state->lives;
}
char get_score(const GameState* state){
	return state->score;
}
int get_bricks(const GameState* state){
	return state->bricks;
}


void destroy_game_state(GameState* state){
	free(state);
}
