#include "file.h"

//menambahkan manipulasi file yang sudah direncanakan
//Sopian menambahkan : modul open file

// Fungsi untuk membaca/mencari data berdasarkan username
void open_file_username(Player *player, char targetUsername[10], int *is_found) 
{
    FILE *file;
    char name[10] = "", record [50] = "", duration[6] = "";
    int highscore, highmove, totalwin, totallose;
    int found = 0;

    file = fopen("Player_Score.txt", "a+");  
    if (file == NULL) {
        printf("error opening file!");
        *is_found = -1;
        return;
    }
    // Cari username di dalam file
    fseek (file, 0, SEEK_SET);
    while (fgets(record, sizeof(record), file)) {
        sscanf(record,"%s", name);     
        if (strcmp(name, targetUsername) == 0) {
            // Jika username ditemukan
            fseek (file, -strlen(record)-1, SEEK_CUR);
            fscanf(file, "%s %d %d %s %d %d", name, &highscore, &highmove, duration, &totalwin, &totallose);
            
            createPlayer(player, name, highscore, highmove, 0, 0, duration, totalwin, totallose);

            *is_found = 1;
            found = 1;
            break;
        }
    }
    
    fclose(file);
    if (found == 0){
        // Jika username tidak ditemukan, buat data baru
        *is_found = 0;
    }
    printf("is found = %d", *is_found);
}

void add_newplayer_username (Player *player, char targetUsername[]) 
{
    FILE *file; 

    file = fopen ("Player_Score.txt", "a+");

    if (file == NULL){
        printf ("Error opening file!");
        return;
    }
    
    createPlayer(player, targetUsername, 0, 0, 0, 0, "00:00", 0, 0);

    printf("p test 2");
    fprintf (file, "%s %d %d %s %d %d\n", getUsername(player), getHighscore(player), getHighmove(player), getDuration(player), getTotalWin(player), getTotalLose(player));
    printf("p test 2");
    fclose(file);
}

void update_player(Player *player)
{
    FILE *file;
    FILE *tempfile;
    char record [50] = "", nama_yg_dicari[10] = "";
    char duration[6], name[10];
    int highscore, highmove, totalwin, totallose;

    file = fopen("Player_Score.txt", "r+");  
    tempfile = fopen("temp_Player_Score.txt", "a+");

    if (file == NULL || tempfile == 0) {
        printf("error opening file!");
        return;
    }
    // Cari username di dalam file
    fseek (file, 0, SEEK_SET);
    while (fgets(record, sizeof(record), file) != NULL) {
        sscanf(record,"%s", nama_yg_dicari);     
        if (strcmp(nama_yg_dicari, getUsername(player)) == 0) {
            // Jika username ditemukan
            fseek (tempfile, -1, SEEK_CUR);
            fprintf(tempfile, "%s %d %d %s %d %d\n", getUsername(player), getHighscore(player), getHighmove(player), getDuration(player), getTotalWin(player), getTotalLose(player));
        }else if (strcmp(nama_yg_dicari, getUsername(player)) != 0) {
            fprintf(tempfile,"%s", record);
        }
    }
    
    fclose(file);
    fclose(tempfile);
    empty_file ("Player_Score.txt");

    file = fopen("Player_Score.txt","a");
    tempfile = fopen("temp_Player_Score.txt","r");
    if (file == NULL || tempfile == 0) {
        printf("error opening file!");
        return;
    }
    fseek (tempfile, 0, SEEK_SET);
    fseek (file, 0, SEEK_SET);
    while (fgets(record, sizeof(record), tempfile) != NULL) {   
        fprintf(file, "%s", record);
    }
    

    fclose(file);
    fclose(tempfile);
    empty_file ("temp_Player_Score.txt");

}

void empty_file (char * filename)
{
    FILE *file;

    file = fopen(filename, "w");
    if (file == 0){
        printf("error opening file!");
        return;
    }
    fputs("", file);
    fclose(file);
}

// Fungsi untuk menambahkan data baru dan menjaga agar file tetap terurut
// void sort_file_playerscore() 
// {
//     FILE *file = fopen("Player_Score.txt", "a+");
//     FILE *tempFile = fopen("tempFile.txt", "w");
//     Player temp;
//     int added = 0;

//     if (file == NULL || tempFile == NULL) {
//         printf("error opening file!");
//         return;
//     }

//     // Salin data lama ke file sementara, sambil menambahkan data baru secara terurut
//     while (fscanf(file, "%s %d %d %d %d %d", temp.username, &temp.highscore, &temp.highmove, &temp.duration, &temp.totalwin, &temp.totallose) != EOF) {
//         if (!added && newPlayer.highscore > temp.highscore) {
//             // Tambahkan data baru jika highscore lebih besar
//             fprintf(tempFile, "%s %d %d %d %d %d\n", newPlayer.username, newPlayer.highscore, newPlayer.highmove, newPlayer.duration, newPlayer.totalwin, newPlayer.totallose);
//             added = 1;
//         }
//         // Salin data lama
//         fprintf(tempFile, "%s %d %d %d %d %d\n", temp.username, temp.highscore, temp.highmove, temp.duration, temp.totalwin, temp.totallose);
//     }

//     // Jika data baru belum ditambahkan (karena highscore paling kecil), tambahkan di akhir
//     if (!added) {
//         fprintf(tempFile, "%s %d %d %d %d %d\n", newPlayer.username, newPlayer.highscore, newPlayer.highmove, newPlayer.duration, newPlayer.totalwin, newPlayer.totallose);
//     }

//     fclose(file);
//     fclose(tempFile);

//     // Ganti file asli dengan file sementara
//     remove("Player_Score.txt");
//     rename("tempFile.txt", "Player_Score.txt");
// }