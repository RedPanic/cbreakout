#ifndef BRICK_H
#define BRICK_H

#include "raylib.h"
#include <stdlib.h>

typedef struct Brick{
    Vector2 position;
    Color color;
    int width;
}Brick;

Brick* new_brick(Vector2 position, int width);
void destroy_brick(Brick* brick);
Color choose_brick_color();

#endif