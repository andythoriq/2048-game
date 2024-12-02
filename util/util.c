#include "util.h"

// void gotoxy(int x, int y) {
//     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//     COORD pos = { .X = x, .Y = y };
//     SetConsoleCursorPosition(hConsole, pos);
// }

// int get_terminal_width(char width) {
//     CONSOLE_SCREEN_BUFFER_INFO csbi;
//     int ukuran = 80; // Default ukuran jika gagal
//     if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
//         if (width == 'l') {
//             ukuran = csbi.srWindow.Right - csbi.srWindow.Left + 1;
//         } else if (width == 't') {
//             ukuran = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
//         }
//     }
//     return ukuran;
// }

void gotoxy (int x, int y){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}

int get_terminal_width(char width){ //t = tinggi, l = lebar
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (width == 'l'){
    	int lebar;
	    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
	        lebar = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	    } else {
	        lebar = 80; // Default jika gagal
	    }
	    return lebar;
	}else if (width == 't'){
		int tinggi;
		if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
	    	tinggi = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	    } else {
	        tinggi = 80; // Default jika gagal
	    }
	    return tinggi;
	}
}