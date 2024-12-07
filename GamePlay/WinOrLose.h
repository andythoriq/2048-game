#ifndef WINORLOSE_H
#define WINORLOSE_H

#include <stdbool.h>
#include "../Struct/Tile.h"
#include "../Struct/Player.h"

//nama author   : Nauval Khairiyan
//nama file     : WinOrLose.c
//deskripsi : 
/*file c yang berisi modul-modul untuk memeriksa kondisi menang atau kalah.
lalu jika kondisi terpenuhi, hasil gameover/win akan di keluarkan*/

//variable untuk seluruh modul
extern int win_number;

//modul untuk memeriksa apakah gameover / win game
void game_result(Tile tiles[4][4], Player *p, bool *game_finished);

//function bertipe bool, untuk memeriksa kondisi kalah
bool isGameOver(Tile tiles[4][4]);

//function bertipe bool, untuk memeriksa kondisi menang
bool isGameWin(Tile tiles[4][4]);


#endif