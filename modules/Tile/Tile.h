#ifndef Tile_H
#define Tile_H

#include <string.h>

typedef struct Tile
{
    char color[32];
    int value;
} Tile;

#define AC_BLACK "\x1b[90m"
#define AC_RED "\x1b[91m"
#define AC_GREEN "\x1b[92m"
#define AC_YELLOW "\x1b[93m"
#define AC_BLUE "\x1b[94m"
#define AC_MAGENTA "\x1b[95m"
#define AC_CYAN "\x1b[96m"
#define AC_WHITE "\x1b[97m"

void createTile(Tile * tile, int newValue);

int getValue(Tile tile);

const char * getColor(Tile tile);

void setValue(Tile *tile, int newValue);

void setColor(Tile *tile, char newColor[32]);

void setValueAndColor(Tile *tile, int newValue);

#endif