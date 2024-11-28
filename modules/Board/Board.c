#include "Board.h"
#include "../Halaman_Lobby/Halaman_lobby.h"

// kami mengambil referensi untuk printBoard dari https://www.geeksforgeeks.org
// kami mengubah beberapa bagian seperti findlen, menambahkan warna, menengahkan papan, dll
// menambah variable left dan right space

void printBoard(Tile tiles[4][4])
{
	system("cls");
	int x_pos = (get_terminal_width('l')-33)/2;
	int y_pos = (get_terminal_width('t') - 9)/2;
	gotoxy(x_pos,y_pos);
	
    int i, j, k, left_space, right_space, digit, total_space = 7;
    
    printf("---------------------------------\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (j == 0) {
            	gotoxy(x_pos, y_pos+1+(2*i));
                printf("|");
            }

            int value = getValue(tiles[i][j]);
            if (value != 0) {
                digit = findlen(value);

                // jika 0, 2, 4, 8 maka digitnya adalah 1. jika 32, 64 maka digitnya adalah 2 ...
                left_space = (total_space - digit) / 2;
                right_space = total_space - digit - left_space;

                // Cetak spasi kiri
                for (k = 0; k < left_space; k++) {
                    printf(" ");
                }

                printf("%s%d%s", getColor(tiles[i][j]), value, AC_WHITE);

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
        }

        if (i != 3) {
        	gotoxy(x_pos, y_pos+2+(2*i));
            printf("---------------------------------\n");
        }
    }
    gotoxy(x_pos, y_pos + 8);
    printf("---------------------------------\n");
}

int findlen(int n)
{
    int digit = 0;
    if (n == 0) {
        return 1;
    }
    while (n > 0) {
        digit++;
        n /= 10;
    }
    return digit;
}
