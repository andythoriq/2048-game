#include "WinOrLose.h"

int win_number = 2048;

// Memeriksa hasil permainan 
void game_result(Tile tiles[4][4]) {
	// Kamus Data
	// int tiles[4][4]; // nanti masukin angka yang selalu diperbarui dalam tilesnya

	if (isGameWin(tiles)) {
		printf("Selamat! Kamu Menang! Kamu Berhasil Mencapai Angka 2048\nSilakan tekan 'enter' untuk mengulang permainan!");
		generateTiles(tiles);
		getchar();
	} else if (isGameOver(tiles)) {
		printf("Yahhh! Kamu Gagal. Jangan Menyerah, Ayo Coba Lagi!\nSilakan tekan 'enter' untuk mengulang permainan!");
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