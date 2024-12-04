#ifndef File_H
#define File_H

#include "Utilities.h"
#include "../Struct/Player.h"

void open_file_username(Player *player, const char *targetUsername, int *is_found);

void add_newplayer_username (Player *player, const char *targetUsername);

void sort_file_playerscore(Player newPlayer) ;

#endif
