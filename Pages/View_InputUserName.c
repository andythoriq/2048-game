#include "View_InputUserName.h"

//*** screen utama ***//
void halaman_login(Player *player, int *nextkey)
{
	int is_repeat_program = 1;
	
	while (is_repeat_program == 1){
		input_user_screen(&*player, &*nextkey);
		if (*nextkey == 0 || *nextkey == 1){
			is_repeat_program = 0;
		}if (*nextkey == -1){
			is_repeat_program = 1;
		}
	}
}

void input_user_screen(Player *player , int *nextkey)
{
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
	input_username_border();								//## memanggil modul untuk menampilkan halaman input user
	
	//menampilkan teks "press to enter as a guest jika input kosong"
	printf_center("empty the input to play as a guest", bottom_border + 3);

	//menerima input dari user//							

	while (1){
		gotoxy(left_border + 5, top_border + 5);		//memposisikan pada bagian x y tempat karakter muncul
		username_input_check(input_name, &result);		//## memanggil modul untuk menginput dan memeriksa hasil inputan
		if (result == 27){	
			*nextkey = 0;
			break;							//key 0 artinya tidak akan masauk ke halaman game
		}else if (result == 13){
			*nextkey = 1;
			break;
		}
	}
	//jika mengisi karakter, akan di assign ke array input name di dalam modul diatas.

	gotoxy(1, bottom_border + 3);			//membersihkan bacaan pada bawah border
	printf("\033[K");						
	
	if (*nextkey == 1){
		username_found_result(&*player, input_name, &*nextkey);
	}

	play_sound(2);	//membunyikan sound efek
}

//*** modul pendukung ***//
void input_username_border()
{
	system("cls"); //membersihkan layar
	
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

void username_input_check(char input_name[], int *result)
{
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
				input_name[i-1] = ' ';	//mengisi array yang dihapus dengan space
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

void username_found_result (Player *player, char input_name[], int *nextkey)
{
	char temp_text[60];
	int option;
	int is_found;

	/*** Inisiasi posisi birder ***/
	int left_border = (get_terminal_width('l') - 30) / 2;		//posisi x untuk border kiri
	int right_border = (get_terminal_width('l') + 30 - 2)/2;	//posisi x untuk border kanan
	int top_border = (get_terminal_width('t') - 7)/2; 			//posisi y untuk border atas
	int bottom_border = (get_terminal_width('t') + 7 - 2)/2;	//posisi y untuk border bawah
						
	
	/*** Memeriksa username terdaftar atau tidak ***/
	open_file_username(&*player, input_name, &is_found);			//## memanggil function open file untuk mencari username pada file Player_Score.txt
	
	if(is_found == 1) {
	//** kondisi jika terdaftar **/
		sprintf(temp_text, "[ Name : %s | Highscore : %d | duration : %s ]", getUsername(player), getHighscore(player), getConvertetDuration(player));
		printf_center ("username has been found", bottom_border + 2);
		printf_center (temp_text, bottom_border + 4);
		//done
		*nextkey = 1;
		getch();

	}else if (is_found == 0 && input_name[0] != ' '){
	//** jika belum terdaftar **//
		//teks tampil
		printf_center ("couldn't find username!", bottom_border + 3);
		printf_center ("[press 'ENTER' to create new username]", bottom_border + 5);
		
		//*** Memilih ingin membuat baru username baru atau tidak ***//
		option = getch();
		/**** jika memilih ENTER ****/
		if (option == ENTER){
			//||| Open File untuk menyimpan data baru |||//
			add_newplayer_username(&*player, input_name);
			//|||||||||||||||||||||||||||||||||||||||||||//;
			*nextkey = 1;
	
		}else{
			gotoxy(1, bottom_border + 2);	//membersihkan bacaan teks
			printf("\033[K");
			gotoxy(1, bottom_border + 4);
			printf("\033[K");	
			
			*nextkey = -1;	
		
		}
	}else if (is_found == -1){
		//kondisi jika file tidak ditemukan//
	}
	if (input_name[0] == ' '){	
	//** jika memilih sebagai guest **//
		printf_center ("[press 'ENTER' to play as a guest]", bottom_border + 3);
		option = getch();
		if (option == 13){
			*nextkey = 1;
			//bermain sebagai guest tanpa save data
		}else{
			*nextkey = -1;
			gotoxy(1, bottom_border + 3);				//mengapus text 'press enter to play as a guest
			printf("\033[K");	
		}
	}
}
