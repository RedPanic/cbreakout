#include "ball.h"
#include<stdlib.h>


Ball* new_ball(Vector2 pos, Vector2 direction, Color color, int width){
    Ball* ball = (Ball*)malloc(sizeof(Ball));
    ball->position = (Vector2){(pos.x + (PADDLE_WIDTH/2) - (BALL_WIDTH/2)), pos.y - (BALL_WIDTH/2)};
    ball->direction = direction;
    ball->color = color;
    ball->width = width;
    return ball;
}

void move_ball(Ball* ball){
    ball->position.x += (BALL_SPEED * ball->direction.x);
    ball->position.y += (BALL_SPEED * ball->direction.y);
}

void draw_ball(Ball* ball){
    DrawCircleV(ball->position, ball->width/2, ball->color);
}

void destroy_ball(Ball* ball){
    free(ball);
}