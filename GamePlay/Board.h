#ifndef Board_H
#define Board_H

#include "../Struct/Tile.h"
#include "../Struct/Player.h"

int findlen(int n);

void printBoard(Tile tiles[4][4], Player *p);

#endif