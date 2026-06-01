# ============================================================
# Makefile — raylib project (Windows / MinGW)
# ============================================================

CC      = gcc
TARGET  = program.exe
SRC     = main.c ball.c paddle.c my_helpers.c brick.c game_state.c
OBJ     = $(SRC:.c=.o)
DEP     = $(SRC:.c=.d)

RAYLIB_SRC = C:/raylib/raylib/src

INCLUDES = -I$(RAYLIB_SRC)
LIBS     = -L$(RAYLIB_SRC) -lraylib -lopengl32 -lgdi32 -lwinmm

CFLAGS   = -Wall -std=c99 -MMD -MP $(INCLUDES)
LDFLAGS  = $(LIBS)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

run: $(TARGET)
	./$(TARGET)

clean:
	del /Q $(TARGET) *.o *.d 2>nul || true

.PHONY: all run clean