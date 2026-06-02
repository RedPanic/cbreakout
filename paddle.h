#ifndef PADDLE_H
#define PADDLE_H

#include "raylib.h"
#include<stdlib.h>

typedef struct Paddle {
    Vector2 position;
    Color color;
    int width;

}Paddle;

Paddle* new_paddle(Color color, int width);
void move_paddle(Paddle* paddle, Vector2 direction);
void destroy_paddle(Paddle* paddle);




#endif