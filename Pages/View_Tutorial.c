#include <stdio.h>
#include <string.h>

#include "../Utilities/Utilities.h"

#include "View_Tutorial.h"

void View_Tutorial() 
{
	int i; //deklarasi index
	int x_pos = (get_terminal_width('l') - 90)/2;
	int y_pos = (get_terminal_width('t') - 16)/2; 

	for (i = x_pos; i <= x_pos + 90; i++) { // Membuat Bingkai Atas dan bawah
		gotoxy(i, y_pos);
		printf("=");
		gotoxy(i, y_pos + 16 + 1);
		printf("=");
	}
	printf("\n");

	for (i = y_pos + 1; i <= y_pos + 16 - 1; i++) { // Membuat Bingkai kiri dan kanan
		gotoxy(x_pos, i);
		printf("*");
		gotoxy(x_pos + 90, i);
		printf("*");
	}
	
	const char* text[] = {	
	"                     ",
	"HOW TO PLAY GAME 2048",
	"                     ",
	"1. Geser ubin ke atas, bawah, kiri, atau kanan menggunakan panah (keyboard/sentuhan).",
	"2. Ubin dengan angka yang sama akan bergabung saat bertemu akan menghasilkan         ", 
    "   nilai totalnya (contoh: 2 + 2 = 4).                                               ",
	"3. Setiap geseran menambahkan ubin baru bernilai 2 atau 4 secara acak di papan       ",
	"4. Hindari pengisian penuh papan agar tetap memiliki ruang untuk ubin baru.          ",
	"   Fokuslah pada kombinasi ubin besar.                                               ",
	"5. Permainan berakhir jika papan penuh dan tidak ada gerakan yang memungkinkan       ",
	"6. Jika berhasil membuat ubin dengan nilai 2048, Anda memenangkan permainan          ",
	"7. Pilih main lagi atau restart jika ingin mengulang permainan dari awal             ",
	"                                                                                     ",
	"                                                                                     ",
	"                                                                                     "
	};
	
	for (i = 1; i < 15; i++) { // Mencetak Teks dalam bingkai
		gotoxy((get_terminal_width('l') - strlen(text[i]))/2, y_pos+i+2);
		printf("%s", text[i]);
	}	
	printf("\n");
	
	printf_center ("[press 'ENTER' to return]", y_pos + 16 + 3 );

	if ( getch() == ENTER){
		play_sound(2);
		return;
	}else{
	}
}
