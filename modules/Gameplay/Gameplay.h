#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "../Tile/Tile.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Berisiskan helper atau fungsi logika game 2048

// ubah ini menjadi global variabel di main atau masukkan ke dalam attribute User di main
extern int score;
extern int total_move;

void move(char choice, Tile tiles[4][4]);

void generateTiles(Tile tiles[4][4]);

void resetTiles(Tile tiles[4][4]);

void fillNumberInRandomPosition(Tile tiles[4][4]);

#endif