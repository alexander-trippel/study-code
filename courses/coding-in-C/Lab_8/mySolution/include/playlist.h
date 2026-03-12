#ifndef PLAYLIST_H
#define PLAYLIST_H

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SONGS 100

typedef struct Song
{
	char* title;
	char* artist;
	struct Song* pNext;
}Song;

typedef struct
{
	Song* first;
    int anzahlSongs;
}Playlist;



void init_playlist(Playlist *playlist);
void add_song(Playlist* pPlaylist, char* title, char* artist);
void print_playlist(Playlist *pPlaylist);
void delete_firstSong(Playlist* pPlaylist);
void delete_playlist(Playlist *pPlaylist);

#endif