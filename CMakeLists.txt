# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(Game2048)

# Set the C standard
# set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Source files
set(SOURCES
    main.c
    modules/Board/Board.c
    modules/File/File.c
    modules/Gameplay/Gameplay.c
    modules/GameWinOrLose/WinOrLose.c
    modules/Halaman_Lobby/Halaman_lobby.c
    modules/Halaman_Tutorial/HowToPlay.c
    modules/Tile/Tile.c
    util/util.c
)

# Add the executable
add_executable(game2048 ${SOURCES})
