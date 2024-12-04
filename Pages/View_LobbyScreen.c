#include "View_LobbyScreen.h"

#include "../Utilities/Utilities.h"

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