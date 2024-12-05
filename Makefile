# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source directories and files
SRC_G = GamePlay
SRC_P = Pages
SRC_S = Struct
SRC_U = Utilities
SOURCES = main.c \
           $(SRC_G)/Board.c \
           $(SRC_G)/Movement.c \
           $(SRC_G)/WinOrLose.c \
           $(SRC_P)/View_GamePlay.c \
           $(SRC_P)/View_InputUserName.c \
           $(SRC_P)/View_LeaderBoard.c \
           $(SRC_P)/View_LobbyScreen.c \
           $(SRC_P)/View_Tutorial.c \
           $(SRC_S)/Player.c \
           $(SRC_S)/Tile.c \
           $(SRC_U)/File.c \
           $(SRC_U)/Utilities.c 

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Target executable
TARGET = game2048

# Directory for build
BUILD_DIR = build
RESOURCES_DIR = resources

# Copy resources
resources:
	mkdir -p $(BUILD_DIR)/$(RESOURCES_DIR)
	cp -r $(RESOURCES_DIR)/* $(BUILD_DIR)/$(RESOURCES_DIR)/

# Default target
all: resources $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET) $(OBJECTS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJECTS) $(BUILD_DIR)/$(TARGET)
	rm -rf $(BUILD_DIR)/$(RESOURCES_DIR)

# Phony targets
.PHONY: all clean resources
