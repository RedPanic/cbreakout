#include "raylib.h"
#include "settings.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"
#include "my_helpers.h"
#include "game_state.h"
#include<stdlib.h>


int main(void){
	InitWindow(WIN_WIDTH, WIN_HEIGHT, "C Breakout by @micpos");
	SetTargetFPS(T_FPS);
    GameState* state = create_game_state(BRICK_COUNT);
    Paddle *paddle = new_paddle(RAYWHITE, PADDLE_WIDTH);
    Ball *ball = new_ball(paddle->position, (Vector2){1, -1}, MAROON, BALL_WIDTH);
    Brick **bricks = createBricks(state->bricks);
    

	while(!WindowShouldClose()){

        int user_input = GetKeyPressed();

        switch(user_input){
            case KEY_LEFT:
            if(paddle->position.x >= 0 && !state->need_freeze) move_paddle(paddle, (Vector2){-10, 0});
                break;
            case KEY_RIGHT:
                if(paddle->position.x + paddle->width <= WIN_WIDTH && !state->need_freeze) move_paddle(paddle, (Vector2){10, 0});
                break;
            case KEY_SPACE:
                if(state->need_freeze){
                    state->need_freeze = false;
                }
                break;
            case KEY_R:
            if(state->is_over){
                state->is_over = false;
                state->lives = 3;
                state->score = 0;
                state->bricks = BRICK_COUNT;
                freeze_game(state, paddle, ball);
                destroy_bricks(bricks);
                bricks = createBricks(state->bricks);
            }
        }

        if(!state->need_freeze){
            do_ball_movement(ball, paddle, bricks, state);
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("C Breakout", 10, 10, 20, WHITE);
        draw_lives(state);
        draw_score(state);
        if(!state->is_over){
        draw_bricks(bricks, state->bricks);
        draw_ball(ball);
        DrawRectangle(paddle->position.x, paddle->position.y, paddle->width, 20, paddle->color);
        }else {
            DrawText("Game Over", WIN_WIDTH / 2 - 180, WIN_HEIGHT / 2 - 40, 80, WHITE);
            DrawText("Press 'R' to restart", WIN_WIDTH / 2 - 90, WIN_HEIGHT / 2 + 40, 20, WHITE);
        }
        EndDrawing();
	}

    destroy_ball(ball);
    destroy_paddle(paddle);
    destroy_bricks(bricks);
    destroy_game_state(state);

    CloseWindow();
    
	return 0;
}
