#include <stdio.h>
#include "File.h"


int main() {
    const char *filename = "player_board.txt";
    Player player;

    char targetUsername[50];
    printf("Masukkan username yang ingin dicari: ");
    scanf("%s", targetUsername);

    // Panggil fungsi untuk mencari atau menambahkan data
    getPlayerData(filename, targetUsername, &player);

    // Tampilkan data pemain yang ditemukan atau baru dibuat
    printf("\nData Player:\n");
    printf("Username: %s\n", player.username);
    printf("Highscore: %d\n", player.highscore);
    printf("Highmove: %d\n", player.highmove);
    printf("Duration: %d\n", player.duration);
    printf("Totalwin: %d\n", player.totalwin);
    printf("Totallose: %d\n", player.totallose);

    return 0;
}
