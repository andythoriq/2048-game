#include "file.h"


//nama author   : Muhamad Sopiana Argiansah
//nama file     : File.c
//deskripsi : 
/*file c yang berisi modul-modul yang berhubungan dengan save data
dan manipulasi file */


// modul untuk membaca/mencari data berdasarkan username
void open_file_username(Player *player, char targetUsername[10], int *is_found) 
{
    /* parameter :
    player : parameter input output (by adress) yang berisi struct player saat ini
    targetusername : parameter input output (by adress) yang berisi username yang diinput username
    *is_found : parameter input output (by adress) yang mengembalikan nilai ditemukan atau tidaknya username pada file
    */

   //kamus data
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

//modul untuk menambahkan data baru kedalam file
void add_newplayer_username (Player *player, char targetUsername[]) 
{
    /* parameter :
    player : parameter input output (by adress) yang berisi struct player saat ini
    targetusername : parameter input output (by adress) yang berisi username yang diinput username
    */

    FILE *file; 

    file = fopen ("Player_Score.txt", "a+");

    if (file == NULL){
        printf ("Error opening file!");
        return;
    }
    
    //Mengisi struct player dengan kosong dan username sesuai input
    createPlayer(player, targetUsername, 0, 0, 0, 0, 0, 0);

    fprintf (file, "%s %d %d %d %d\n", getUsername(player), getHighscore(player), getHighmove(player), getTotalWin(player), getTotalLose(player));
    fclose(file);
}

//modul untuk mengupdate data pada file tiap kali selesai bermain
void update_player(Player *player)
{
/*parameter :
player : parameter input output (by adress) yang berisi struct player yang bermain saat ini
        untuk mengambil nama dari player tersebut*/

    //kamus data
    FILE *file;
    FILE *tempfile;
    char record [50] = "", nama_yg_dicari[10] = "";
    char name[10];
    int highscore, highmove, totalwin, totallose;

    //program
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
            //mengisi data username yang dicari ke tempfile dengan data baru
            fprintf(tempfile, "%s %d %d %d %d\n", getUsername(player), getHighscore(player), getHighmove(player), getTotalWin(player), getTotalLose(player));
        
        //mengisi data sisanya ke dalam temp file
        }else if (strcmp(nama_yg_dicari, getUsername(player)) != 0) {
            fprintf(tempfile,"%s", record);
        }
    }
    
    fclose(file);
    fclose(tempfile);
    //menghapus seluruh data pada file player score
    empty_file ("Player_Score.txt");

    //mengisi nilai temp file ke file Player_Score.txt
    file = fopen("Player_Score.txt","a");
    tempfile = fopen("temp_filedata.txt","r");
    if (file == NULL || tempfile == 0) {
        printf("error opening file!");
        return;
    }

    //mengcopy semua data pada tempfile ke file player score
    fseek (tempfile, 0, SEEK_SET);
    fseek (file, 0, SEEK_SET);
    while (fgets(record, sizeof(record), tempfile) != NULL) {   
        fprintf(file, "%s", record);
    }
    

    fclose(file);
    fclose(tempfile);

    //mengosongkan tempfile
    empty_file ("temp_filedata.txt");
}



//modul untuk mengurutkan data yang ada di dalam file
void sort_file_playerscore() 
{
    //data file
    FILE *file;
    Player player[50];
    Player key;
    char record [50];
    int i, j, datacount;

    //programm
    file = fopen("Player_Score.txt", "r");

    if (file == NULL) {
        printf("error opening file!");
        return;
    }

    //mengscanf (read) semmua data pada file palyer score
    //lalu dimasukan ke dalam struct sementara
    i = 0;
    fseek(file, 0, SEEK_SET);
    fscanf(file, "%s %d %d %d %d", player[i].username, &player[i].highscore, &player[i].highmove, &player[i].totalwin, &player[i].totallose);
    fseek(file, 0, SEEK_SET);
    while (!feof(file)) {
        fscanf(file, "%s %d %d %d %d", player[i].username, &player[i].highscore, &player[i].highmove, &player[i].totalwin, &player[i].totallose);
        i++;
    }
    //menghitung ada berapa data yang terbaca
    datacount = i - 1;

    //melakukan sorting data secara insertion
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
    //mengosongkan file player score
    empty_file("Player_Score.txt");

    //mengisi nilai temp file ke file Player_Score.txt
    file = fopen("Player_Score.txt","a");

    //mengcopy semua data pada array struct player ke dalam file data
    fseek(file, 0, SEEK_SET);
    for (i=0 ; i<datacount; i++) {
        fprintf(file, "%s %d %d %d %d\n",  player[i].username, player[i].highscore, player[i].highmove, player[i].totalwin, player[i].totallose);
    }
    fclose(file);
}

//modul untuk menyimpan progress bermain username yang di panggil
void save_playerprogress(Tile tiles[4][4], char username[])
{
/*parameter :
tiles : parameter input output (by adress) yang berisi struct tile (angka) pada board bermain
username : parameter input yang berisi username player, digunakan untuk keyword ketika mencari username pada file*/
    
    
    //kamus data
    FILE *file;
    FILE *tempfile;
    int i,j, is_found = 0;
    char name[10], record[50];

    //pprogram modul
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

        //membandingkan keyword dengan username yang dibaca
        if (strcmp(name, username) == 0) {
            // Jika username ditemukan
            is_found = 1;
            //mengisis data tiles terbaru ke dalam tempfile
            fseek (tempfile, -1, SEEK_CUR);
            //mengwrite username terbke dalam tempfile
            fprintf(tempfile, "%s ", username);
            for (i=0;i<4;i++){
                for (j=0;j<4;j++){
                    //mengwrite semua data array tiles ke dalam temp file
                    fprintf(tempfile, "%d ", tiles[i][j].value);
                }
            }
            fprintf(tempfile, "\n");
        //jika bukan keyword yang dicari, maka akan mengwrite semua data pada file ke tempfile
        }else if (strcmp(name, username) != 0) {
            fprintf(tempfile,"%s", record);
        }
    }

    //jika keyword tidak ditemukan sama seklai
    if (is_found == 0){

        //mengisi data tiles terbaru ke dalam tempfile
        fseek (tempfile, -1, SEEK_CUR);
        //mengwrite username ke dalam temp file
        fprintf(tempfile, "%s ", username);
        for (i=0;i<4;i++){
            for (j=0;j<4;j++){
                //mengwrite semua data array tiles ke dalam tempfile
               fprintf(tempfile, "%d ", tiles[i][j].value);
            }
        }
        fprintf(tempfile, "\n");
    }
    
    fclose(file);
    fclose(tempfile);
    //mengosongkan isi file tiles_safe_data
    empty_file ("Tiles_Safe_data.txt");

    //mengisi nilai temp file ke file Player_Score.txt
    file = fopen("Tiles_Safe_data.txt","a");
    tempfile = fopen("temp_filedata.txt","r");
    if (file == NULL || tempfile == 0) {
        printf("error opening file!");
        return;
    }

    //mengcopy isi pada temp file ke file, sehingga dat username yang dicari tergantikan
    fseek (tempfile, 0, SEEK_SET);
    fseek (file, 0, SEEK_SET);
    while (fgets(record, sizeof(record), tempfile) != NULL) {   
        fprintf(file, "%s", record);
    }
    
    fclose(file);
    fclose(tempfile);
    //mengosongkan isi temmpfile
    empty_file ("temp_filedata.txt");
}


//modul untuk membuka dan mencari data pada tiles_safe_data sesuai keyword yang dicari
void open_save_progress (Tile tiles[4][4], char username[], int *is_save)
{
    //kamus data
    FILE *file;
    FILE *tempfile;
    int i,j, is_found = 0;
    char name[10], record[50];
    int temp;

    int found = 0;


    //programm
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
            //mengscan (read) username pada baris saat ini dari dalam file
            fscanf(file, "%s", name);
            //mengscan(read) data array tiles tiap indeks pada file
            for (i=0;i<4;i++){
                for (j=0;j<4;j++){
                    fscanf(file, "%d ", &temp);
                    //mengisi data yang terbaca pada file ke array tiles sesaui indeks saat ini
                    setValueAndColor(&tiles[i][j], temp);
                }
            }
            //kunci found dinyalakan sebagai tanda file sudah ditemukan
            found = 1;
            //kunci is_save dikembalikan ke modul pemanggil sebagai tanda bahawa ada save data yang ditemukan
            *is_save = 1;
            break;
        }
    }
    
    fclose(file);

    //jika tidak ada save tiles pada file yang ditemukan
    if (found == 0){
        // Jika username tidak ditemukan, tanda bahwa tidak ada save data akan dikembalikan ke modul oemnaggil
        *is_save = 0;
    }    
}

//Modul untuk mengosongkan seluruh isi pada file
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

