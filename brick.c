#include "brick.h"

Brick* new_brick(Vector2 position, int width) {
    Brick* brick = (Brick*)malloc(sizeof(Brick));
    if (brick) {
        brick->position = position;
        brick->color = choose_brick_color();
        brick->width = width;
    }
    return brick;
}

void destroy_brick(Brick* brick) {
    if (brick) {
        free(brick);
    }
}

Color choose_brick_color() {

    return RED; // Placeholder - replace with actual color selection logic
}