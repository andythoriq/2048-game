#include "file.h"

//menambahkan manipulasi file yang sudah direncanakan
//Sopian menambahkan : modul open file

// Fungsi untuk membaca/mencari data berdasarkan username
void open_file_username(Player *player, const char *targetUsername, int *is_found) 
{
    FILE *file;
    Player temp; 

    file = fopen("Player_Score.txt", "a+");
    if (file == NULL) {
        printf("error opening file!");
        *is_found = -1;
        return;
    }

    // Cari username di dalam file
    while (fscanf(file, "%s %d %d %d %d %d", temp.username, &temp.highscore, &temp.highmove, &temp.duration, &temp.totalwin, &temp.totallose) != EOF) {
        if (strcmp(temp.username, targetUsername) == 0) {
            // Jika username ditemukan
            // *player = temp; // Salin data ke output parameter
            setUsername(player, temp.username);
            setHighscore(player, temp.highscore);
            setHighmove(player, temp.highmove);
            setDuration(player, temp.duration);
            setTotalWin(player, temp.totalwin);
            setTotalLose(player, temp.totallose);
            *is_found = 1;
            break;
        }
    }
    rewind(file);
    fclose(file);

    if (!*is_found) {
        // Jika username tidak ditemukan, buat data baru
        *is_found = 0;
    }
}

void add_newplayer_username (Player *player, const char *targetUsername) 
{
    FILE *file; 

    file = fopen ("Player_Score.txt", "a+");

    if (file == NULL){
        printf ("Error opening file!");
        return;
    }

    // strcpy(player->username, *targetUsername);
    // player->highscore = 0;
    // player->highmove = 0;
    // player->duration = 0;
    // player->totalwin = 0;
    // player->totallose = 0; 
    setUsername(player, targetUsername);
    setHighscore(player, 0);
    setHighmove(player, 0);
    setDuration(player, 0);
    setTotalWin(player, 0);
    setTotalLose(player, 0);

    sort_file_playerscore(*player) ;
}

// Fungsi untuk menambahkan data baru dan menjaga agar file tetap terurut
void sort_file_playerscore(Player newPlayer) 
{
    FILE *file = fopen("Player_Score.txt", "a+");
    FILE *tempFile = fopen("tempFile.txt", "w");
    Player temp;
    int added = 0;

    if (file == NULL || tempFile == NULL) {
        printf("error opening file!");
        return;
    }

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
    remove("Player_Score.txt");
    rename("tempFile.txt", "Player_Score.txt");
}