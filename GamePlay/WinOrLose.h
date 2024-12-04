#ifndef WINORLOSE_H
#define WINORLOSE_H

extern int win_number;

void game_result(Tile tiles[4][4]);

bool isGameOver(Tile tiles[4][4]);

bool isGameWin(Tile tiles[4][4]);

#endif