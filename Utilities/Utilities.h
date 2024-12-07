#ifndef Utilities_H
#define Utilities_H

#define UP_ARROW 72
#define DOWN_ARROW 80
#define RIGHT_ARROW 77
#define LEFT_ARROW 75
#define ENTER 13
#define ESC 27
#define BACKSPACE 8

#include <windows.h>
#include <conio.h>
#include <stdio.h>


//nama author   : Muhamad Sopiana Argiansah
//nama file     : Utilities.c
//deskripsi : 
/*file c yang berisi modul-modul untuk keperluan tampilan
dan banyak dipanggil di halaman lain */


//modul untuk membersihka layar pada terminal
void clearscreen ();

//modul uutuk mengaktifkan bunyi beep pada thread lain
DWORD WINAPI beepThread(LPVOID sound);

//modul untuk memnaggil thread untuk membunyikan beep
void play_sound(intptr_t TYPE_sound);

//modul untuk memindahkan kursor ke posisi x, y tertentu
void gotoxy(int x, int y);

//modul untuk memperoleh ukuran terminal saat ini
int get_terminal_width(char width);

//modul untuk memperoleh posisi x/y pas ditengah2 teminal
int get_middle_pos(char pos);

//modul untuk memprint text tepat dibagian tengah(x) halaman
void printf_center (const char* text, int posisi_Y);	

//modul untuk mengubah style pada text 
void text_style (char text[], int style);	

//modul untuk memperoleh input user pada saat selectedkey di lobby
void selectedarrow_text (int *selectedarrow, int *key);

#endif
