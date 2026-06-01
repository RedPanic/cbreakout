#ifndef BALL_H
#define BALL_H

#include "raylib.h"
#include "settings.h"

typedef struct Ball {
    Vector2 position;
    Vector2 direction;
    Color color;
    int width;
} Ball;

Ball* new_ball(Vector2 pos, Vector2 direction, Color color, int width);
void move_ball(Ball* ball);
void destroy_ball(Ball* ball);
void draw_ball(Ball* ball);

#endif