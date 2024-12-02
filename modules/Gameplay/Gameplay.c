#include "Gameplay.h"

void move(char choice, Tile arr[4][4])
{
	printf("\033[2J");
//	system("cls");
	int col, row, k, i, j, arr_before[4][4];

    for ( i = 0; i < 4; i++) {
        for ( j = 0; j < 4; j++) {
            arr_before[i][j] = getValue(arr[i][j]);
        }
    }

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

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (arr_before[i][j] != getValue(arr[i][j])) {
                fillNumberInRandomPosition(arr);
                return;
            }
        }
    }
}

void generateTiles(Tile arr[4][4])
{
	int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            createTile(&arr[i][j], 0);
        }
    }

    fillNumberInRandomPosition(arr);
    fillNumberInRandomPosition(arr);
}

void resetTiles(Tile arr[4][4])
{
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            setValueAndColor(&arr[i][j], 0);
        }
    }
}

void fillNumberInRandomPosition(Tile arr[4][4])
{
    int x, y = 0, number = 2;

    bool isValid = false;

    while (!isValid)
    {
        // get random position
        x = rand() % 4;
        y = rand() % 4;

        // cek apakah pada posisi x y kosong
        if (getValue(arr[y][x]) == 0) {
            setValue(&arr[y][x], number);
            isValid = true;
        }
    }
}