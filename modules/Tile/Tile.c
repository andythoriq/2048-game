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
    static char colorCopy[16];
    strncpy(colorCopy, tile.color, sizeof(colorCopy) - 1);
    colorCopy[sizeof(colorCopy) - 1] = '\0';
    return colorCopy;
}

void setValue(Tile *tile, int newValue)
{
    tile->value = newValue;
}

void setColor(Tile *tile, char newColor[16])
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
        setColor(tile, AC_CYAN); 
    } else if (newValue == 32) {
        setColor(tile, AC_GREEN);
    } else if (newValue == 64) {
        setColor(tile, AC_YELLOW);
    } else if (newValue == 128) {
        setColor(tile, AC_YELLOW);
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
