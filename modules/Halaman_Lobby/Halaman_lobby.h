#ifndef Halaman_Lobby_H
#define Halaman_Lobby_H

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

typedef struct{	//struct player memuat data username untuk di manipulasi file
	char name[9];
	int highsocre;
	char duration[5];
} Player;	//P nya gede

DWORD WINAPI beepThread(LPVOID sound);

void play_sound(intptr_t TYPE_sound);

int get_terminal_width(char width);		//memperoleh lebar dan panjang terminal [menggunakan windows.h]

int get_middle_y();						//memperoleh posisi tepat ditengah-tengah y

void gotoxy (int x, int y);				//memindahkan kursor pada posisi x dan y terntentu

void printf_center (const char* text, int posisi_Y);	//untuk keperluan memprint text tepat berada di tengah-tengah halaman

void shade_animation(char text[]);		//membuat text menjadi pudar

void lobby_screen (int selectedarrow);	//print halaman lobby awal

void input_username_screen();			//print halaman input username

void user_input_username(char username[]);				//modul untuk membuat tampilan saat input teks

#endif