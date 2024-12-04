#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "Tile.h"

void createTile(Tile * tile, int newValue)
{
    setValue(tile, newValue);
    setColor(tile, AC_BLACK);
}

int getValue(Tile tile)
{
    return tile.value;
}

const char * getColor(Tile tile)
{
    static char colorCopy[32];
    strncpy(colorCopy, tile.color, sizeof(colorCopy) - 1);
    colorCopy[sizeof(colorCopy) - 1] = '\0';
    return colorCopy;
}

void setValue(Tile *tile, int newValue)
{
    tile->value = newValue;
}

void setColor(Tile *tile, char newColor[32])
{
    strncpy(tile->color, newColor, sizeof(tile->color) - 1);
    tile->color[sizeof(tile->color) - 1] = '\0';
}

void setValueAndColor(Tile *tile, int newValue)
{
    setValue(tile, newValue);
    if (newValue == 8) {
        setColor(tile, AC_WHITE);
    } else if (newValue == 16) {
        setColor(tile, AC_YELLOW); 
    } else if (newValue == 32) {
        setColor(tile, AC_YELLOW);
    } else if (newValue == 64) {
        setColor(tile, AC_CYAN);
    } else if (newValue == 128) {
        setColor(tile, AC_GREEN);
    } else if (newValue == 256) {
        setColor(tile, AC_BLUE);
    } else if (newValue == 512) {
        setColor(tile, AC_MAGENTA);
    } else if (newValue == 1024) {
        setColor(tile, AC_RED);
    } else if (newValue == 2048) {
        setColor(tile, AC_RED);
    } else {
        setColor(tile, AC_BLACK);
    }
}

void generateTiles(Tile tiles[4][4])
{
	int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            createTile(&tiles[i][j], 0);
        }
    }

    fillNumberInRandomPosition(tiles);
    fillNumberInRandomPosition(tiles);
}

void resetTiles(Tile tiles[4][4])
{
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            setValueAndColor(&tiles[i][j], 0);
        }
    }
}

void fillNumberInRandomPosition(Tile tiles[4][4])
{
    int x, y = 0, number = 2;

    bool isValid = false;

    while (!isValid)
    {
        // get random position
        x = rand() % 4;
        y = rand() % 4;

        // cek apakah pada posisi x y kosong
        if (getValue(tiles[y][x]) == 0) {
            setValue(&tiles[y][x], number);
            isValid = true;
        }
    }
}