#include "Halaman_Lobby.h"
#include "../File/File.h"

#define UP_ARROW 72
#define DOWN_ARROW 80
#define ENTER 13


//Sopian menambahkan modul baru, 2 modul untuk halaman input user name, yaitu : input_username_screen & user_input_username

DWORD WINAPI beepThread(LPVOID sound){			//deklarasi Thread untuk suara Beep
	int type = (int)(intptr_t)sound;
	switch (type){
		case 1:
			Beep(400,300);
			return 0;
		case 2:
			Beep(600,300);
			return 0;
		case 3:
			Beep(1400,100);
			return 0;
	}
}

void play_sound(intptr_t type_sound){
	HANDLE soundthread;															//membuat variable untuk HANDLE
	soundthread = CreateThread(NULL,0, beepThread, (LPVOID)type_sound,0,NULL);	//memanggil thread
	CloseHandle(soundthread);													//menutup Handle
}

int get_middle_pos(char pos){
	if (pos == 'y'){	//jika memimnta midle pos y
		int posisi_y = get_terminal_width('t')/2;		
		return posisi_y;
	}else if (pos == 'x'){	//jika meminta middle pos x
		int posisi_x = get_terminal_width('l')/2;
		return posisi_x;		
	}
}

void printf_center (const char* text, int posisi_Y){
	int posisi_X = (get_terminal_width('l') - strlen(text)) / 2;	//posisi X tepat di tengah2 halaman
	gotoxy (posisi_X, posisi_Y);									//set cursor pada posisi x dan y
	printf("%s\n", text);											//printf teks pada posisi ditentukan
	//printf("%d ; %d", posisi_X, strlen(text));
}

void text_style(char text[], int style){
	int i;
	if (style == 1){
		while(_kbhit() == 0){						//selama tidak ada input keyboard
			printf("\033[2m%s", text);				//ANSI untuk text pudar
			printf("\033[%dD", strlen(text));		//ANSI mengembalikan posisi kursor ke awal kalimat
		}
	}
	printf("\033[0m");
}

void lobby_screen (int selectedarrow)
{
	system("cls"); //bersihkan layar
	printf("\033[?25l"); //menyembunyikan cursor
	
	//mendefinisikan posisi sisi-sisi border
	int left_border = (get_terminal_width('l') - 57 ) /2;
	int right_border = left_border + 57 - 1;
	int top_border = (get_terminal_width('t') - 19)/2;
	int bottom_border = top_border + 16;
		
	const char* menu[]={"START GAME","HIGHSCORE LIST","HOW TO PLAY ","EXIT"};  //Array yang berisi nama dari opsi pada halaman lobby
	int y_arrow[] = {top_border+6, top_border+8, top_border+10, top_border+12 }; //indeks posisi Y untuk setiap text opsi
	char newtext[20]; //array character untuk menyalin text yang ditunjuk panah
	int i; //indeks itterasi border
	int p; //indeks pilihan untuk arrow
	

	
	for (i = left_border; i<=left_border+57-1; i++){ //border bagian atas
		gotoxy(i,top_border);
		printf("*");
	}
	printf_center("*  ==================== 2048 GAME ====================  *", top_border+1); //header/judul
	for (i = left_border; i<=left_border+57-1; i++){ //border dibawah judul
		gotoxy(i,top_border + 2);
		printf("*");
	}
	for(i=top_border+3; i<=bottom_border-1; i++){ //border samping
		gotoxy(left_border,i);
		printf("|");
		gotoxy(right_border,i);
		printf("|");
	}
	
	printf_center(menu[0], y_arrow[0]); //START GAME
	printf_center(menu[1], y_arrow[1]); //PLAYER SCORE LIST
	printf_center(menu[2], y_arrow[2]); //HOW TO PLAY
	printf_center(menu[3], y_arrow[3]); //QUIT
	
	for(i=left_border;i<=left_border+57-1;i++){ //Border bawah
		gotoxy(i,bottom_border);
		printf("*");
	}
	for (p=0;p<=3;p++){ //mencari teks yang ditunjukan tanda panah
		if (p == selectedarrow){
			sprintf(newtext, "--> %s", menu[p]);  //memberi tanda panah ke teks yang dipilih
			gotoxy((get_terminal_width('l')-strlen(newtext))/2, y_arrow[p]); 
			text_style(newtext, 1); //membuat teks yang dipilih menjadi redup warnanya
		}
	}
}

void input_username_screen()
{
	system("cls"); //membersihkan layar
	
	//******* Deklarasi variable lokal ******//
	int i,j = 0; 				//i untuk itterasi sumbu y, dan j untuk itterasi sumbu x
	char temp_text [23];		//temporari variable untuk menaruh sementara string yang ingin di print
	
	//membuat posisi bingkai
	int left_border = (get_terminal_width('l') - 30) / 2;		//posisi x untuk border kiri
	int right_border = (get_terminal_width('l') + 30 - 2)/2;	//posisi x untuk border kanan
	int top_border = (get_terminal_width('t') - 7)/2; 			//posisi y untuk border atas
	int bottom_border = (get_terminal_width('t') + 7 - 2)/2;	//posisi y untuk border bawah

	//******* Program border ********//
	//membuat border horisontol dengan "===="
	for ( i = left_border; i < right_border ; i++){
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
	gotoxy(1, top_border);
	printf("[press 'esc' to return]");
	printf("\033[0m");					//mengembalikan style text ke default

	
	//membuat patokan tempat karakter username berada dengan maksimal 10 karakter
	for ( i = left_border + 5; i < right_border-4; i += 2){
		gotoxy(i, top_border + 4);
		printf("_");	
	}
	
	//printf("\n\n%s", username.name);
	//getchar();
}

void user_input_username(char username[])
{
	//******** Deklarasi Variable Lokal *********//
    int i = 0;
	
	//******* Program Modul ******//
    printf("\033[?25h");		//ANSI untuk memunculkan posisi kursor
    
    while(1){					//itterasi menunggu input
    
		char input = getch();	//mendapatkan input tanpa enter

		//jika input = backspace//
		if (input == 8){		
			if (i == 0){			//jika semua karakter telah dihapus, backspace tidak terjadi
			}else if (i != 0){		//jika ada karakter sebelumnya, maka karakter tersebut akan dihapus
				username[i-1] = '\0';	//mengisi array yang dihapus dengan NULL
				printf("\033[2D");		//mengembalikan indeks ke beberapa kolom ke belakang dengan ASCII
				printf("_");
				printf("\033[1D");
				i--;
			}
			
		//jika input sudah mencapai batas 10 karakter//	
		} else if (i == 10 && input != 13){	
			
		//Jika input ENTER, maka selesai//	
		} else if (input == 13){
			//Jika enter diposisi awal
			if (i == 0){
				username[0] = '\0';			// mengisi array username dengan NULL
			}				
			break;
			
		//menghindari menekan esc, arrow, dan tab	
		}else if (input == 0 || input == 224){
			input = getch();
			if (input == 72 || input == 80 || input == 75 || input == 77){
				continue;
			}
		}else if (input == 9 || input == 27){
		}
		else{
			printf("%c ", input);	//meanmpilkan character yang bAru ditekan ke layar
			username[i] = input;	//membasukan kedalam array untuk nantinya diparsing
			i++;			
		}
	}
	printf("\033[?25l");		//menghilangkan tapmilan posisi kursor
}




