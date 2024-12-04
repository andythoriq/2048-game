#include <string.h>
#include "player.h"


void createPlayer(Player *player, char username[10], int highscore, int highmove, int currentscore, int currentmove, int duration, int totalwin, int totallose) {
    setUsername(player, username);
    setHighscore(player, highscore);
    setHighmove(player, highmove);
    setScore(player, currentscore);
    setMove(player, currentmove);
    setDuration(player, duration);
    setTotalWin(player, totalwin);
    setTotalLose(player, totallose);
}

// Getter implementations
const char *getUsername(const Player *p) {
    return p->username;
}

int getHighscore(const Player *p) {
    return p->highscore;
}

int getHighmove(const Player *p) {
    return p->highmove;
}

int getScore(const Player *p) {
    return p->currentmove;
}

int getMove(const Player *p) {
    return p->currentmove;
}

int getDuration(const Player *p) {
    return p->duration;
}

const char * getConvertetDuration(const Player *p)
{
    // convert int seconds to MM:SS
    return "05:50";
}

int getTotalWin(const Player *p) {
    return p->totalwin;
}

int getTotalLose(const Player *p) {
    return p->totallose;
}

// Setter implementations
void setUsername(Player *p, const char *username) {
    strncpy(p->username, username, sizeof(p->username) - 1);
    p->username[sizeof(p->username) - 1] = '\0'; // Ensure null termination
}

void setHighscore(Player *p, int highscore) {
    p->highscore = highscore;
}

void setHighmove(Player *p, int highmove) {
    p->highmove = highmove;
}

void setScore(Player *p, int score) {
    p->currentscore = score;
}

void setMove(Player *p, int move) {
    p->currentmove = move;
}

void setDuration(Player *p, int duration) {
    p->duration = duration;
}

void setTotalWin(Player *p, int totalwin) {
    p->totalwin = totalwin;
}

void setTotalLose(Player *p, int totallose) {
    p->totallose = totallose;
}
