// #include "modules/Halaman_Lobby/Halaman_Lobby.h"
// #include "modules/Halaman_Tutorial/HowToPlay.h"
// #include "modules/Gameplay/Gameplay.h"
// #include "modules/Board/Board.h"
// #include "modules/File/File.h"

//Sopian menambahkan program main untuk bagian input username.
// selain itu juga merapihkan beberaopa bagian program yang kurang baik

int main()
{
	//************* Deklarasi Kamus Data ************//
	FILE *file;
	Player username[1];				//struct Player
	int key, option;				//Kunci untuk opsi yang dipilih
	char input_user;				//variable untuk menampung input user	
	int selectedarrow = 0;			//Bagian text yang ditunjukan panah dan pudar
	int done = 0;					//kunci untuk selesai atau belumnya program
	int i;
	int result;						//variable sementara untuk hasil pengeecekan void
	char input_name[9];				//Nama yang diinput player
	char temp_text[50];				//text temporer untuk menyimpan sementara stirng yang di copy
	Tile tiles[4][4];				//Array dua dimensi sebagai letak posisi angka-angka pada saat game berjalan
	//Kamus data Bingkai
	int left_border;	//posisi x untuk border kiri
	int right_border; 	//posisi x untuk border kanan
	int top_border;		//posisi y untuk border atas
	int bottom_border; 	//posisi y untuk border bawah

	int score = 0;       // score yang disimpan dalam database
	int total_move = 0;	 // total move yang disimpan dalam database
	
	////////////////////////////////////////////////
	// ******* inisiasi array dan halaman ******* //
	////////////////////////////////////////////////

	for (i=0 ; i<=sizeof(input_name) ; i++){
		input_name[0] = ' ';
	}
	
	while(done == 0){
		
		/////////////////////////////////////////
		// ******** Halaman Lobby Awal ********//
		/////////////////////////////////////////
		
		lobby_screen(selectedarrow);		//menampilkan halaman lobby awal
		
		key = getch();						// mendapatkan Input
		
		if (key == 0 || key == 224) { 		// Deteksi tombol arrow pada keyboard
	        key = getch();
	        
	        play_sound(1);
	        
	        /*Kontrol atas dan bawah*/
	        if(key == UP_ARROW) {
				selectedarrow = (selectedarrow - 1 + 4) % 4; // ketikan menekan arrow atas
	        }else if (key == DOWN_ARROW) {
	            selectedarrow = (selectedarrow + 1) % 4; // ketika menekan arrow turun
	        }
	        
	    /*Memilih salah satu opsi*/
	    }else if (key == ENTER){
	    	system("cls");
	    	
	    	play_sound(2);			//membunyikan sound efek
	        
	        /*Opsi Play Game*/
	    	if(selectedarrow == 0){
               View_InputUserName();
			/*Opsi Highscore List*/
			}else if (selectedarrow == 1){
				printf_center("HIGHSCORE LIST",15);
	   				
	   				
				//done
				getchar();
				play_sound(2);
	   				
	   				
			/*Opsi How To Play*/
    		}else if (selectedarrow == 2){
    			printf_center("HOW TO PLAY", 15);
    			
				HowToPlay();
    			
    			//done
    			getchar();
    			play_sound(2);
    			
    			
    		/*Opsi Quit Game*/
    		}else if (selectedarrow == 3){
    			printf_center("Terimakasih Sudah Bermain", 15);
    			break;
    			done = 1;
    		}	
		}
	}
	return 0;
}