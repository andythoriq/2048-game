#include "modules/Halaman_Lobby/Halaman_Lobby.h"
#include "modules/Halaman_Tutorial/HowToPlay.h"
#include "modules/Gameplay/Gameplay.h"
#include "modules/Board/Board.h"
#include "modules/File/File.h"

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

	generateTiles(tiles);
	
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

	    		/////////////////////////////////////////////////
	    		//******** Awal Halaman Input Username ********//
	    		/////////////////////////////////////////////////
	    	
				//*** memulai program ***//
				key = 1;
				while (key == 1){
	    			//inisiasi posisi border
		    		left_border = (get_terminal_width('l') - 30) / 2;		//posisi x untuk border kiri
					right_border = (get_terminal_width('l') + 30 - 2)/2;	//posisi x untuk border kanan
					top_border = (get_terminal_width('t') - 7)/2; 			//posisi y untuk border atas
					bottom_border = (get_terminal_width('t') + 7 - 2)/2;	//posisi y untuk border bawah
										
					//*** menampilkan halaman ***//
	    			input_username_screen();						//## memanggil modul untuk menampilakna halaman input user
					
					//menampilkan teks press to enter as a guest jika input kosong
					printf_center("empty the input to play as a guest", bottom_border + 2);

					//menerima input dari user//
					i = 0;	
					result = -1;												//indeks untuk posisi character pada array nama yang diinpnut
					while (1){
						gotoxy(left_border + 5 + 2*i, top_border + 4);			//memposisikan pada bagian x y tempat karakter muncu
						input_user = getch();	//mendapatkan input tanpa enter
						username_input_check(input_name, input_user, &i, &result);		//## memanggil modul input_user_name

						if (result == ESC){
							key = 0;    //Key 0 untuk keluar dari loop input user dan kembali ke lobby
							break;
						}else if (result == ENTER){
							key = 1;	//key 1 untuk selesai input dan lanjut ke game
							break;
						}
						result = -1;
					}
					//mengisi struct name dengan array
					for (i = 0; i <=9 ; i++){
						strcpy(username[0].name,input_name);
					}
					//mengisi sisa array dengan space kosong
					for (i ; i <= 9 ; i++){
						username[0].name[i] = ' ';
					}

					gotoxy(1, bottom_border + 2);
					printf("\033[K");						
					
					if (key == 1){
						/*** Memeriksa username terdaftar atau tidak ***/
						int is_found = open_file(username, input_name);		//memanggil modul open file untuk mencari username pada file Player_Score.txt
							
						//** kondisi jika terdaftar **/
						if (is_found == 1){
							sprintf(temp_text, "[ Name : %s | Highscore : %d | duration : %s ]", username[0].name, username[0].highsocre, username[0].duration);
							printf_center ("username has been found", bottom_border + 2);
							printf_center (temp_text, bottom_border + 4);
							//done
							getchar();
							break;
							
						//** jika belum terdaftar **//
						}else if (is_found == 0 && input_name[0] != ' '){
							//teks tampil
							printf_center ("couldn't find username!", bottom_border + 2);
							printf_center ("[press 'ENTER' to create new username]", bottom_border + 4);
							
							//memilih//
							option = getch();
							/**** jika memilih ENTER ****/
							if (option == ENTER){
								
								//||| Open File untuk menyimpan data baru |||//
								file = fopen("Player_score.txt","a+");
								fprintf (file, "%s %d %s\n", input_name, 0, "00:00");
								rewind(file);
								fclose(file);
								//|||||||||||||||||||||||||||||||||||||||||||//;
								break;
								
							}else{
								gotoxy(1, bottom_border + 2);
								printf("\033[K");
								gotoxy(1, bottom_border + 4);
								printf("\033[K");							
							}
							//balik keatas
						
						//** jika memilih sebagai guest **//
						}
						if (input_name[0] == ' '){
							printf_center ("[press 'ENTER' to play as a guest]", bottom_border + 2);
							option = getch();
							if (option == 13){
								break;
								//bermain sebagai guest tanpa save data
							}
							gotoxy(1, bottom_border + 2);
							printf("\033[K");
							gotoxy(1, bottom_border + 4);
							printf("\033[K");	
						}
					}
					else if (key == 0){
						//keluar loop input dan kembali ke lobby utama
						break;
					}
					//kembali keatas...

					play_sound(2);	//membunyikan sound efek
	   			
					//mengosongkan array input_name
					for (i = 0; i<sizeof(input_name); i++){
						input_name[i] = ' ';
					}
				}
	   			//--------------------------------------------------//
			    //*********** Akhir Halaman input Username *********//
			    //--------------------------------------------------//
	    			
				///////////////////////////////////////////////
	    		//******** Awal Halaman Bermain Game ********//
	    		///////////////////////////////////////////////
	    		if (key == 1){
					//***** Deklarasi Kamus data *****//
					bool is_repeat_program = true;
					char choice = 'w';
					
					//***** Memulai Program *****//
					generateTiles(tiles);						//## memanggil modul untuk mengisi array dua dimensi
					
					//selama is_repeat_program == true, maka game berjalan
					while (is_repeat_program) {
						
						printBoard(tiles, score, total_move);						//## memanggil modul untuk membuat papan
			        	printf("[press 'e' to finish the Game]");
						
						//Pilihan sesuai input keyboard//
						choice = getch();
						//jika memilih e (EXIT GAME)
						if (choice == 'e' || choice == 'E') {					//opsi untuk mengakhiri game
							is_repeat_program = false;							//repitisi diakhiri
							resetTiles(tiles); 									// reset tiles, jadi kondisi semula

							printf("\033[48;5;255m\033[30m");		//memberikan efek background
							//teks yang tampil
							printf_center("ARE YOU SURE WANT TO FINISH?", ((get_terminal_width('t') - 9)/2) + 3);
							printf_center("[press 'e' to cancel]", ((get_terminal_width('t') - 9)/2)+5);
							
							printf("\033[0m");						// mengembalikan setingan default teks
							
							choice = getch();			//memilih benar keluar atau tidak
							if ( choice == 'e'){			//jika menekan e
								is_repeat_program = true;	//repetisi diulangi
							}
						//jika memilih selain e (CONTINUE PLAYING)
						} else {
							move(choice, tiles, &score, &total_move);				//## memanggil modul untuk menggerakan papan (GAME LOGIC UTAMA)
							game_result(tiles);// game result
							play_sound(3);	//Membunyikan suara
						}
						//membersihkan layar//
						system("cls");
						//kembali keatas......
					}
					//Jika memilih EXIT GAME//
					play_sound(2);
					resetTiles(tiles);						//## memanggil modul untuk mereset board game seperti semula
					
					//----------------------------------------------//
					//*********** akhir Halaman Game Utama *********//
					//----------------------------------------------//
				}else if (key == 0){
					//tidak mengrun halaman game, lalu kembali ke lobby
				}

				key = 0;
				// kembali ke halaman lobby
			
			/////////////////////////////////////////////////////////
			// ********** AKHIR HALAMAN ENTER START GAME **********//
			/////////////////////////////////////////////////////////

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