# C Breakout

A classic Breakout game clone written in C using the [raylib](https://www.raylib.com/) library.

## Features

- Basic Breakout gameplay (paddle movement, ball bouncing, brick destruction).
- Score and lives tracking.
- Configurable game settings via `settings.h`.
- Modular design with separate components for Ball, Paddle, Bricks, and Game State.

## Prerequisites

- **GCC Compiler** (MinGW for Windows).
- **raylib** installed (Makefile expects it at `C:/raylib/raylib/src`).

## Building and Running

To build the project, run:

```bash
make
```

To run the game:

```bash
make run
```

To clean build artifacts:

```bash
make clean
```

## Controls

- **Left Arrow**: Move paddle left.
- **Right Arrow**: Move paddle right.
- **Esc**: Close the game.

## Project Structure

- `main.c`: Entry point and main game loop.
- `ball.c/h`: Ball logic and rendering.
- `paddle.c/h`: Paddle logic and rendering.
- `brick.c/h`: Brick structure and lifecycle.
- `game_state.c/h`: Game state management (score, lives).
- `settings.h`: Game constants (window size, speeds, counts).
- `my_helpers.c/h`: Utility functions for drawing and movement.
- `Makefile`: Build configuration for Windows/MinGW.

## License

MIT License (or your preferred license).
