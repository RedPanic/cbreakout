#include "my_helpers.h"

Brick **createBricks(int amount)
{
    Brick **bricks = malloc(amount * sizeof(Brick));
    for (int i = 0; i < amount; i++)
    {
        bricks[i] = new_brick((Vector2){(i % COLS) * (BRICK_SPACE + BRICK_WIDTH + BRICK_SPACE), (BRICK_STARTING_POINT + ((i / COLS) * amount))}, GREEN, BRICK_WIDTH);
    }

    return bricks;
}

void draw_bricks(Brick **bricks, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        DrawRectangle(bricks[i]->position.x, bricks[i]->position.y, bricks[i]->width, 20, bricks[i]->color);
    }
}
void destroy_bricks(Brick **bricks)
{
    free(bricks);
}

void draw_lives(const GameState *state)
{
    DrawText(TextFormat("Lives: %d", state->lives), 10, 30, 20, WHITE);
}
void draw_score(const GameState *state)
{
    DrawText(TextFormat("Score: %d", state->score), WIN_WIDTH - 140, 30, 20, WHITE);
}

void do_ball_movement(Ball *ball, Paddle *paddle, Brick **bricks, GameState *state)
{
    if (ball)
    {
        if (ball->position.x <= 0 || ball->position.x >= WIN_WIDTH - ball->width)
        {
            ball->direction.x = -ball->direction.x;
        }

        check_paddle_collisions(ball, paddle);

        if (check_brick_collisions(ball, bricks, state))
        {
            ball->direction.y = -ball->direction.y;
        }

        if (ball->position.y <= 0)
        {
            ball->direction.y = -ball->direction.y;
        }

        if (ball->position.y >= WIN_HEIGHT - ball->width)
        {
            freeze_game(state, paddle, ball);
            state->lives--;
            state->score = 0;
            if (state->lives <= 0)
            {
                game_over(state, paddle, ball);
            }

            return;
        }

        move_ball(ball);
    }
}

bool check_paddle_collisions(Ball *ball, Paddle *paddle)
{
    Rectangle pad_rect = (Rectangle){paddle->position.x, paddle->position.y, paddle->width, 20};

    if (CheckCollisionCircleRec(ball->position, (float)ball->width, pad_rect))
    {
        ball->direction.y = -ball->direction.y;
        return true;
    }
    return false;
}

bool check_brick_collisions(Ball *ball, Brick **bricks, GameState *state)
{
    for (int i = 0; i < state->bricks; i++)
    {
        if (bricks[i] == NULL)
        {
            continue;
        }
        Rectangle brick_rect = (Rectangle){bricks[i]->position.x, bricks[i]->position.y, bricks[i]->width, 20};

        if (CheckCollisionCircleRec(ball->position, (float)ball->width, brick_rect))
        {
            state->score += 100;
            destroy_brick(bricks[i]);

            for (int j = i; j < state->bricks - 1; j++)
            {
                bricks[j] = bricks[j + 1];
            }

            bricks[state->bricks - 1] = NULL;
            state->bricks--;

            return true;
        }
    }
    return false;
}

void freeze_game(GameState *state, Paddle *paddle, Ball *ball)
{
    state->need_freeze = true;
    if (paddle)
    {
        paddle->position.x = WIN_WIDTH / 2 - PADDLE_WIDTH / 2;
        if (ball)
        {
            ball->position.x = paddle->position.x + PADDLE_WIDTH / 2 - BALL_WIDTH /2;
            ball->position.y = paddle->position.y - BALL_WIDTH;
        }
    }
}

void game_over(GameState *state, Paddle *paddle, Ball *ball)
{
    state->is_over = true;
    freeze_game(state, paddle, ball);
}