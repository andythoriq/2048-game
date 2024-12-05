#ifndef File_H
#define File_H

#include "Utilities.h"
#include "../Struct/Player.h"

void open_file_username(Player *player, char targetUsername [10], int *is_found);

void add_newplayer_username (Player *player, char targetUsername []);

// void sort_file_playerscore() ;

void update_player(Player *player);

void empty_file (char * filename);

#endif
