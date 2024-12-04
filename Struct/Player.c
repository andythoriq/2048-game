#include <string.h>
#include "player.h"

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
