#include "Utilities.h"


//nama author   : Muhamad Sopiana Argiansah
//nama file     : Utilities.c
//deskripsi : 
/*file c yang berisi modul-modul untuk keperluan tampilan
dan banyak dipanggil di halaman lain */


//modul untuk membersihka layar pada terminal
void clearscreen ()
{
	printf("\033[3J");
	printf("\033[2J");
	printf("\033[3J");
	printf("\033[H");
	
	fflush(stdout);
}

//modul uutuk mengaktifkan bunyi beep pada thread lain
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
			Beep(1100,100);
			return 0;
	}
	fflush(stdout);
}

//modul untuk memnaggil thread untuk membunyikan beep
void play_sound(intptr_t type_sound){
	HANDLE soundthread;	
	DWORD threadID1;														//membuat variable untuk HANDLE
	soundthread = CreateThread(NULL,0, beepThread, (LPVOID)type_sound,0,&threadID1);	//memanggil thread
	fflush(stdout);
	CloseHandle(soundthread);       // Menutup handle
}

//modul untuk memindahkan kursor ke posisi x, y tertentu
void gotoxy (int x, int y){
	printf("\033[%d;%dH", y, x);		//ANSI untuk memposisikan kursor pada posisi x dan y terntentu
}

//modul untuk memperoleh ukuran terminal saat ini
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

//modul untuk memperoleh posisi x/y pas ditengah2 teminal
int get_middle_pos(char pos){
	if (pos == 'y'){	//jika memimnta midle pos y
		int posisi_y = get_terminal_width('t')/2;		
		return posisi_y;
	}else if (pos == 'x'){	//jika meminta middle pos x
		int posisi_x = get_terminal_width('l')/2;
		return posisi_x;		
	}
}

//modul untuk memprint text tepat dibagian tengah(x) halaman
void printf_center (const char* text, int posisi_Y){
	int posisi_X = (get_terminal_width('l') - strlen(text)) / 2;	//posisi X tepat di tengah2 halaman
	gotoxy (posisi_X, posisi_Y);									//set cursor pada posisi x dan y
	printf("%s\n", text);											//printf teks pada posisi ditentukan
	//printf("%d ; %d", posisi_X, strlen(text));
}

//modul untuk mengubah style pada text 
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

//modul untuk memperoleh input user pada saat selectedkey di lobby
void selectedarrow_text (int *selectedarrow, int *key){
	
	*key = getch();
	if (*key == 0 || *key == 224) { 		// Deteksi tombol arrow pada keyboard
	    *key = getch();
	       
	    play_sound(1);
	        
	    /*Kontrol atas dan bawah*/
	    if(*key == UP_ARROW || *key == RIGHT_ARROW) {
			*selectedarrow = (*selectedarrow - 1 + 4) % 4; // ketikan menekan arrow atas
	    }else if (*key == DOWN_ARROW || *key == LEFT_ARROW) {
	        *selectedarrow = (*selectedarrow + 1) % 4; // ketika menekan arrow turun
	    }
	}
}