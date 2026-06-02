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
    int color_value = GetRandomValue(1, 4);
    switch (color_value) {
        case 1: return GREEN;
        case 2: return YELLOW;
        case 3: return MAGENTA;
        default: return DARKBLUE; // Placeholder - replace with actual color selection logic
    }
}