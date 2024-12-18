#ifndef File_H
#define File_H

#include "Utilities.h"
#include "../Struct/Player.h"
#include "../Struct/Tile.h"

//nama author   : Muhamad Sopiana Argiansah
//nama file     : File.c
//deskripsi : 
/*file c yang berisi modul-modul yang berhubungan dengan save data
dan manipulasi file */


// modul untuk membaca/mencari data berdasarkan username
void open_file_username(Player *player, char targetUsername [], int *is_found);

//modul untuk menambahkan data baru kedalam file
void add_newplayer_username (Player *player, char targetUsername []);

//modul untuk mengupdate data pada file tiap kali selesai bermain
void update_player(Player *player);

//modul untuk mengurutkan data yang ada di dalam file
void sort_file_playerscore() ;

//modul untuk menyimpan progress bermain username yang di panggil
void save_playerprogress(Tile tiles[4][4], char username[]);

void open_save_progress (Tile tiles[4][4], char username[], int *is_save);

//modul untuk mengosongkan seluruh isi data pad afile yang dipanggil
void empty_file (char * filename);

#endif
