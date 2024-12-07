#ifndef VIEW_GAMEPLAY_H
#define VIEW_GAMEPLAY_H

#include <stdbool.h>
#include "../Struct/Tile.h"
#include "../Struct/Player.h"


//nama author   : Muhamad Sopiana Argiansah, Andy Thoriq, Nauval Khairiyan
//nama file     : View_GamePlay.c
//deskripsi : 
/*file c yang berisi modul-modul pada halalman game berlangsung, seperti menampilkan board,
logika game, game result, dll.*/

//modul yang berisi modul-modul lain untuk membuat halaman saat game dimulai secara keseluruhan
void View_GamePlay(Tile tiles[4][4], Player *player);

#endif