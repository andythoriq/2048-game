#include "file.h"

//menambahkan manipulasi file yang sudah direncanakan
//Sopian menambahkan : modul open file

int open_file (Player username[], char keyword[]) {
	
	//******** Deklarasi variable lokal ********//
    FILE *file;  		// Pointer ke file dengan variable file
    char line[23];  	// Array untuk menyimpan hasil bacaan setiap baris file
    char keyname[9];	// string sementara untuk menyimpan username untuk dibandingkan dengan keyword
    int found = 0;  	//kunci unutk ditemukan atau tidak keyword pada file
    
    //variable untuk menampung hasil fscanf
	char name[9];			
	int score, mnt, dtk;
	
	//******* program ******//
    // Membuka file "example.txt" untuk dibaca
    file = fopen("Player_Score.txt", "r+");

    // Memeriksa apakah file berhasil dibuka
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Membaca file baris per baris
    while (fgets(line, sizeof(line), file)) {
    	sscanf(line, "%s ", keyname);									//memeriksa username nya saja dan diassign ke keyname
        //Mencari apakah keyword ada di dalam baris
        if (strcmp(keyname, keyword) == 0) {
        	fseek(file, -strlen(line), SEEK_CUR);						//mengembalikan posisi pointer pada file ke sebelah kiri baris
            fscanf (file, "%s %d %d:%d", name, &score, &mnt, &dtk);		//melakukan scan file dan memasukannya ke variable lokal
            
            //Assignment data ke Struct Player
            strcpy (username[0].name,name);
            username[0].highsocre = score;
            sprintf(username[0].duration, "%d:%d", mnt, dtk);
			
			//Kunci ditemukan
			found = 1;	
			return 1;	//ditemukan
		}
	}
    //Jika keyword username tidak ditemukan
    if (!found) {
    	return 0;		//tidak ditemukan
    }

    // Menutup file setelah selesai
    rewind(file);
    fclose(file);
}

//void create_username ();


