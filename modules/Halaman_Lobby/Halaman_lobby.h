#ifndef Halaman_Lobby_h
#define Halaman_Lobby_h

#include <stdio.h>  	 //standar input output
#include <stdlib.h>		//manipulasi memori
#include <string.h>		//mempermudah print dan input string
#include <conio.h>		//mempermudah proses input output char
#include <windows.h>	//menggunakan system-system window 
#include <stdbool.h>	//boolean
#include <stdint.h>		//menambahkan syntax tipe data intptr_t dll

#include "../../util/util.h"

#define UP_ARROW 72
#define DOWN_ARROW 80
#define ENTER 13


// int get_terminal_width(char width);

int get_middle_y();

// void gotoxy (int x, int y);

void printf_center (const char* text, int posisi_Y);

void shade_animation(char text[]);

void lobby_screen (int selectedarrow);

void input_username();

#endif