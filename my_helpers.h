#ifndef MY_HELPERS_H
#define MY_HELPERS_H
#include "brick.h"
#include "ball.h"
#include "paddle.h"
#include "raylib.h"
#include "game_state.h"
#include "settings.h"
#include <stdio.h>
#include <stdlib.h>


Brick **createBricks(int amount);
void draw_bricks(Brick **bricks, int amount);
void destroy_bricks(Brick **bricks);
void do_ball_movement(Ball *ball, Paddle *paddle, Brick **bricks, GameState *state);
bool check_brick_collisions(Ball *ball, Brick **bricks, GameState *state);
void draw_lives(const GameState *state);
void draw_score(const GameState *state);

#endif