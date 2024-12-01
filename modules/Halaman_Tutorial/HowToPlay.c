#include "HowToPlay.h"

// TODO: jadikan gotoxy kedalam saty modul yang sama
void gotoxy(int x, int y) { //Mendapatkan koordinat x dan y 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x; 
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}

int get_terminal_width(char width) { //t = tinggi, l = lebar
    CONSOLE_SCREEN_BUFFER_INFO csbi; // Mencari lebar dan tinggi terminal
    int tinggi;
    if (width == 'l') {
    	int lebar;
	    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
	        lebar = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	    } else {
	        lebar = 80; // Default jika gagal
	    }
	    return lebar;
	} else if (width == 't') {
		if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
	    	tinggi = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	    } else {
	        tinggi = 80; // Default jika gagal
	    }
		return (tinggi);
	}
}

void HowToPlay() {
	
	// Mengetahui Lebar dan Tinggi Terminal
	//int lebar = get_terminal_width('l'); 
	//int tinggi = get_terminal_width('t');
	//printf("%d, %d", lebar, tinggi);
	//printf("\n\n"); 
	
	int i; //deklarasi index
	int x_pos = (get_terminal_width('l') - 90)/2;
	for (i = x_pos; i <= x_pos + 90; i++) { // Membuat Bingkai Atas 
		gotoxy(i, 0);
		printf("*");
	}
	printf("\n");
	
	int y_pos = (get_terminal_width('t') - 16)/2; 
	for (i = y_pos; i <= y_pos + 16; i++) { // Membuat Bingkai Kiri
		gotoxy(15, i-7);
		printf("*");
	}
	for (i = y_pos; i <= y_pos + 16; i++) { // Membuat Bingkai Kanan
		gotoxy(105, i-7);
		printf("*");
	}
	
	for (i = x_pos; i <= x_pos + 90; i++) { // Membuat Bingkai Bawah
		gotoxy(i, 16);
		printf("*");
	}
	printf("\n");
	
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
	
	for (i = 0; i < 15; i++) { // Mencetak Teks dalam bingkai
		gotoxy((get_terminal_width('l') - strlen(text[i]))/2, i+1);
		printf("%s", text[i]);
	}	
	printf("\n");
	return 0;
}