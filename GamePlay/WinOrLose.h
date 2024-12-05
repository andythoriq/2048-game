#ifndef WINORLOSE_H
#define WINORLOSE_H

#include <stdbool.h>
#include <stdio.h>
#include "../Tile/Tile.h"
#include "../Gameplay/Gameplay.h"
#include "../../Utilities/Utilities.h"

extern int win_number;

void game_result(Tile tiles[4][4]);

bool isGameOver(Tile tiles[4][4]);

bool isGameWin(Tile tiles[4][4]);

#endif