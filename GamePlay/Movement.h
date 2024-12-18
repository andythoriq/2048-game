#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <ctype.h>

#include "../Struct/Tile.h"
#include "../Struct/Player.h"
#include "../Utilities/Utilities.h"

//nama author   : Andy Thoriq
//nama file     : Board.c
//deskripsi : 
/*file c yang berisi modul logika game atau cara permainan game berjalan. terdapat modul yang memproses
input user dan menggerakan tile sesuai input user tersebut sesuai logika game 2048 berjalan*/

//Modul untuk menggerakan angka pada board(tile) sesuai input {logika game}
void move(char choice, Tile tiles[4][4], Player *player);


#endif