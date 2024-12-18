#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#ifndef Tile_H
#define Tile_H

#define AC_BLACK "\x1b[90m"
#define AC_RED "\x1b[91m"
#define AC_GREEN "\x1b[92m"
#define AC_YELLOW "\x1b[93m"
#define AC_BLUE "\x1b[94m"
#define AC_MAGENTA "\x1b[95m"
#define AC_CYAN "\x1b[96m"
#define AC_WHITE "\x1b[97m"


//nama author   : Andy Thoriq
//nama file     : Player.c
//deskripsi : 
/*file c yang berisi struct tile (angka-angka pada board), 
juga segala modul-modul yang berkaitan dengan
manipulasi tiles*/


//**************//
/* program modul*/
//**************//


//mendeklarasikan struct tiles
typedef struct Tile
{
    char color[32];
    int value;
} Tile;

//modul untuk untuk mengisi tile dengan nilai baru
void createTile(Tile * tile, int newValue);

//modul untuk memperoleh nilai pada tile[i][j] sesuai i j yang di tulis
int getValue(Tile tile);

//modul untuk memperoleh warna sesuai  nilai dari angka yang dimasukan
const char * getColor(Tile tile);

//modul untuk memberikan nilai baru pada salah satu indeks pada tile
void setValue(Tile *tile, int newValue);

//modul untuk menentukan warna pada salah satu indeks tile sesuai nilai nya
void setColor(Tile *tile, char newColor[]);

//modul untuk memberikan nilai dan warna pada salah satu indesk tile
void setValueAndColor(Tile *tile, int newValue);

//modul untuk mengosongkan seluruh tile dan memberikan 2 angka random pada posisi random
void generateTiles(Tile tiles[4][4]);

//modul untuk menghapus seluruh isi pada tile
void resetTiles(Tile tiles[4][4]);

//modul untuk memberikan random angka pada random posisi
void fillNumberInRandomPosition(Tile tiles[4][4]);

#endif