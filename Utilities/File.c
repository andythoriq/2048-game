#include "file.h"

//menambahkan manipulasi file yang sudah direncanakan
//Sopian menambahkan : modul open file

// Fungsi untuk membaca/mencari data berdasarkan username
void open_file_username(Player *player, char targetUsername[10], int *is_found) 
{
    FILE *file;
    char name[10] = "", record [50] = "";
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
            fscanf(file, "%s %d %d %d %d", name, &highscore, &highmove, &totalwin, &totallose);
            
            createPlayer(player, name, highscore, highmove, 0, 0, totalwin, totallose);

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
}

void add_newplayer_username (Player *player, char targetUsername[]) 
{
    FILE *file; 

    file = fopen ("Player_Score.txt", "a+");

    if (file == NULL){
        printf ("Error opening file!");
        return;
    }
    
    createPlayer(player, targetUsername, 0, 0, 0, 0, 0, 0);

    fprintf (file, "%s %d %d %d %d\n", getUsername(player), getHighscore(player), getHighmove(player), getTotalWin(player), getTotalLose(player));
    fclose(file);
}

void update_player(Player *player)
{
    FILE *file;
    FILE *tempfile;
    char record [50] = "", nama_yg_dicari[10] = "";
    char name[10];
    int highscore, highmove, totalwin, totallose;

    file = fopen("Player_Score.txt", "r+");  
    tempfile = fopen("temp_filedata.txt", "a+");

    if (file == NULL || tempfile == NULL) {
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
            fprintf(tempfile, "%s %d %d %d %d\n", getUsername(player), getHighscore(player), getHighmove(player), getTotalWin(player), getTotalLose(player));
        }else if (strcmp(nama_yg_dicari, getUsername(player)) != 0) {
            fprintf(tempfile,"%s", record);
        }
    }
    
    fclose(file);
    fclose(tempfile);
    empty_file ("Player_Score.txt");

    //mengisi nilai temp file ke file Player_Score.txt
    file = fopen("Player_Score.txt","a");
    tempfile = fopen("temp_filedata.txt","r");
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
    empty_file ("temp_filedata.txt");
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

//Fungsi untuk menambahkan data baru dan menjaga agar file tetap terurut
void sort_file_playerscore() 
{
    FILE *file;
    Player player[50];
    Player key;
    char record [50];
    int i, j, datacount;

    file = fopen("Player_Score.txt", "r");

    if (file == NULL) {
        printf("error opening file!");
        return;
    }
    i = 0;
    fseek(file, 0, SEEK_SET);
    fscanf(file, "%s %d %d %d %d", player[i].username, &player[i].highscore, &player[i].highmove, &player[i].totalwin, &player[i].totallose);
    fseek(file, 0, SEEK_SET);
    while (!feof(file)) {
        fscanf(file, "%s %d %d %d %d", player[i].username, &player[i].highscore, &player[i].highmove, &player[i].totalwin, &player[i].totallose);
        i++;
    }
    datacount = i - 1;

    for (i = 1; i < datacount; i++){
        key = player[i];
        j = i - 1;

        while (j>=0 && player[j].highscore < key.highscore){
            player[j+1] = player[j];
            j--;
        }
        player[j+1] = key;
    }

    fclose(file);
    empty_file("Player_Score.txt");

    //mengisi nilai temp file ke file Player_Score.txt
    file = fopen("Player_Score.txt","a");

    fseek(file, 0, SEEK_SET);
    for (i=0 ; i<datacount; i++) {
        fprintf(file, "%s %d %d %d %d\n",  player[i].username, player[i].highscore, player[i].highmove, player[i].totalwin, player[i].totallose);
    }
    fclose(file);
}

void save_playerprogress(Tile tiles[4][4], char username[])
{
    FILE *file;
    FILE *tempfile;
    int i,j, is_found = 0;
    char name[10], record[50];

    file = fopen("Tiles_Safe_data.txt", "r+");  
    tempfile = fopen("temp_filedata.txt", "a+");

    if (file == NULL || tempfile == NULL) {
        printf("error opening file!");
        return;
    }
    // Cari username di dalam file
    fseek (file, 0, SEEK_SET);
    while (fgets(record, sizeof(record), file) != NULL) {
        sscanf(record,"%s ", name);   
        if (strcmp(name, username) == 0) {
            // Jika username ditemukan
            is_found = 1;
            fseek (tempfile, -1, SEEK_CUR);
            fprintf(tempfile, "%s ", username);
            for (i=0;i<4;i++){
                for (j=0;j<4;j++){
                    fprintf(tempfile, "%d ", tiles[i][j].value);
                }
            }
            fprintf(tempfile, "\n");
        }else if (strcmp(name, username) != 0) {
            fprintf(tempfile,"%s", record);
        }
    }
    if (is_found == 0){
        fseek (tempfile, -1, SEEK_CUR);
        fprintf(tempfile, "%s ", username);
        for (i=0;i<4;i++){
            for (j=0;j<4;j++){
               fprintf(tempfile, "%d ", tiles[i][j].value);
            }
        }
        fprintf(tempfile, "\n");
    }
    
    fclose(file);
    fclose(tempfile);
    empty_file ("Tiles_Safe_data.txt");

    //mengisi nilai temp file ke file Player_Score.txt
    file = fopen("Tiles_Safe_data.txt","a");
    tempfile = fopen("temp_filedata.txt","r");
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
    empty_file ("temp_filedata.txt");
}

void open_save_progress (Tile tiles[4][4], char username[], int *is_save)
{
    FILE *file;
    FILE *tempfile;
    int i,j, is_found = 0;
    char name[10], record[50];
    int temp;

    int found = 0;

    file = fopen("Tiles_Safe_data.txt", "a+");  
    if (file == NULL) {
        printf("error opening file!");
        return;
    }
    // Cari username di dalam file
    fseek (file, 0, SEEK_SET);
    while (fgets(record, sizeof(record), file)) {
        sscanf(record,"%s", name);     
        if (strcmp(name, username) == 0) {
            // Jika username ditemukan
            fseek (file, -strlen(record)-1, SEEK_CUR);
            fscanf(file, "%s", name);
            for (i=0;i<4;i++){
                for (j=0;j<4;j++){
                    fscanf(file, "%d ", &temp);
                    setValueAndColor(&tiles[i][j], temp);
                }
            }
            found = 1;
            *is_save = 1;
            break;
        }
    }
    
    fclose(file);
    if (found == 0){
        // Jika username tidak ditemukan, buat data baru
        *is_save = 0;
    }    
}



