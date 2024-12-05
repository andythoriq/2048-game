#include <string.h>
#include "player.h"

<<<<<<< HEAD
=======

void createPlayer(Player *player, char username[10], int highscore, int highmove, int currentscore, int currentmove, char duration[6], int totalwin, int totallose) {
    setUsername(player, username);
    setHighscore(player, highscore);
    setHighmove(player, highmove);
    setScore(player, currentscore);
    setMove(player, currentmove);
    setDuration(player, duration);
    setTotalWin(player, totalwin);
    setTotalLose(player, totallose);
}

>>>>>>> ganti-player-menjadi-array
// Getter implementations
const char *getUsername(const Player *p) {
    return p->username;
}

<<<<<<< HEAD
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

=======
int getHighscore(const Player * p) {
    return p->highscore;
}

int getHighmove(const Player * p) {
    return p->highmove;
}

int getScore(const Player * p) {
    return p->currentscore;
}

int getMove(const Player * p) {
    return p->currentmove;
}

const char *getDuration(const Player * p) {
    return p->duration;
}

const char * getConvertetDuration(const Player *p)
{
    return p -> duration;
}

int getTotalWin(const Player * p) {
    return p->totalwin;
}

int getTotalLose(const Player * p) {
    return p->totallose;
}

int getComparedHighScore(Player *p)
{
    if (getScore(p) > getHighscore(p)) {
		setHighscore(p, getScore(p));
	}
    return getHighscore(p);
}

int getComparedHighMove(Player *p)
{
    if (getMove(p) > getHighmove(p)) {
		setHighmove(p, getMove(p));
	}
    return getHighmove(p);
}

>>>>>>> ganti-player-menjadi-array
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

<<<<<<< HEAD
void setDuration(Player *p, int duration) {
    p->duration = duration;
=======
void setDuration(Player *p, char duration[6]) {
    strncpy (p->duration, duration, 6);
>>>>>>> ganti-player-menjadi-array
}

void setTotalWin(Player *p, int totalwin) {
    p->totalwin = totalwin;
}

void setTotalLose(Player *p, int totallose) {
    p->totallose = totallose;
}
