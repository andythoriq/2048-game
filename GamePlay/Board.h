#ifndef Board_H
#define Board_H

#include "../Struct/Tile.h"
#include "../Struct/Player.h"

//nama author   : Andy Thoriq
//nama file     : Board.c
//deskripsi : 
/*file c yang berisi modul untuk membuat dan menampilakan board
pada halaman saat game dimulai. board digunakan sebagai tempat angka(tiles berada)*/

//function untuk memperoleh panjang atau jumlah digit pada variable int
int findlen(int n);

//modul untuk membuat dan menampilkan  board pada halaman game dimulai
void printBoard(Tile tiles[4][4], Player *p);

#endif