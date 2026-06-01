#include "brick.h"

Brick* new_brick(Vector2 position, Color color, int width) {
    Brick* brick = (Brick*)malloc(sizeof(Brick));
    if (brick) {
        brick->position = position;
        brick->color = color;
        brick->width = width;
    }
    return brick;
}

void destroy_brick(Brick* brick) {
    if (brick) {
        free(brick);
    }
}