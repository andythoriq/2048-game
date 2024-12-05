#ifndef INPUT_USER_NAME_H
#define INPUT_USER_NAME_H

#include <stdbool.h>
#include "../Struct/Player.h"
#include "../Utilities/Utilities.h"
#include "../Utilities/File.h"

//*** screen utama ***//
void halaman_login(Player *player, int *nextkey);

void input_user_screen (Player *player, int *nextkey);

//*** modul pendukung ***//
void input_username_border();

void username_input_check(char input_name[], int *result);

void username_found_result (Player *player, char input_name[], int *nextkey);

#endif