# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(game2048)




# Set the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Source files
set(SOURCES
    main.c
    GamePlay/Board.c
    GamePlay/Movement.c
    GamePlay/WinOrLose.c
    Pages/View_GamePlay.c
    Pages/View_InputUserName.c
    Pages/View_LeaderBoard.c
    Pages/View_LobbyScreen.c
    Pages/View_Tutorial.c
    Struct/Player.c
    Struct/Tile.c
    Utilities/File.c
    Utilities/Utilities.c
)

# Set output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the executable
add_executable(game2048 ${SOURCES})
