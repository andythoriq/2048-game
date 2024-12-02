#ifndef Halaman_Lobby_H
#define Halaman_Lobby_H

#include <stdio.h>  	 //standar input output
#include <stdlib.h>		//manipulasi memori
#include <string.h>		//mempermudah print dan input string
#include <conio.h>		//mempermudah proses input output char
#include <windows.h>	//menggunakan system-system window 
#include <stdbool.h>	//boolean
#include <stdint.h>		//menambahkan syntax tipe data intptr_t dll

#include "../../Utilities/Utilities.h"
#include "../File/File.h"

#define UP_ARROW 72
#define DOWN_ARROW 80
#define RIGHT_ARROW 77
#define LEFT_ARROW 75
#define ENTER 13
#define ESC 27
#define BACKSPACE 8

void lobby_screen (int selectedarrow);	//print halaman lobby awal

void input_username_screen();			//print halaman input username

void username_input_check(char username[], char input, int *i, int *result);				//modul untuk membuat tampilan saat input teks

#endif