#ifndef WINORLOSE_H
#define WINORLOSE_H

#include <stdbool.h>
#include "../Struct/Tile.h"
#include "../Struct/Player.h"

extern int win_number;

void game_result(Tile tiles[4][4], Player *p, bool *game_finished);

bool isGameOver(Tile tiles[4][4]);

bool isGameWin(Tile tiles[4][4]);


#endif