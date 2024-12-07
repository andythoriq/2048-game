#include "View_LeaderBoard.h"

void View_LeaderBoard()
{
    FILE *file;
    Player player[50];
    int i, datacount;
    
    // posisi border
    int left_border = ((get_terminal_width('l') - 103)/2);
	int right_border = left_border + 103;
	int top_border = ((get_terminal_width('t') - 26)/2);
	int bottom_border = top_border + 26;

    LeaderBoard_Border();

    sort_file_playerscore();  

    //mengisi array dengan data file//
    file = fopen ("Player_Score.txt", "r");
    if (file == NULL){
        printf("error opening file!");
        return;
    }
    i = 0;
    fseek(file, 0, SEEK_SET);
    fscanf(file, "%s %d %d %d %d", player[i].username, &player[i].highscore, &player[i].highmove, &player[i].totalwin, &player[i].totallose);
    fseek(file, 0, SEEK_SET);
    while (!feof(file)) {
        fscanf(file, "%s %d %d %d %d", player[i].username, &player[i].highscore, &player[i].highmove, &player[i].totalwin, &player[i].totallose);
        i++;
    }
    fclose(file);
    ///////// selesai mengisi array //////////////
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

void LeaderBoard_Border ()
{
    int i,j;

    int left_border = ((get_terminal_width('l') - 103)/2);
	int right_border = left_border + 103;
	int top_border = ((get_terminal_width('t') - 26)/2);
	int bottom_border = top_border + 26;
    printf_center ("------------------------------ LEADERBOARD ------------------------------", top_border+1);
    for (i = left_border; i < right_border; i++){
        gotoxy(i, top_border + 3);
        printf("#");
        gotoxy(i, top_border + 5);
        printf("#");        
        gotoxy(i, bottom_border);
        printf("#");
    }

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

