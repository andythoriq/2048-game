#include "View_LeaderBoard.h"

//nama author   : Muhamad Sopiana Argiansah
//nama file     : View_LeaderBoard.c
//deskripsi : 
/*file c yang berisi modul-modul untuk membuat dan menampilkan 
halaman leader Board*/


//**************//
/* program modul*/
//**************//

//modul utama untuk membuat halaman leadrboard secara keseluruhan
void View_LeaderBoard()
{

    //kamus data
    FILE *file;
    Player player[50];
    int i, datacount;
    
    // posisi border
    int left_border = ((get_terminal_width('l') - 103)/2);
	int right_border = left_border + 103;
	int top_border = ((get_terminal_width('t') - 26)/2);
	int bottom_border = top_border + 26;

    //membuat border leader board
    LeaderBoard_Border();           //## memanggil modul untuk membuat border leader board

    //melakukan sorting pada file supaya terbesar ke terkecil
    sort_file_playerscore();        //##meamnggil nodul ubtuk sorting data pada file

    //mengisi array dengan data  pada file data//
    file = fopen ("Player_Score.txt", "r");
    if (file == NULL){
        printf("error opening file!");
        return;
    }
    //melakukan scanf(read) pada file dan memasukannya ke variable
    i = 0;
    fseek(file, 0, SEEK_SET);
    fscanf(file, "%s %d %d %d %d", player[i].username, &player[i].highscore, &player[i].highmove, &player[i].totalwin, &player[i].totallose);
    fseek(file, 0, SEEK_SET);
    while (!feof(file)) {
        fscanf(file, "%s %d %d %d %d", player[i].username, &player[i].highscore, &player[i].highmove, &player[i].totalwin, &player[i].totallose);
        i++;
    }
    fclose(file);

    ///////// selesai mengisi array sesuai data file //////////////

    //menampilkan hasil pada leaderboard sesaui data pada file yang sudah di sort
    datacount = i -1;
    for (i=0 ; i<datacount; i++){
        gotoxy (left_border + 3, top_border+6+2*i);
        printf("%d", i+1);

        gotoxy(left_border + 11, top_border+6+2*i);
        printf("%s", player[i].username);
        gotoxy(left_border + 27, top_border+6+2*i);
        printf("%d", player[i].highscore);
        gotoxy(left_border + 43, top_border+6+2*i);
        printf("%d", player[i].highmove);
        gotoxy(left_border + 59, top_border+6+2*i);
        printf("%d", player[i].totalwin); 
        gotoxy(left_border + 75, top_border+6+2*i);
        printf("%d", player[i].totallose);    
        if ( i > 9){
            break;
        }              
    }
    getch();
    play_sound(2);
    return;
}


//modul untuk membuat border pada halaman leaderboard
void LeaderBoard_Border ()
{
    //kamus data
    int i,j;

    //mendeklarasikan posisi border
    int left_border = ((get_terminal_width('l') - 103)/2);
	int right_border = left_border + 103;
	int top_border = ((get_terminal_width('t') - 26)/2);
	int bottom_border = top_border + 26;

    //header border
    printf_center ("------------------------------ LEADERBOARD ------------------------------", top_border+1);
  
    //border horisontal
    for (i = left_border; i < right_border; i++){
        gotoxy(i, top_border + 3);
        printf("#");
        gotoxy(i, top_border + 5);
        printf("#");        
        gotoxy(i, bottom_border);
        printf("#");
    }

    //teks pada setiap kolom
    gotoxy(left_border + 2 , top_border + 4);
    printf("Rank");    
    gotoxy(left_border + 11 , top_border + 4);
    printf("Username");
    gotoxy(left_border + 27 , top_border + 4);
    printf("Highscore");    
    gotoxy(left_border + 43 , top_border + 4);
    printf("Highmove");
    gotoxy(left_border + 59 , top_border + 4);
    printf("Totalwin");
    gotoxy(left_border + 75 , top_border + 4);
    printf("Totallose");

    //border vertikal
    for (i = top_border + 3 ; i < bottom_border; i++){
        gotoxy(left_border, i);
        printf("#");
        gotoxy(right_border, i);
        printf("#");

        gotoxy(left_border + 7, i);
        printf("#");
        gotoxy(left_border + 23, i);
        printf("#");
        gotoxy(left_border + 39, i);
        printf("#");
        gotoxy(left_border + 55, i);
        printf("#");
        gotoxy(left_border + 71, i);
        printf("#");
        gotoxy(left_border + 87, i);
        printf("#");
    }
}

