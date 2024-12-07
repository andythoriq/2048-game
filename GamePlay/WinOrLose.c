#include <stdio.h>

#include "../Utilities/Utilities.h"
#include "../Utilities/File.h"

#include "WinOrLose.h"

//nama author   : Nauval Khairiyan
//nama file     : WinOrLose.c
//deskripsi : 
/*file c yang berisi modul-modul untuk memeriksa kondisi menang atau kalah.
lalu jika kondisi terpenuhi, hasil gameover/win akan di keluarkan*/


//**************//
/* program modul*/
//**************//


// Memeriksa hasil permainan 
void game_result(Tile tiles[4][4], Player *p, bool *game_finished) {
/* parameter :
tiles	: parameter input output (by adress) tiles saat ini (angka didalam modul)
p		: parameter input output (by adress) struct player saat ini
*game finished	: parameter input output (by adress) untuk kondisi game berakhir atau tidak*/


	//kamus data
	char* textMenang[] = {"********** CONGRATULATION **********","you reach number 2048"};
	char* textKalah[] = {"********** GAMEOVER **********", "there is no more space to move"}; 

	//jika kondisi menunjukan menang
	if (isGameWin(tiles)) {
		setTotalWin(p, getTotalWin(p) + 1);

		gotoxy((get_terminal_width('l') - strlen(textMenang[0]))/2, get_middle_pos('y'));
		printf("%s", textMenang[0]);
		gotoxy((get_terminal_width('l') - strlen(textMenang[1]))/2, get_middle_pos('y') + 2);
		printf("%s", textMenang[1]);
		*game_finished = true;
	
	//jika kondisi menunjukan kalah
	} else if (isGameOver(tiles)) {
		setTotalLose(p, getTotalLose(p) + 1);

		gotoxy((get_terminal_width('l') - strlen(textKalah[0]))/2, get_middle_pos('y'));
		printf("%s", textKalah[0]);
		gotoxy((get_terminal_width('l') - strlen(textKalah[1]))/2, get_middle_pos('y') + 1);
		printf("%s", textKalah[1]);
		*game_finished = true;
	}

	printf("\n");
}

//Function untuk memeriksa apakah pemain kalah
bool isGameOver(Tile tiles[4][4]) {

	//kamus data
	int i; int j;
	
	//Cek jika masih ada langkah valid horizontal atau vertikal
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (getValue(tiles[i][j]) == 0) return false;
			if (i > 0 && getValue(tiles[i][j]) == getValue(tiles[i - 1][j])) return false;
			if (j > 0 && getValue(tiles[i][j]) == getValue(tiles[i][j - 1])) return false;
		}
	}
	
	//Tidak ada langkah yang valid lagi
	return true;
}

// Function untuk memeriksa apakah pemain menang
bool isGameWin(Tile tiles[4][4]) {
	//kamus data
	int win_number = 2048;
	int i; int j;


	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (getValue(tiles[i][j]) == win_number) { 
				return true;
			}
		}
	}
	
	return false;
} 

