#include "modules/Halaman_Lobby/Halaman_Lobby.h"
#include "modules/Gameplay/Gameplay.h"
#include "modules/Board/Board.h"

DWORD WINAPI beepThread(LPVOID param){
	intptr_t sound = (intptr_t)param;
	switch (sound){
		case 1:
			Beep(400,300);
			return 0;
		case 2:
			Beep(600,300);
			return 0;
	}
}


int main()
{
	int key;
	int selectedarrow = 0; //pertama-tama menunjuk opsi Start Game
	int done = 0;
	char choice = 'w';
	bool is_repeat_program = true;
	Tile tiles[4][4];
	HANDLE thread;
	
	
	while(done == 0){
		lobby_screen(selectedarrow);
		key = getch();
		
		if (key == 0 || key == 224) { // Deteksi tombol arrow pada keyboard
	        key = getch();
	        
	        thread = CreateThread(NULL,0, beepThread, (LPVOID)1,0,NULL);
	        CloseHandle(thread);
	        
	        if(key == UP_ARROW) {
				selectedarrow = (selectedarrow - 1 + 4) % 4; // ketikan menekan arrow atas
	        }else if (key == DOWN_ARROW) {
	            selectedarrow = (selectedarrow + 1) % 4; // ketika menekan arrow turun
	        }
	    }else if (key == ENTER){
	    	system("cls");
	    	
	    	thread = CreateThread(NULL,0, beepThread, (LPVOID)2,0,NULL);
	        CloseHandle(thread);
	        
	    	if(selectedarrow == 0){
	    			//
	    			input_username();
	    			
	    			thread = CreateThread(NULL,0, beepThread, (LPVOID)2,0,NULL);
	        		CloseHandle(thread);
	    			
					//*************//

					generateTiles(tiles);
				
				    while (is_repeat_program) {
				
				        printBoard(tiles);
				
				        printf("[tekan e untuk keluar]");
				        choice = getch();
				
				         system("cls");
				
				        if (choice == 'e') {
				            is_repeat_program = false;
							resetTiles(tiles);
				        } else {
				            move(choice, tiles);
				        }
				        //***********//
				    }
				    //set value array 0 (ngosongin array lagi
	   			}else if (selectedarrow == 1){
	   				printf_center("HIGHSCORE LIST",15);
	   				getchar();
    			}else if (selectedarrow == 2){
    				printf_center("HOW TO PLAY", 15);
    				getchar();
    			}else if (selectedarrow == 3){
    				printf_center("Terimakasih Sudah Bermain", 15);
    				break;
    				done = 1;
    			}	
		}
	}
	return 0;
}