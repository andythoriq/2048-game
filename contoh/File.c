#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "File.h"

// Fungsi untuk membaca/mencari data berdasarkan username
void getPlayerData(const char *filename, const char *targetUsername, Player *player) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Gagal membuka file");
        return;
    }

    Player temp;
    int found = 0;

    // Cari username di dalam file
    while (fscanf(file, "%s %d %d %d %d %d", temp.username, &temp.highscore, &temp.highmove, &temp.duration, &temp.totalwin, &temp.totallose) != EOF) {
        if (strcmp(temp.username, targetUsername) == 0) {
            // Jika username ditemukan
            found = 1;
            *player = temp; // Salin data ke output parameter
            break;
        }
    }

    fclose(file);

    if (!found) {
        // Jika username tidak ditemukan, buat data baru
        strcpy(player->username, targetUsername);
        player->highscore = 0;
        player->highmove = 0;
        player->duration = 0;
        player->totalwin = 0;
        player->totallose = 0;
        // Tambahkan data baru ke file
        addPlayer(filename, *player);
    }
}

// Fungsi untuk menambahkan data baru dan menjaga agar file tetap terurut
void addPlayer(const char *filename, Player newPlayer) {
    FILE *file = fopen(filename, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        perror("Gagal membuka file");
        return;
    }

    Player temp;
    int added = 0;

    // Salin data lama ke file sementara, sambil menambahkan data baru secara terurut
    while (fscanf(file, "%s %d %d %d %d %d", temp.username, &temp.highscore, &temp.highmove, &temp.duration, &temp.totalwin, &temp.totallose) != EOF) {
        if (!added && newPlayer.highscore > temp.highscore) {
            // Tambahkan data baru jika highscore lebih besar
            fprintf(tempFile, "%s %d %d %d %d %d\n", newPlayer.username, newPlayer.highscore, newPlayer.highmove, newPlayer.duration, newPlayer.totalwin, newPlayer.totallose);
            added = 1;
        }
        // Salin data lama
        fprintf(tempFile, "%s %d %d %d %d %d\n", temp.username, temp.highscore, temp.highmove, temp.duration, temp.totalwin, temp.totallose);
    }

    // Jika data baru belum ditambahkan (karena highscore paling kecil), tambahkan di akhir
    if (!added) {
        fprintf(tempFile, "%s %d %d %d %d %d\n", newPlayer.username, newPlayer.highscore, newPlayer.highmove, newPlayer.duration, newPlayer.totalwin, newPlayer.totallose);
    }

    fclose(file);
    fclose(tempFile);

    // Ganti file asli dengan file sementara
    remove(filename);
    rename("temp.txt", filename);
}