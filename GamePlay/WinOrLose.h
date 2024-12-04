#ifndef WINORLOSE_H
#define WINORLOSE_H

#include <stdbool.h>
#include "../Struct/Tile.h"

extern int win_number;

void game_result(Tile tiles[4][4]);

bool isGameOver(Tile tiles[4][4]);

bool isGameWin(Tile tiles[4][4]);

#endif