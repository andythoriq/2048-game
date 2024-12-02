#include "Halaman_Lobby.h"

#define UP_ARROW 72
#define DOWN_ARROW 80
#define ENTER 13

int get_middle_pos(char pos){
	if (pos == 'y'){
		int posisi_y = get_terminal_width('t')/2;
		return posisi_y;
	}else if (pos == 'x'){
		int posisi_x = get_terminal_width('l')/2;
		return posisi_x;		
	}
}



void printf_center (const char* text, int posisi_Y){
	int posisi_X = (get_terminal_width('l') - strlen(text)) / 2;
	gotoxy (posisi_X, posisi_Y);
	printf("%s\n", text);
	//printf("%d ; %d", posisi_X, strlen(text));
}

void shade_animation(char text[]){
	while(kbhit() == 0){
		printf("\033[2m%s", text);
		printf("\033[%dD", strlen(text));
	}
	printf("\033[%0m]");
}

void lobby_screen (int selectedarrow)
{
	system("cls"); //bersihkan layar
	printf("\033[?25l"); //menyembunyikan cursor
	
	const char* menu[]={"START GAME","HIGHSCORE LIST","HOW TO PLAY ","EXIT"};  //Array yang berisi nama dari opsi pada halaman lobby
	int y_arrow[] = {11,13,15,17}; //indeks posisi Y untuk setiap text opsi
	char newtext[20]; //array character untuk menyalin text yang ditunjuk panah
	int i; //indeks itterasi border
	int p; //indeks pilihan untuk arrow
	int left_border = (get_terminal_width('l') - 57 ) /2;
	int right_border = (get_terminal_width('l') + 57 - 2) /2;
	
	for (i = left_border; i<=left_border+57-1; i++){ //border bagian atas
		gotoxy(i,5);
		printf("*");
	}
	printf_center("*  ==================== 2048 GAME ====================  *", 6); //header/judul
	for (i = left_border; i<=left_border+57-1; i++){ //border dibawah judul
		gotoxy(i,7);
		printf("*");
	}
	for(i=8;i<=21;i++){ //border samping
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
		gotoxy(i,21);
		printf("*");
	}
	for (p=0;p<=3;p++){ //mencari teks yang ditunjukan tanda panah
		if (p == selectedarrow){
			sprintf(newtext, "--> %s", menu[p]);  //memberi tanda panah ke teks yang dipilih
			gotoxy((get_terminal_width('l')-strlen(newtext)-2)/2, y_arrow[p]); 
			shade_animation(newtext); //membuat teks yang dipilih menjadi redup warnanya
		}
	}
}

void input_username()
{
	system("cls");
	printf_center("INPUT USER NAME", get_middle_pos('y'));
	getchar();
}







