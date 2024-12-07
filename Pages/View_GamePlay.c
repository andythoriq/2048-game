#include "View_GamePlay.h"
#include "../GamePlay/Movement.h"
#include "../GamePlay/WinOrLose.h"
#include "../Struct/Player.h"
#include "../Struct/Tile.h"
#include "../Utilities/Utilities.h"
#include "../Utilities/File.h"
#include "../GamePlay/Board.h"

//nama author   : Muhamad Sopiana Argiansah, Andy Thoriq, Nauval Khairiyan
//nama file     : View_GamePlay.c
//deskripsi : 
/*file c yang berisi modul-modul pada halalman game berlangsung, seperti menampilkan board,
logika game, game result, dll.*/


//**************//
/* program modul*/
//**************//

//modul yang berisi modul-modul lain untuk membuat halaman saat game dimulai secara keseluruhan
void View_GamePlay(Tile tiles[4][4], Player *player)
{
/*parameter :
tiles : parameter input output (by adress) berisi angka pada board
player  : parameter input output (by adress) berisi struct player (pemain saat ini)*/

    //***** Deklarasi Kamus data *****//
    bool is_repeat_program = true;
    int option, is_saved; 
    int p, selectedarrow;
    bool game_finished = false, escinput = false;
    char choice = 'w';
    char blankname[10] = "";

    //***** Memulai Program *****//

    //* memeriksa apakah terdapat save data progress tiles *//
    open_save_progress (tiles, player->username, &is_saved);        //## memanggil modul untuk memriksa apakah ada save progress 

    //jika tidak ada save data progress tiles
    if (is_saved == 0){
        generateTiles(tiles);				//## memanggil modul untuk mengisi array dua dimensi
    }
    printBoard(tiles, player);				//## memanggil modul untuk membuat papan

    //*************************************************//
    // Itterasi game hingga is_repeat_ program = false //
    //*************************************************//
    while (is_repeat_program == true) {

        //Pilihan sesuai input keyboard//
        choice = getch();

        //****************************//
        //Program Sesuai Pilihan input//
        //****************************//

        //*** jika memilih esc (EXIT GAME) ***//

        if (choice == ESC) {					//opsi untuk mengakhiri game
        
            printf("\033[48;5;255m\033[30m");		//memberikan efek background
            //teks yang tampil
            printf_center("ARE YOU SURE WANT TO FINISH?", ((get_terminal_width('t') - 9)/2) + 3);
            printf_center("[press 'ENTER' to yes]", ((get_terminal_width('t') - 9)/2)+5);
            printf("\033[0m");						// mengembalikan setingan default teks
            
            //press ENTER untuk leave / ESC to cancel//
            choice = getch();				
            if ( choice == ENTER){			
                play_sound(2);
                update_player(player);
                is_repeat_program = false;	//repitisi diakhiri
                escinput = true;            //masuk ke opsi pilihan save data/tidak
            }else{
                is_repeat_program = true;	//repetisi diulangi						
            }								
        
        //*** jika memilih tombol  [r / R] (Reset GAME) ***//
        } else if ( choice == 'r' || choice == 'R'){
            resetTiles(tiles);
            generateTiles(tiles);

            // reset current move dan current score
            setScore(player, 0);
            setMove(player, 0);

            play_sound(2);
            is_repeat_program = true;

        //*** jika memilih tombol lain W A S D (MOVE GAME) ***//  
        }else if (choice == 'w' || 'a' || 's' || 'd' || 'W' || 'A' || 'S' || 'D' ){
            move(choice, tiles, &*player);				//## memanggil modul untuk menggerakan papan (GAME LOGIC UTAMA)
            play_sound(3);
            printBoard(tiles, player);
            

            //** Memeriksa apakah gameover atau tidak **//
            printf("\033[48;5;250m\033[30m");		//memberikan efek background
            game_result(tiles, &*player, &game_finished);	//## memanggil modul game result
            printf("\033[0m");						// mengembalikan setingan default teks
            
            //*Jika GameOver *//
            if (game_finished == true) {
                printf_center("do you want to play again?", ((get_terminal_width('t') - 9)/2) + 10);
                printf_center("press [ENTER] to play again", ((get_terminal_width('t') - 9)/2) + 12);
                printf_center("press [ESC] to exit the game", ((get_terminal_width('t') - 9)/2) + 13);
                //Press Enter untuk contunue playing / ESC untuk kembali ke lobby//

                while(1){
                    option = getch();
                    if (option == ENTER) {      //jika memilih ENTER
                        generateTiles(tiles);                               //generate tiles baru
                        save_playerprogress(tiles, getUsername(player));    //save player progress dibuat 0
                        update_player(player);                              //mengubah file save player highscore
                        createPlayer(player, getUsername(player), getHighscore(player), getHighmove(player), 0, 0, getTotalWin(player), getTotalLose(player));
                        
                        //mengulang kembali permainan
                        is_repeat_program = true;       //repetisi diulangi
                        break;
                    } else if (option == ESC) {
                        generateTiles(tiles);                               //generate tiles baru
                        save_playerprogress(tiles, getUsername(player));    //save player progress dibuat 0                        
                        update_player(player);                      //mengubah save player highscore pada file
                        createPlayer(player, blankname, 0, 0, 0, 0, 0, 0); //mengosongkan kembali struct player

                        //tidak mengulang kembali, dan kembali ke lobby
                        is_repeat_program = false;  //repetisi diakhiri
                        break;
                    }else{
                        //tidak menerima input selain ESC atau ENTER
                    } 
                }
                game_finished = false;      //mengembalikan syarat game finished ke false
            }
        }

        //membersihkan layar//
        clearscreen();
        //membuat board dengan angka baru
        printBoard(tiles, player);				//## memanggil modul untuk membuat papan
        //kembali keatas......
    }

    //*** Save Progress***/
    //masuk jika kelaur game menggunakan ESC buka karena game_over
    if (escinput == true && player->username[0] != ' ' ) {
        clearscreen();
        printf_center("do you want to save the progress?", get_terminal_width('t')/2);
        printf_center("press [ENTER] to save data", (get_terminal_width('t') + 2)/2);
        printf_center("press [ESC] to skip", (get_terminal_width('t') + 4)/2);
        printf_center("press [R] to reset progress", (get_terminal_width('t') + 6)/2);

        while(1){
            option = getch();
            //memilih ENTER untuk save progress
            if (option == ENTER) {
                save_playerprogress(tiles, getUsername(player));
                break;
            //memilih ESC untuk tidak save dan tidak mengubah save terakhir
            } else if (option == ESC) {
                resetTiles(tiles); 			// reset tiles, jadi kondisi semula
                break;
            //memilih R untuk mereset save data
            }else if (option == 'r' || option == 'R'){
                resetTiles(tiles);
                generateTiles(tiles);
                save_playerprogress(tiles, getUsername(player));
                break;
            }else{
            }
        }
    }
    //Jika memilih EXIT GAME//
    resetTiles(tiles);						        //## memanggil modul untuk mereset board game seperti semula
    createPlayer(player, blankname, 0, 0, 0, 0, 0, 0);
    return;
} 