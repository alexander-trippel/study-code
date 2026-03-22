#include "include/playlist.h"

int main()
{
    Playlist *meinePlaylist = malloc(sizeof(meinePlaylist));
    if(meinePlaylist == NULL)
    {
        printf("fehler beim Speicher reservieren");
        return -1;
    }
init_Playlist(meinePlaylist);

add_Song(meinePlaylist, "hallo", "Alex");
add_Song(meinePlaylist, "hallo", "dani");
add_Song(meinePlaylist, "hallo", "paul");

print_playlist(meinePlaylist);

delete_firstSong(meinePlaylist);

print_playlist(meinePlaylist);

delete_Playlist(meinePlaylist);

free(meinePlaylist);
return 0;
}