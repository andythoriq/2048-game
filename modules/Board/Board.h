#ifndef Board_H
#define Board_H

#include <stdio.h>

#include "../Tile/Tile.h"
#include "../../Utilities/Utilities.h"

int findlen(int n);

void printBoard(Tile tiles[4][4], int score, int total_move);

#endif