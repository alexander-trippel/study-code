/*
* File: section3.c 
*Description: Program für das verwalten von Playlists
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Song
{
	char* title;
	char* artist;
	struct Song* pNext;
}Song;

typedef struct
{
	Song* first;
}Playlist;


/*
* @brief neue Playlist erstellen
* 
* @param playlist	Pointer auf Playlist
*/
void init_playlist(Playlist *playlist)
{
	playlist->first = NULL;
	return;
}


/*
* @brief neuen Song zur Playlist hinzufügen
*
* @param playlist	Pointer auf Playlist
* @param title		Titel vom Song
* @param artist		Name des Sängers
*/
void add_song(Playlist* pPlaylist, char* title, char* artist)
{
	Song* neu = malloc(sizeof(*neu));
	neu->pNext = NULL; 
	if (neu == NULL)
	{
		printf("Fehler: Speicher konnte nicht reserviert werden\n\n");
		return;
	}

	neu->title = malloc(strlen(title)+1);
	neu->artist = malloc(strlen(artist)+1);
	if (neu->artist == NULL || neu->title == NULL)
	{
		printf("Fehler: Speicher konnte nicht reserviert werden\n\n");
		free(neu->artist);
		free(neu->title);
		free(neu);
		return;
	}

	strcpy(neu->artist, artist);
	strcpy(neu->title, title);

	if (pPlaylist->first == NULL)
	{
		pPlaylist->first = neu;
	}
	else
	{
		Song* temp = pPlaylist->first;
		while (temp->pNext != NULL)
		{
			temp = temp->pNext;
		}
		temp->pNext = neu;
	}
}


/*
* @brief Playlist ausgeben
*
* @param playlist	Pointer auf Playlist
*/
void print_playlist(Playlist *pPlaylist)
{
	if (pPlaylist->first == NULL)
	{
		printf("Playlist ist leer\n\n");
	}
	Song* ausgabe = pPlaylist->first;
	while (ausgabe != NULL)
	{
		printf("Title: %s, Artist: %s\n", ausgabe->title, ausgabe->artist);
		ausgabe = ausgabe->pNext;
	}
}


/*
* @brief den ersten Song in der Playlist löschen
*
* @param playlist	Pointer auf Playlist
*/
void delete_firstSong(Playlist* pPlaylist)
{
	if (pPlaylist->first == NULL)
	{
		printf("Playlist ist leer");
		return;
	}
	Song* temp = pPlaylist->first;
	pPlaylist->first = temp->pNext;
	free(temp->artist);
	free(temp->title);
	free(temp);
}


/*
* @brief die ganze Playlist löschen
*
* @param playlist	Pointer auf Playlist
*/
void delete_playlist(Playlist *pPlaylist)
{
	while (pPlaylist->first != NULL)
	{
		delete_firstSong(pPlaylist);
	}
	return;
}


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