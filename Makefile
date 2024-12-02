# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source directories and files
SRC_DIR = modules
SOURCES = main.c \
           $(SRC_DIR)/Board/Board.c \
           $(SRC_DIR)/Gameplay/Gameplay.c \
           $(SRC_DIR)/GameWinOrLose/WinOrLose.c \
           $(SRC_DIR)/Halaman_Lobby/Halaman_lobby.c \
           $(SRC_DIR)/Halaman_Tutorial/HowToPlay.c \
           $(SRC_DIR)/Tile/Tile.c

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Target executable
TARGET = game2048

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Phony targets
.PHONY: all clean
