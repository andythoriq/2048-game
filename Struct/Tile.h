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

typedef struct Tile
{
    char color[32];
    int value;
} Tile;

void createTile(Tile * tile, int newValue);

int getValue(Tile tile);

const char * getColor(Tile tile);

void setValue(Tile *tile, int newValue);

void setColor(Tile *tile, char newColor[]);

void setValueAndColor(Tile *tile, int newValue);

void generateTiles(Tile tiles[4][4]);

void resetTiles(Tile tiles[4][4]);

void fillNumberInRandomPosition(Tile tiles[4][4]);

#endif