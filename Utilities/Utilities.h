#ifndef Utilities_H
#define Utilities_H

#include <windows.h>
#include <stdio.h>

DWORD WINAPI beepThread(LPVOID sound);

void play_sound(intptr_t TYPE_sound);

int get_middle_pos(char pos);						//memperoleh posisi tepat ditengah-tengah y

void printf_center (const char* text, int posisi_Y);	//untuk keperluan memprint text tepat berada di tengah-tengah halaman

void text_style (char text[], int style);		//membuat text menjadi pudar

void gotoxy(int x, int y);

int get_terminal_width(char width);

#endif
