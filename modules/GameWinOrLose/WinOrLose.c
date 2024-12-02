#include "WinOrLose.h"

int win_number = 2048;

// Memeriksa hasil permainan 
void game_result(Tile tiles[4][4]) {
	// Kamus Data
	// int tiles[4][4]; // nanti masukin angka yang selalu diperbarui dalam tilesnya

	char textMenang[] = "Selamat! Kamu Menang! Kamu Berhasil Mencapai Angka 2048";
	char textKalah[] = "Yahhh! Kamu Gagal. Jangan Menyerah, Ayo Coba Lagi!"; 
	char textEnter[] = "Silakan tekan 'enter' untuk mengulang permainan!";

	if (isGameWin(tiles)) {
		gotoxy((get_terminal_width('l') - strlen(textMenang))/2, get_middle_pos('y'));
		printf("%s", textMenang);
		gotoxy((get_terminal_width('l') - strlen(textEnter))/2, get_middle_pos('y') + 1);
		printf("%s", textEnter);
		generateTiles(tiles);
		getchar();
	} else if (isGameOver(tiles)) {
		gotoxy((get_terminal_width('l') - strlen(textKalah))/2, get_middle_pos('y'));
		printf("%s", textKalah);
		gotoxy((get_terminal_width('l') - strlen(textEnter))/2, get_middle_pos('y') + 1);
		printf("%s", textEnter);
		generateTiles(tiles);
		getchar();
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