
#include "Utilities/everything.h"

//nama author   : Muhamad Sopiana Argiansah, Andy Thoriq, dan Nauval Khaiy=riyan
//nama file     : main.c
//deskripsi : 
/*file c utama yang berisi modul utama tempat program berjalan.
memanggil semua modul yang sudah disiapkan sehingga membentuk program yang padu*/

int main()
{
	//Kamus data
	Player player;
	char username[10] = "";
	Tile tiles[4][4];
	int done = 0, nextkey = 0, key, selectedarrow = 0;

	//mengasign struct player saat ni dengan kosong
	createPlayer(&player, username, 0,0,0,0,0,0);
	// generateTiles(tiles);

	//selama Done 0, itterasi halaman lobby utama akan terus muncul
	while (done == 0){

		lobby_screen(selectedarrow);	//## memanggil modul untuk menampilkan halaman lobby

		//input user sesuai arrow (UP atau DOWN , Right atau Left)
		selectedarrow_text(&selectedarrow, &key);		//## memanggil modul untuk menunjukan mana opsi yang ditunjukan anak panah

		//jika menekan enter, maka memilih opsi yang ditunjukan panah
		if(key == ENTER){
			//membersihkan layar
			clearscreen ();
			
			//membunyikan suara
			play_sound(2);

			//memeriksa kondisi
			switch (selectedarrow){
				case 0:
					//jika menunjuk opsi halaman_login
					halaman_login(&player, &nextkey);

					//jika syarat nextkey terpenuhi, maka lanjut ke game dimulai
					if (nextkey == 1){
						/*game mulai*/
						View_GamePlay(tiles, &player);
					}
					break;
				case 1:
					//jika memilih opsi Highscore List
					View_LeaderBoard();
					break;
				case 2:
					//Jika memilih opsi How To Play
					View_Tutorial();
					break;
				case 3:

					// Jika memilih opsi EXIT
					printf_center("Terimakasih Sudah Bermain", 15);
					done = 1;
					break;
			}
		}
	}

	//game berakhir
	return 0;
}