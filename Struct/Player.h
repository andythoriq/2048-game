#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player
{
    char username[10];
    int highscore;
    int highmove;
    int currentscore;
    int currentmove;
<<<<<<< HEAD
    int duration;
=======
    char duration [6];
>>>>>>> ganti-player-menjadi-array
    int totalwin;
    int totallose;
} Player;

<<<<<<< HEAD
=======
void createPlayer(Player *player, char username[10], int highscore, int highmove, int currentscore, int currentmove, char duration[6], int totalwin, int totallose);

>>>>>>> ganti-player-menjadi-array
// Getter
const char *getUsername(const Player *p);
int getHighscore(const Player *p);
int getHighmove(const Player *p);
int getScore(const Player *p);
int getMove(const Player *p);
<<<<<<< HEAD
int getDuration(const Player *p);
int getTotalWin(const Player *p);
int getTotalLose(const Player *p);
=======
const char *getDuration(const Player *p);
int getTotalWin(const Player *p);
int getTotalLose(const Player *p);
const char *getConvertetDuration(const Player *p);
>>>>>>> ganti-player-menjadi-array

// Setter
void setUsername(Player *p, const char *username);
void setHighscore(Player *p, int highscore);
void setHighmove(Player *p, int highmove);
void setScore(Player *p, int score);
void setMove(Player *p, int move);
<<<<<<< HEAD
void setDuration(Player *p, int duration);
void setTotalWin(Player *p, int totalwin);
void setTotalLose(Player *p, int totallose);


=======
void setDuration(Player *p, char duration[6]);
void setTotalWin(Player *p, int totalwin);
void setTotalLose(Player *p, int totallose);

int getComparedHighScore(Player *p);
int getComparedHighMove(Player *p);
>>>>>>> ganti-player-menjadi-array
#endif