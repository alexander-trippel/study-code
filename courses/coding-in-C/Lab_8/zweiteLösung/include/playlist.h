#ifndef PLAYLIST_H
#define PLAYLIST_H

#define MAX_SONGS 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Song
{
    char *title;
    char *name;
    struct Song *pNext;
}Song;

typedef struct
{
    int anzahl;
    Song *first;
}Playlist;

void init_Playlist(Playlist *pPlaylist);
void add_Song(Playlist *pPlaylist, char *pTitle, char *pName);
void print_playlist(Playlist *pPlaylist);
void delete_firstSong(Playlist *pPlaylist);
void delete_Playlist(Playlist *pPlaylist);
#endif