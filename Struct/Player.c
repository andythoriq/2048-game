#include <string.h>
#include "player.h"


//nama author   : Andy Thoriq
//nama file     : Player.c
//deskripsi : 
/*file c yang berisi struct Player dan mdoul-modul
yang berhubungan dengan manipulasi struct player*/


//**************//
/* program modul*/
//**************//

//modul untuk menginput data pada subvar-subvar struct player
void createPlayer(Player *player, char username[10], int highscore, int highmove, int currentscore, int currentmove, int totalwin, int totallose) {
    setUsername(player, username);
    setHighscore(player, highscore);
    setHighmove(player, highmove);
    setScore(player, currentscore);
    setMove(player, currentmove);
    setTotalWin(player, totalwin);
    setTotalLose(player, totallose);
}

// Getter implementations
/*untuk memperoleh nilai pada subvar struct*/
char *getUsername(Player *p) {
    return p->username;
}


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

// Setter implementations
/*untuk mengisi data pada subvar Player dengan data baru*/
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

void setTotalWin(Player *p, int totalwin) {
    p->totalwin = totalwin;
}

void setTotalLose(Player *p, int totallose) {
    p->totallose = totallose;
}

