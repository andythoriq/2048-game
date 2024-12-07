#include "Movement.h"

//nama author   : Andy Thoriq
//nama file     : Movement.c
//deskripsi : 
/*file c yang berisi modul untuk membuat dan menampilakan board
pada halaman saat game dimulai. board digunakan sebagai tempat angka(tiles berada)*/

//Modul untuk menggerakan angka pada board(tile) sesuai input {logika game}
void move(char choice, Tile tiles[4][4], Player *p)
{
    //membersihkan layar
	clearscreen();

    //kamus data
	int col, row, k, i, j, arr_before[4][4];

    //**************//
    /* program modul*/
    //**************//
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arr_before[i][j] = getValue(tiles[i][j]);
        }
    }

    switch (choice) {
        case 'w':
            for (col = 0; col < 4; col++) { // col: 0 1 2 3
                // sort
                for (row = 0; row < 3; row++) { // row: 0 1 2
                    for (k = row + 1; k < 4; k++) { // k: 1 2 3
                        if (getValue(tiles[row][col]) == 0 && getValue(tiles[k][col]) != 0) {
                            setValueAndColor(&tiles[row][col], getValue(tiles[k][col]));
                            setValueAndColor(&tiles[k][col], 0);
                            break;
                        }
                    }
                }
                // sum
                for (row = 0; row < 3; row++) {
                    if (getValue(tiles[row][col]) == getValue(tiles[row + 1][col]) && getValue(tiles[row][col]) != 0) {
                        setValueAndColor(&tiles[row][col], getValue(tiles[row][col]) * 2);
                        // hitung score
                        setScore(p, getScore(p) + getValue(tiles[row][col]));
                        setValueAndColor(&tiles[row + 1][col], 0);
                    }
                }
                // sort
                for (row = 0; row < 3; row++) {
                    for (k = row + 1; k < 4; k++) {
                        if (getValue(tiles[row][col]) == 0 && getValue(tiles[k][col]) != 0) {
                            setValueAndColor(&tiles[row][col], getValue(tiles[k][col]));
                            setValueAndColor(&tiles[k][col], 0);
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
                        if (getValue(tiles[row][col]) == 0 && getValue(tiles[row][k]) != 0) {
                            setValueAndColor(&tiles[row][col], getValue(tiles[row][k]));
                            setValueAndColor(&tiles[row][k], 0);
                            break;
                        }
                    }
                }
                // sum
                for (col = 3; col > 0; col--) {
                    if (getValue(tiles[row][col]) == getValue(tiles[row][col - 1]) && getValue(tiles[row][col]) != 0) {
                        setValueAndColor(&tiles[row][col], getValue(tiles[row][col]) * 2);
                        // hitung score
                        setScore(p, getScore(p) + getValue(tiles[row][col]));
                        setValueAndColor(&tiles[row][col - 1], 0);
                    }
                }
                // sort
                for (col = 3; col > 0; col--) {
                    for (k = col - 1; k >= 0; k--) {
                        if (getValue(tiles[row][col]) == 0 && getValue(tiles[row][k]) != 0) {
                            setValueAndColor(&tiles[row][col], getValue(tiles[row][k]));
                            setValueAndColor(&tiles[row][k], 0);
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
                        if (getValue(tiles[row][col]) == 0 && getValue(tiles[k][col]) != 0) {
                            setValueAndColor(&tiles[row][col], getValue(tiles[k][col]));
                            setValueAndColor(&tiles[k][col], 0);
                            break;
                        }
                    }
                }
                // sum
                for (row = 3; row > 0; row--) {
                    if (getValue(tiles[row][col]) == getValue(tiles[row - 1][col]) && getValue(tiles[row][col]) != 0) {
                        setValueAndColor(&tiles[row][col], getValue(tiles[row][col]) * 2);
                        // hitung score
                        setScore(p, getScore(p) + getValue(tiles[row][col]));
                        setValueAndColor(&tiles[row - 1][col], 0);
                    }
                }
                // sort
                for (row = 3; row > 0; row--) {
                    for (k = row - 1; k >= 0; k--) {
                        if (getValue(tiles[row][col]) == 0 && getValue(tiles[k][col]) != 0) {
                            setValueAndColor(&tiles[row][col], getValue(tiles[k][col]));
                            setValueAndColor(&tiles[k][col], 0);
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
                        if (getValue(tiles[row][col]) == 0 && getValue(tiles[row][k]) != 0) {
                            setValueAndColor(&tiles[row][col], getValue(tiles[row][k]));
                            setValueAndColor(&tiles[row][k], 0);
                            break;
                        }
                    }
                }
                // sum
                for (col = 0; col < 3; col++) {
                    if (getValue(tiles[row][col]) == getValue(tiles[row][col + 1]) && getValue(tiles[row][col]) != 0) {
                        setValueAndColor(&tiles[row][col], getValue(tiles[row][col]) * 2);
                        // hitung score
                        setScore(p, getScore(p) + getValue(tiles[row][col]));
                        setValueAndColor(&tiles[row][col + 1], 0);
                    }
                }
                // sort
                for (col = 0; col < 3; col++) {
                    for ( k = col + 1; k < 4; k++) {
                        if (getValue(tiles[row][col]) == 0 && getValue(tiles[row][k]) != 0) {
                            setValueAndColor(&tiles[row][col], getValue(tiles[row][k]));
                            setValueAndColor(&tiles[row][k], 0);
                            break;
                        }
                    }
                }
            }
            break;
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (arr_before[i][j] != getValue(tiles[i][j])) {
                // tambah total move (gerakan yang valid)
                setMove(p, getMove(p) + 1);
                fillNumberInRandomPosition(tiles);
                return;
            }
        }
    }
}
