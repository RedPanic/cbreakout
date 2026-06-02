#include "paddle.h"
#include "settings.h"


Paddle* new_paddle(Color color, int width){
    Paddle* paddle = (Paddle*)malloc(sizeof(Paddle));
    paddle->position = (Vector2){WIN_WIDTH/2 - PADDLE_WIDTH/2, WIN_HEIGHT - PADDLE_HEIGHT};
    paddle->color = color;
    paddle->width = width;
    return paddle;
}
void move_paddle(Paddle* paddle, Vector2 direction){
    paddle->position.x += direction.x * PADDLE_SPEED;
    paddle->position.y += direction.y * PADDLE_SPEED;
}
void destroy_paddle(Paddle* paddle){
    free(paddle);
}