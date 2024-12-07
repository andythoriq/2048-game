#ifndef INPUT_USER_NAME_H
#define INPUT_USER_NAME_H

#include <stdbool.h>
#include "../Struct/Player.h"
#include "../Utilities/Utilities.h"
#include "../Utilities/File.h"

//nama author   : Muhamad Sopiana Argiansah
//nama file     : View_GamePlay.c
//deskripsi : 
/*file c yang berisi modul-modul untuk membuat halaman input username. 
memeriksa apakah terdapat player pada file data, dan membuat nama player baru
jika tidak ada*/

//*** screen utama ***//

//modul untuk melakukan itterasi halaman input user (halaman login) hingga user memilih enter atau esc.
void halaman_login(Player *player, int *nextkey);

//modul untuk user melakukan input username dan dilakukan pemeriksaan
void input_user_screen (Player *player, int *nextkey);


////////////////////////////
//*** modul pendukung ***//
////////////////////////////


//modul untuk membuat dan menampilkan border halaman pada halaman input username
void input_username_border();

//modul untuk melakuakan input username, dan memeriksa input yang diberikan 
void username_input_check(char input_name[], int *result);

//modul untuk memeriksa apakah username yang diinput terdapat pada data file atau tidak
void username_found_result (Player *player, char input_name[], int *nextkey);

#endif