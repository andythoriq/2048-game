#include "Tile.h"

void createTile(Tile * tile)
{
    setValue(tile, 64);
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

// pindahin ini ke modul pergerakan
void move(char choice, Tile arr[4][4])
{
	system("cls");
	int col, row, k;
    switch (choice) {
        case 'w':
            for (col = 0; col < 4; col++) { // col: 0 1 2 3
                // sort
                for (row = 0; row < 3; row++) { // row: 0 1 2
                    for (k = row + 1; k < 4; k++) { // k: 1 2 3
                        if (getValue(arr[row][col]) == 0 && getValue(arr[k][col]) != 0) {
                            setValueAndColor(&arr[row][col], getValue(arr[k][col]));
                            setValueAndColor(&arr[k][col], 0);
                            break;
                        }
                    }
                }
                // sum
                for (row = 0; row < 3; row++) {
                    if (getValue(arr[row][col]) == getValue(arr[row + 1][col]) && getValue(arr[row][col]) != 0) {
                        setValueAndColor(&arr[row][col], getValue(arr[row][col]) * 2);
                        setValueAndColor(&arr[row + 1][col], 0);
                    }
                }
                // sort
                for (row = 0; row < 3; row++) {
                    for (k = row + 1; k < 4; k++) {
                        if (getValue(arr[row][col]) == 0 && getValue(arr[k][col]) != 0) {
                            setValueAndColor(&arr[row][col], getValue(arr[k][col]));
                            setValueAndColor(&arr[k][col], 0);
                            break;
                        }
                    }
                }
            }
            break;
        case 'd':
            for (row = 0; row < 4; row++) { // row: 0 1 2 3
                // sort
                for (col = 3; col > 0; col--) { // col: 3 2 1
                    for (k = col - 1; k >= 0; k--) { // k: 2 1 0
                        if (getValue(arr[row][col]) == 0 && getValue(arr[row][k]) != 0) {
                            setValueAndColor(&arr[row][col], getValue(arr[row][k]));
                            setValueAndColor(&arr[row][k], 0);
                            break;
                        }
                    }
                }
                // sum
                for (col = 3; col > 0; col--) {
                    if (getValue(arr[row][col]) == getValue(arr[row][col - 1]) && getValue(arr[row][col]) != 0) {
                        setValueAndColor(&arr[row][col], getValue(arr[row][col]) * 2);
                        setValueAndColor(&arr[row][col - 1], 0);
                    }
                }
                // sort
                for (col = 3; col > 0; col--) {
                    for (k = col - 1; k >= 0; k--) {
                        if (getValue(arr[row][col]) == 0 && getValue(arr[row][k]) != 0) {
                            setValueAndColor(&arr[row][col], getValue(arr[row][k]));
                            setValueAndColor(&arr[row][k], 0);
                            break;
                        }
                    }
                }
            }
            break;
        case 's':
            for (col = 0; col < 4; col++) {
                // sort
                for (row = 3; row > 0; row--) {
                    for (k = row - 1; k >= 0; k--) {
                        if (getValue(arr[row][col]) == 0 && getValue(arr[k][col]) != 0) {
                            setValueAndColor(&arr[row][col], getValue(arr[k][col]));
                            setValueAndColor(&arr[k][col], 0);
                            break;
                        }
                    }
                }
                // sum
                for (row = 3; row > 0; row--) {
                    if (getValue(arr[row][col]) == getValue(arr[row - 1][col]) && getValue(arr[row][col]) != 0) {
                        setValueAndColor(&arr[row][col], getValue(arr[row][col]) * 2);
                        setValueAndColor(&arr[row - 1][col], 0);
                    }
                }
                // sort
                for (row = 3; row > 0; row--) {
                    for (k = row - 1; k >= 0; k--) {
                        if (getValue(arr[row][col]) == 0 && getValue(arr[k][col]) != 0) {
                            setValueAndColor(&arr[row][col], getValue(arr[k][col]));
                            setValueAndColor(&arr[k][col], 0);
                            break;
                        }
                    }
                }
            }
            break;
        case 'a':
            for (row = 0; row < 4; row++) { // row: 0 1 2 3
                // sort
                for (col= 0; col < 3; col++) { // col: 0 1 2
                    for (k = col + 1; k < 4; k++) { // k: 1 2 3
                        if (getValue(arr[row][col]) == 0 && getValue(arr[row][k]) != 0) {
                            setValueAndColor(&arr[row][col], getValue(arr[row][k]));
                            setValueAndColor(&arr[row][k], 0);
                            break;
                        }
                    }
                }
                // sum
                for (col = 0; col < 3; col++) {
                    if (getValue(arr[row][col]) == getValue(arr[row][col + 1]) && getValue(arr[row][col]) != 0) {
                        setValueAndColor(&arr[row][col], getValue(arr[row][col]) * 2);
                        setValueAndColor(&arr[row][col + 1], 0);
                    }
                }
                // sort
                for (col = 0; col < 3; col++) {
                    for ( k = col + 1; k < 4; k++) {
                        if (getValue(arr[row][col]) == 0 && getValue(arr[row][k]) != 0) {
                            setValueAndColor(&arr[row][col], getValue(arr[row][k]));
                            setValueAndColor(&arr[row][k], 0);
                            break;
                        }
                    }
                }
            }
            break;
    }
}

// pindahin ini ke modul tiles
void generateTiles(Tile arr[4][4])
{
	int i,j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            createTile(&arr[i][j]);
        }
    }
}