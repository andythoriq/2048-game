#ifndef WINORLOSE_H
#define WINORLOSE_H

#include <stdbool.h>
#include "../Struct/Tile.h"
#include "../Struct/Player.h"

extern int win_number;

void game_result(Tile tiles[4][4]);

bool isGameOver(Tile tiles[4][4]);

bool isGameWin(Tile tiles[4][4]);

void check_highscore(Player *p);

void check_highmove(Player *p);

#endif