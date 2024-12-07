#include "View_InputUserName.h"


//nama author   : Muhamad Sopiana Argiansah
//nama file     : View_GamePlay.c
//deskripsi : 
/*file c yang berisi modul-modul untuk membuat halaman input username. 
memeriksa apakah terdapat player pada file data, dan membuat nama player baru
jika tidak ada*/


//**************//
/* program modul*/
//**************//


////////////////////////
//*** screen utama ***//
///////////////////////

//modul untuk melakukan itterasi halaman input user (halaman login) hingga user memilih enter atau esc.
void halaman_login(Player *player, int *nextkey)
{
/*parameter :
player : parameter input output (by adress) berisi struct player yang bermain saat ini
*nextkey : parameter input output (by adress) mengembalikan syarat program selesai atau kembali berulang*/

	//kamus data
	int is_repeat_program = 1;
	
	//memeriksa kondisi, itterasi berakhir atau tidak
	while (is_repeat_program == 1){
		input_user_screen(player, nextkey);		//## memanggil modul untuk user melakukan input
		if (*nextkey == 0 || *nextkey == 1){
			//kondnisi jika  user selesai melakukan input username atau memilih esc
			is_repeat_program = 0;
		}if (*nextkey == -1){
			//kondisi ketika user belum selesai melakukan input
			is_repeat_program = 1;
		}
	}

	return;
}

//modul untuk user melakukan input username dan dilakukan pemeriksaan
void input_user_screen(Player *player , int *nextkey)
{
/*parameter :
player : parameter input output (by adress) berisi struct player yang bermain saat ini
*nextkey : parameter input output (by adress) mengembalikan syarat program selesai atau kembali berulang*/

	/*** Kamus data ***/
	char input_name[10];
	int result;
	int i;
	
	/*** Inisiasi posisi birder ***/
	int left_border = (get_terminal_width('l') - 30) / 2;		//posisi x untuk border kiri
	int right_border = (get_terminal_width('l') + 30 - 2)/2;	//posisi x untuk border kanan
	int top_border = (get_terminal_width('t') - 7)/2; 			//posisi y untuk border atas
	int bottom_border = (get_terminal_width('t') + 7 - 2)/2;	//posisi y untuk border bawah
						
	//*** menampilkan halaman ***//
	input_username_border();						//## memanggil modul untuk menampilkan border input user
	
	//menampilkan teks "press to enter as a guest jika input kosong"
	printf_center("empty the input to play as a guest", bottom_border + 3);

	//menerima input dari user//	
	//berulang hingga user menekan enter atau esc						
	while (1){
		gotoxy(left_border + 5, top_border + 5);		//memposisikan pada bagian x y tempat karakter muncul
		username_input_check(input_name, &result);		//## memanggil modul untuk menginput dan memeriksa hasil inputan
		if (result == ESC){	
			//Jika menekan esc
			*nextkey = 0;
			break;							//key 0 artinya tidak akan masauk ke halaman game (kembali ke lobby)
		}else if (result == ENTER){
			//jika menekan ENTER
			*nextkey = 1;
			break;							//key 1 artinya masuk ke halaman game
		}
	}
	//jika mengisi karakter, akan di assign ke array input name di dalam modul diatas.

	gotoxy(1, bottom_border + 3);			//membersihkan bacaan pada bawah border
	printf("\033[K");						
	
	//jika nextkey 1 (username di input), maka memeriksa ada atau tidak nya usernma tersebut
	if (*nextkey == 1){
		username_found_result(player, input_name, nextkey);		//##memanggil modul untuk mencari username pada file data
	}

	play_sound(2);	//membunyikan sound efek
}

////////////////////////////
//*** modul pendukung ***//
////////////////////////////


//modul untuk membuat dan menampilkan border halaman pada halaman input username
void input_username_border()
{
	clearscreen(); //membersihkan layar
	
	//******* Deklarasi variable lokal ******//
	int i,j = 0; 				//i untuk itterasi sumbu y, dan j untuk itterasi sumbu x
	char temp_text [23];		//temporari variable untuk menaruh sementara string yang ingin di print
	
	//membuat posisi bingkai
	int left_border = (get_terminal_width('l') - 30 - 2) / 2;		//posisi x untuk border kiri
	int right_border = (get_terminal_width('l') + 30)/2;	//posisi x untuk border kanan
	int top_border = (get_terminal_width('t') - 7)/2; 			//posisi y untuk border atas
	int bottom_border = (get_terminal_width('t') + 7)/2;	//posisi y untuk border bawah
	
	//******* Program border ********//
	//membuat border horisontol dengan "===="
	for ( i = left_border; i <= right_border ; i++){
		gotoxy(i, top_border);
		printf("=");
		gotoxy(i, top_border + 2);
		printf("=");
		gotoxy(i, bottom_border);
		printf("=");
	}
	//membuat border vertikal dengan "|"
	for ( j = top_border; j <= bottom_border ; j++){
		gotoxy (left_border, j);
		printf("|");
		gotoxy(right_border, j);
		printf("|");
	}
	//header halaman
	printf_center("INPUT USERNAME", top_border + 1);
	
	//Text opsi pilihan
	printf("\033[48;5;255m\033[30m");	//memberikan style background pada text
	gotoxy(left_border - strlen("[press 'esc' to return]"), top_border - 1);
	printf("[press 'esc' to return]");
	printf("\033[0m");					//mengembalikan style text ke default

	
	//membuat patokan tempat karakter username berada dengan maksimal 10 karakter
	for ( i = left_border + 6; i < right_border-5; i += 2){
		gotoxy(i, top_border + 5);
		printf("_");	
	}
	
	//printf("\n\n%s", username.name);
	//getchar();
}

//modul untuk melakuakan input username, dan memeriksa input yang diberikan 
void username_input_check(char input_name[], int *result)
{
/*parameter :
input_name : parameter input output (by adress) berisi nama yang diinputkan oleh user.
*result : paramter output (by adress) berisi keluaran akhir yang ditekan (ESC atau ENTER)*/

	//******* Deklarasi Kamus Data ******//
	int space_indeks;
    int i = 0;
	char input;
	//******* Program Modul ******//
    printf("\033[?25h");		//ANSI untuk memunculkan posisi kursor
    
    while(1){					//itterasi menunggu input
    
		input = getch();	//mendapatkan input tanpa enter
		
		//jika input = backspace//
		if (input == BACKSPACE){		
			if (i == 0){			//jika semua karakter telah dihapus, backspace tidak terjadi
			}else if (i != 0){		//jika ada karakter sebelumnya, maka karakter tersebut akan dihapus
				input_name[i-1] = '\0';	//mengisi array yang dihapus dengan space
				printf("\033[2D");		//mengembalikan indeks ke beberapa kolom ke belakang dengan ASCII
				printf("_");
				printf("\033[1D");
				i--;
			}
		//jika input sudah mencapai batas 10 karakter//	
		} else if (i == 10 && input != ENTER){	
			
		//Jika input ENTER, maka selesai//	
		} else if (input == ENTER && input != ESC){
			//Jika enter diposisi awal
			if (i == 0){
				input_name[0] = ' ';			// mengisi array username dengan space
			}	
			*result = 13;			
			break;
			
		//Jika memilih ESC	
		}else if (input == ESC && input != ENTER){
			*result = 27;
			break;

		//menghalangi keluaran input tombol TAB DAN ARROW
		}else if (input == 0 || input == 224){
			input = getch();
			if (input == UP_ARROW || input == DOWN_ARROW || input == LEFT_ARROW || input == RIGHT_ARROW){
			}
		}else if (input == 9){
		}
		else{
			printf("%c ", input);	//meanmpilkan character yang baru ditekan ke layar
			input_name[i] = input;	//membasukan kedalam array untuk nantinya diparsing
			i++;			
		}
	}
	
	printf("\033[?25l");		//menghilangkan tapmilan posisi kursor
}

//modul untuk memeriksa apakah username yang diinput terdapat pada data file atau tidak
void username_found_result (Player *player, char input_name[], int *nextkey)
{
/*parameter :
player : paramter input output (by adress) berisi struct layer yang bermain saat ini
input_name : parameter input output (by adress) berisi nama yang diinputkan oleh user.
*nextkey : paramter input output (by adress) yang mengembalikan nilai apakah syarat lanjut ke game terpenuhi atau tidak*/

	//kamus data
	char temp_text[100];
	int option;
	int is_found;
	int i;

	/*** Inisiasi posisi border ***/
	int left_border = (get_terminal_width('l') - 30) / 2;		//posisi x untuk border kiri
	int right_border = (get_terminal_width('l') + 30 - 2)/2;	//posisi x untuk border kanan
	int top_border = (get_terminal_width('t') - 7)/2; 			//posisi y untuk border atas
	int bottom_border = (get_terminal_width('t') + 7 - 2)/2;	//posisi y untuk border bawah		
	
	/*** Memeriksa username terdaftar atau tidak ***/
	open_file_username(player, input_name, &is_found);			//## memanggil function open file untuk mencari username pada file Player_Score.txt
	
	if(is_found == 1) {
	//** kondisi jika terdaftar **/
		sprintf(temp_text, "[ Name : %s | Highscore : %d | Highmove : %d ]", player->username, player->highscore, player->highmove);
		printf_center ("username has been found", bottom_border + 2);
		printf_center (temp_text, bottom_border + 4);
		printf_center ("[press 'ENTER' to continue]", bottom_border + 6);

		option = getch();
		if (option == ENTER){
			//lanjut ke game bermain
			*nextkey = 1;
		}else{
			//itterasi input name diulangi
			*nextkey = -1;
		}
		

	}else if (is_found == 0 && input_name[0] != ' '){
	//** jika belum terdaftar **//
		//teks tampil
		printf_center ("couldn't find username!", bottom_border + 3);
		printf_center ("[press 'ENTER' to create new username]", bottom_border + 5);
		
		//*** Memilih ingin membuat baru username baru atau tidak ***//
		option = getch();

		//membersihkan teks yag berada dibawah border
		gotoxy(1, bottom_border + 3);
		printf("\033[K");
		gotoxy(1, bottom_border + 5);
		printf("\033[K");	

		/**** jika memilih ENTER ****/
		if (option == ENTER){
			//||| Open File untuk menyimpan data baru |||//
			add_newplayer_username(player, input_name);
			sprintf(temp_text, "username - %s - berhasil ditambahkan", player->username);
			printf_center(temp_text, bottom_border + 3);
			//|||||||||||||||||||||||||||||||||||||||||||//;
			*nextkey = 1;
			getch(); 			//button//
		}else{
			//jika memilih tombol lain, maka itterasi input username kembali diulang
			*nextkey = -1;	
		}
	
	//jika file tidak ditemukan
	}else if (is_found == -1){
		//kondisi jika file tidak ditemukan//
	}

	//*** kondisi jika menekan ENTER tanpa menginput apapun (bermain sebagai guest)***/
	if (input_name[0] == ' '){	
	//** jika memilih sebagai guest **//
		printf_center ("[press 'ENTER' to play as a guest]", bottom_border + 3);
		option = getch();

		//menekan enter
		if (option == ENTER){

			//syarat lanjut ke game bermain terpenuhi (tanpa username)
			*nextkey = 1;

			//mengosongkan username()
			player->username[0] = ' ';
			//bermain sebagai guest tanpa save data

		//selain enter
		}else{
			*nextkey = -1;					//mengulang kembali itterasi input username
			gotoxy(1, bottom_border + 3);		//mengapus text 'press enter to play as a guest
			printf("\033[K");	
		}
	}
}
