<<<<<<< HEAD



// initialize
// ...




void View_GamePlay()
{
    char choice;

    // clear board

    // initialize board

    do {
        printBoard();
        choice = input_choice();
        moveBoard(choice, tiles, player);
    } while (choice != 'E' || choice != 'e' || choice != EXIT || choice != ESC) {
        printBoard();
        choice = input_choice();
        moveBoard(choice, tiles, player);
    }
    
=======
#include "View_GamePlay.h"
#include "../GamePlay/Movement.h"
#include "../GamePlay/WinOrLose.h"
#include "../Struct/Player.h"
#include "../Struct/Tile.h"
#include "../Utilities/Utilities.h"
#include "../Utilities/File.h"
#include "../GamePlay/Board.h"

void View_GamePlay(Tile tiles[4][4], Player *player)
{
    //***** Deklarasi Kamus data *****//
    bool is_repeat_program = true;
    int option; 
    bool game_finished = false;
    char choice = 'w';
    
    //***** Memulai Program *****//
    generateTiles(tiles);						//## memanggil modul untuk mengisi array dua dimensi
    
    //selama is_repeat_program == true, maka game berjalan
    while (is_repeat_program == true) {
        
        printBoard(tiles, player);						//## memanggil modul untuk membuat papan

        //Pilihan sesuai input keyboard//
        choice = getch();

        //jika memilih esc (EXIT GAME)
        if (choice == ESC) {					//opsi untuk mengakhiri game
        
            printf("\033[48;5;255m\033[30m");		//memberikan efek background
            //teks yang tampil
            printf_center("ARE YOU SURE WANT TO FINISH?", ((get_terminal_width('t') - 9)/2) + 3);
            printf_center("[press 'ENTER' to yes]", ((get_terminal_width('t') - 9)/2)+5);
            printf("\033[0m");						// mengembalikan setingan default teks
            
            choice = getch();				//memilih benar keluar atau tidak
            if ( choice == ENTER){			//jika menekan enter
                is_repeat_program = false;	//repitisi diakhiri	
                update_player(player);
                createPlayer(player, "", 0, 0, 0, 0, "00:00", 0, 0);
                resetTiles(tiles); 			// reset tiles, jadi kondisi semula
            }else{
                is_repeat_program = true;	//repetisi diulangi						
            }								
        
        //jika memilih selain e (CONTINUE PLAYING)
        } else {
            move(choice, tiles, &*player);				//## memanggil modul untuk menggerakan papan (GAME LOGIC UTAMA)
            game_result(tiles, &*player, &game_finished);										//## memanggil modul game result
            if (game_finished == true) {
                printf("do you want to play again?");
                printf("press [ENTER] to play again");
                printf("press [ESC] to exit the game");
                option = getch();
                if (option == ENTER) {
                    generateTiles(tiles);
                    printf("%s %d %d", player->username, player->highscore, player->highmove);
                    update_player(player);
                    createPlayer(player, getUsername(player), getHighscore(player), getHighmove(player), 0, 0, "00:00", getTotalWin(player), getTotalLose(player));
                    is_repeat_program = true;
                } else if (option == ESC) {
                    update_player(player);
                    createPlayer(player, "", 0, 0, 0, 0, "00:00", 0, 0);
                    is_repeat_program = false;
                }
            }
            game_finished = false;
            play_sound(3);											//Membunyikan suara
        }

        //membersihkan layar//
        clearscreen();
        //kembali keatas......
    }
    //Jika memilih EXIT GAME//
    play_sound(2);
    resetTiles(tiles);						//## memanggil modul untuk mereset board game seperti semula
>>>>>>> ganti-player-menjadi-array
    return;
} 