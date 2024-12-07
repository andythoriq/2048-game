#include <stdio.h>

#include "../Utilities/Utilities.h"
#include "../Utilities/File.h"

#include "WinOrLose.h"

int win_number = 2048;

// Memeriksa hasil permainan 
void game_result(Tile tiles[4][4], Player *p, bool *game_finished) {
	// Kamus Data
	// int tiles[4][4]; // nanti masukin angka yang selalu diperbarui dalam tilesnya
	char* textMenang[] = {"********** CONGRATULATION **********","you reach number 2048"};
	char* textKalah[] = {"********** GAMEOVER **********", "there is no more space to move"}; 


	if (isGameWin(tiles)) {
		setTotalWin(p, getTotalWin(p) + 1);

		gotoxy((get_terminal_width('l') - strlen(textMenang[0]))/2, get_middle_pos('y'));
		printf("%s", textMenang[0]);
		gotoxy((get_terminal_width('l') - strlen(textMenang[1]))/2, get_middle_pos('y') + 2);
		printf("%s", textMenang[1]);
		*game_finished = true;
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

// Function untuk memeriksa apakah pemain kalah
bool isGameOver(Tile tiles[4][4]) {
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

