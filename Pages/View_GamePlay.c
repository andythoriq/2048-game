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
    int option, is_saved; 
    int p, selectedarrow;
    bool game_finished = false, escinput = false;
    char choice = 'w';
    

    //***** Memulai Program *****//
    open_save_progress (tiles, player->username, &is_saved);
    if (is_saved == 0){
        generateTiles(tiles);						//## memanggil modul untuk mengisi array dua dimensi
    }
    printBoard(tiles, player);					//## memanggil modul untuk membuat papan
    game_finished = false;
    //selama is_repeat_program == true, maka game berjalan
    while (is_repeat_program == true) {

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
                play_sound(2);
                update_player(player);
                is_repeat_program = false;	//repitisi diakhiri
                escinput = true;
            }else{
                is_repeat_program = true;	//repetisi diulangi						
            }								
        
        //jika memilih selain e (CONTINUE PLAYING)
        } else {
            move(choice, tiles, &*player);				//## memanggil modul untuk menggerakan papan (GAME LOGIC UTAMA)
            play_sound(3);
            printBoard(tiles, player);
            
            printf("\033[48;5;250m\033[30m");		//memberikan efek background
            game_result(tiles, &*player, &game_finished);										//## memanggil modul game result
            printf("\033[0m");						// mengembalikan setingan default teks
            
            if (game_finished == true) {
                printf_center("do you want to play again?", ((get_terminal_width('t') - 9)/2) + 10);
                printf_center("press [ENTER] to play again", ((get_terminal_width('t') - 9)/2) + 12);
                printf_center("press [ESC] to exit the game", ((get_terminal_width('t') - 9)/2) + 13);
 
                while(1){
                    option = getch();
                    if (option == ENTER) {
                        generateTiles(tiles);
                        save_playerprogress(tiles, getUsername(player)); 
                        update_player(player);
                        createPlayer(player, getUsername(player), getHighscore(player), getHighmove(player), 0, 0, "00:00", getTotalWin(player), getTotalLose(player));
                        //mengulang kembali permainan
                        is_repeat_program = true;
                        break;
                    } else if (option == ESC) {
                        update_player(player);
                        createPlayer(player, "", 0, 0, 0, 0, "00:00", 0, 0);
                        //tidak mengulang kembali, dan kembali ke lobby
                        is_repeat_program = false;
                        break;
                    }else{
                    } 
                }
                game_finished = false;
            }
        }

        //membersihkan layar//
        clearscreen();
        //membuat board dengan angka baru
        printBoard(tiles, player);				//## memanggil modul untuk membuat papan
        //kembali keatas......
    }
    if (escinput == true && player->username != "" ) {
        clearscreen();
        printf_center("do you want to save the progress?", get_terminal_width('t')/2);
        printf_center("press [ENTER] to save data", (get_terminal_width('t') + 2)/2);
        printf_center("press [ESC] to skip", (get_terminal_width('t') + 4)/2);

        while(1){
            option = getch();
            if (option == ENTER) {
                save_playerprogress(tiles, getUsername(player));
                break;
            } else if (option == ESC) {
                resetTiles(tiles); 			// reset tiles, jadi kondisi semula
                break;
            }else{
            }
        }
    }
    //Jika memilih EXIT GAME//
    resetTiles(tiles);						        //## memanggil modul untuk mereset board game seperti semula
    createPlayer(player, "", 0, 0, 0, 0, "00:00", 0, 0);
    return;
} 