#ifndef FILE_H
#define FILE_H

// Struktur untuk merepresentasikan data pemain
typedef struct {
    char username[50];
    int highscore;
    int highmove;
    int duration;
    int totalwin;
    int totallose;
} Player;

void getPlayerData(const char *filename, const char *targetUsername, Player *player);

void addPlayer(const char *filename, Player newPlayer);

#endif