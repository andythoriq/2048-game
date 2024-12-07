#include <stdio.h>

#include "../Utilities/Utilities.h"

#include "Board.h"

//nama author   : Andy Thoriq
//nama file     : Board.c
//deskripsi : 
/*file c yang berisi modul untuk membuat dan menampilakan board
pada halaman saat game dimulai. board digunakan sebagai tempat angka(tiles berada)*/

//**************//
/* program modul*/
//**************//

/*** Modul untuk membuat dan menampilkan board ***/
void printBoard(Tile arr[4][4], Player *p)
{
    //membersihkan layar
	clearscreen();

    //deklarasi titik posisi ujung kiri atas board
	int x_pos = (get_terminal_width('l')-33)/2;
	int y_pos = (get_terminal_width('t') - 9)/2;

	//kamus data lokal
    int i, j, k, left_space, right_space, digit, total_space = 7;

    //menampilkan teks "press enter to esc" dengan background putih
    gotoxy(0, y_pos - 3);
    printf("\033[48;5;255m\033[30m");		    //memberikan efek background
    printf("[press 'ESC' to finish the Game]");
    printf("\033[0m");						    // mengembalikan setingan default teks

    //menampilkan teks "press 'r' to reset" dengan backgorund putih
    gotoxy(0, y_pos - 1);
    printf("\033[48;5;255m\033[30m");		    //memberikan efek background
    printf("[press 'r' to reset the Game]");
    printf("\033[0m");	

    //menampilkan teks score dan move pada sisi kiri halaman
    gotoxy(0, y_pos);
    printf("---------------------------------\n");
    printf("HIGH SCORE : %d\n", getComparedHighScore(p));
    printf("HIGH MOVE : %d\n", getComparedHighMove(p));
    printf("SCORE : %d\n", getScore(p));
    printf("MOVE  : %d\n", getMove(p));
    printf("---------------------------------\n");

    //membuat board menggunakan sistem itterasi
    gotoxy(x_pos,y_pos); 
    printf("---------------------------------\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (j == 0) {
            	gotoxy(x_pos, y_pos+1+(2*i));
                printf("|");                    //border sebelah kiri
            }

            int value = getValue(arr[i][j]);    //## memanggil function getValue() untuk memperoleh angka pada arr[i][j]
            if (value != 0) {
                digit = findlen(value);         //## memanggil function findlen() untuk memperoleh jumlah angka pada arr[i][j]

                // jika 0, 2, 4, 8 maka digitnya adalah 1. jika 32, 64 maka digitnya adalah 2 ...
                left_space = (total_space - digit) / 2;
                right_space = total_space - digit - left_space;

                // Cetak spasi kiri
                for (k = 0; k < left_space; k++) {
                    printf(" ");
                }

                /* menampilkan angka pada bagian board sesuai posisi i dan j*/
                printf("%s%d%s", getColor(arr[i][j]), value, AC_WHITE);
                /************************************************************/

                // Cetak spasi kanan
                for (k = 0; k < right_space; k++) {
                    printf(" ");
                }

                printf("|");    //border pemisah tiap angka/kolom

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
            printf("---------------------------------\n");      //border pemisah tiap baris
        }
    }
    gotoxy(x_pos, y_pos + 8);
    printf("---------------------------------\n");      //border bagian bawah

    //menampilkan username yang bermain saat ini pada tengah kiri halaman
    gotoxy((35 - strlen(getUsername(p))) / 2, y_pos + 7);
    printf("%s", getUsername(p));

    //menampilkan ddeskripsi tombol-tombol pada kiri bawah halaman
    gotoxy(0, y_pos + 9);
    printf("---------------------------------\n");
    printf("TEKAN\n");
    printf("W untuk bergerak ke ATAS\n");
    printf("A untuk bergerak ke KIRI\n");
    printf("S untuk bergerak ke BAWAH\n");
    printf("D untuk bergerak ke KANAN\n");
    printf("---------------------------------\n");
}

/*** Modul untuk memperoleh jumlah angka pada variable {misal 20 jumlahnya adalah 2 angka} ***/
int findlen(int n)
{
    //kamus data lokal
    int digit = 0;

    //jika digit 0
    if (n == 0) {
        return 1;
    }

    //jika digit lebih dari 0
    while (n > 0) {
        digit++;
        n /= 10;
    }

    //mengembalikan nilai digit
    return digit;
}