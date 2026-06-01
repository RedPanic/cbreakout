#include "raylib.h"
#include "settings.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"
#include "my_helpers.h"
#include "game_state.h"
#include<stdlib.h>


int main(void){
	InitWindow(WIN_WIDTH, WIN_HEIGHT, "C Breakout @micpos");
	SetTargetFPS(T_FPS);
    GameState* state = create_game_state(BRICK_COUNT);
    Ball *ball = new_ball((Vector2){WIN_WIDTH/2, WIN_HEIGHT/2}, (Vector2){1, 1}, RED, 20);
    Paddle *paddle = new_paddle((Vector2){WIN_WIDTH/2, WIN_HEIGHT - 20}, WHITE, PADDLE_WIDTH);
    Brick **bricks = createBricks(state->bricks);
    

	while(!WindowShouldClose()){

        int user_input = GetKeyPressed();

        switch(user_input){
            case KEY_LEFT:
            if(paddle->position.x >= 0) move_paddle(paddle, (Vector2){-10, 0});
                break;
            case KEY_RIGHT:
                if(paddle->position.x + paddle->width <= WIN_WIDTH) move_paddle(paddle, (Vector2){10, 0});
                break;
        }

        do_ball_movement(ball, paddle, bricks, state);

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("C Breakout", 10, 10, 20, WHITE);
        draw_bricks(bricks, state->bricks);
        draw_ball(ball);
        draw_lives(state);
        draw_score(state);
        DrawRectangle(paddle->position.x, paddle->position.y, paddle->width, 20, paddle->color);

        EndDrawing();
	}

    destroy_ball(ball);
    destroy_paddle(paddle);
    destroy_bricks(bricks);
    destroy_game_state(state);

    CloseWindow();
    
	return 0;
}
