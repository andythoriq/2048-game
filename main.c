// includes
// #include "Pages/View_InputUserName.h"
// #include "Pages/View_LeaderBoard.h"
// #include "Pages/View_Tutorial.h"
// #include "Pages/View_LobbyScreen.h"
// #include "Pages/View_GamePlay.h"
// #include "Utilities/File.h"
// #include "Struct/Player.h"
// #include "Struct/Tile.h"
// #include "Utilities/Utilities.h"
#include "Utilities/everything.h"

int main()
{
	Player player;
	Tile tiles[4][4];
	int done = 0, nextkey = 0, key, selectedarrow = 0;

	createPlayer(&player, "", 0,0,0,0,"00:00",0,0);
	// generateTiles(tiles);

	while (done == 0){
		lobby_screen(selectedarrow);

		selectedarrow_text(&selectedarrow, &key);

		if(key == ENTER){
			clearscreen ();
			
			play_sound(2);

			switch (selectedarrow){
				case 0:
					halaman_login(&player, &nextkey);
					if (nextkey == 1){
						/*game mulai*/
						View_GamePlay(tiles, &player);

					}
					break;
				case 1:
					View_LeaderBoard();
					break;
				case 2:
					View_Tutorial();
					break;
				case 3:
					printf_center("Terimakasih Sudah Bermain", 15);
					done = 1;
					break;
			}
		}
	}
	return 0;
}