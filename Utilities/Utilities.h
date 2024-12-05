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

<<<<<<< HEAD
=======
void clearscreen ();

>>>>>>> ganti-player-menjadi-array
DWORD WINAPI beepThread(LPVOID sound);

void play_sound(intptr_t TYPE_sound);

int get_middle_pos(char pos);						//memperoleh posisi tepat ditengah-tengah y

void printf_center (const char* text, int posisi_Y);	//untuk keperluan memprint text tepat berada di tengah-tengah halaman

void text_style (char text[], int style);		//membuat text menjadi pudar

void gotoxy(int x, int y);

int get_terminal_width(char width);

void selectedarrow_text (int *selectedarrow, int *key);

#endif
