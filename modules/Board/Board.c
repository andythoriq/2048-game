#include "Board.h"

static int len = 0;

void printBoard(Tile arr[4][4])
{
    int i, j, k, left_space, right_space, total_space = 7;

    printf("\t\t\t\t\t---------------------------------\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (j == 0) {
                printf("\t\t\t\t\t|");
            }

            int value = getValue(arr[i][j]);
            if (value != 0) {
                findlen(value);

                // len adalah digit nilai, jika satu digit, maka len: 1. jika tiga digit, maka len: 3.
                left_space = (total_space - len) / 2;
                right_space = total_space - len - left_space;

                // Cetak spasi kiri
                for (k = 0; k < left_space; k++) {
                    printf(" ");
                }

                printf("%s%d%s", getColor(arr[i][j]), value, AC_WHITE);

                // Cetak spasi kanan
                for (k = 0; k < right_space; k++) {
                    printf(" ");
                }

                printf("|");
            } else {
                // Jika nilainya 0, isi sel dengan spasi
                for (k = 0; k < total_space; k++) {
                    printf(" ");
                }
                printf("|");
            }
            len = 0;
        }

        if (i != 3) {
            printf("\n");
            printf("\t\t\t\t\t---------------------------------\n");
        }
    }
    printf("\n\t\t\t\t\t---------------------------------\n");
}

// Function to find the length of a number (count of digits)
void findlen(int n)
{
    len = 0;
    if (n == 0) {
        len = 1;
        return;
    }
    while (n > 0) {
        len++;
        n /= 10;
    }
}
