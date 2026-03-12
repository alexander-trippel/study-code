#include "../include/playlist.h"

/*
* @brief alle Funktionen testen
*/
int main()
{
	Playlist meinePlaylist;
	init_playlist(&meinePlaylist);

	add_song(&meinePlaylist, "Rap", "Daniel");
	add_song(&meinePlaylist, "Pop", "Paul");
	add_song(&meinePlaylist, "Classic", "Eduard");
	add_song(&meinePlaylist, "Chill", "Diana");

	print_playlist(&meinePlaylist);

	delete_firstSong(&meinePlaylist);

	print_playlist(&meinePlaylist);

	delete_playlist(&meinePlaylist);

	return 0;
}