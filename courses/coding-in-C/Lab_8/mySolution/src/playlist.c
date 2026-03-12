#include"../include/playlist.h"


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

	if(!pPlaylist){
		printf("Error");
		return;
	}

    if(pPlaylist->anzahlSongs > MAX_SONGS)
    {
        printf("Fehler: maximale anzahl an Lieder erreicht!!!");
        return;
    }

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
    pPlaylist->anzahlSongs = pPlaylist->anzahlSongs + 1;
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
    pPlaylist->anzahlSongs = pPlaylist->anzahlSongs - 1;
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
