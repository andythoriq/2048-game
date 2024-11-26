#include "modules/Halaman_Lobby/Halaman_Lobby.h"
#include "modules/Tile/Tile.h"
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
	Tile arr[4][4];
	HANDLE thread;
	
	generateTiles(arr);
	
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
					bool is_repeat_program = true;
				    char choice = 'w';
				
				    while (is_repeat_program) {
				
				        printBoard(arr);
				
				        printf("[tekan e untuk keluar]");
				        choice = getch();
				
				         system("cls");
				
				        if (choice == 'e') {
				            is_repeat_program = false;
				        } else {
				            move(choice, arr);
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