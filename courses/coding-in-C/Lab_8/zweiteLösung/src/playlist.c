#include "../include/playlist.h"

void init_Playlist(Playlist *pPlaylist)
{
    pPlaylist->first = NULL;
    pPlaylist->anzahl = 0;
    return;
}

void add_Song(Playlist *pPlaylist, char *pTitle, char *pName)
{
    if(pPlaylist->anzahl >= MAX_SONGS)
    {
        printf("Playlist ist voll");
        return;
    }

    Song *neu = malloc(sizeof(neu));
    Song *temp = pPlaylist->first;
    if(neu == NULL)
    {
        printf("fehler beim Speicher reservieren");
        return;
    }

    neu->name = malloc(strlen(pName + 1));
    neu->title = malloc(strlen(pTitle + 1));

    if (!neu->title || !neu->name)
    {
        printf("Error: Memory could not be allocated.\n");
        free(neu->title);
        free(neu->name);
        free(neu);
        return;
    }

    strcpy(neu->name, pName);
    strcpy(neu->title, pTitle);

    if(pPlaylist->first == NULL)
    {
        pPlaylist->first = neu;
        return;
    }
    else
    {
        while(temp->pNext != NULL)
        {
            temp = temp->pNext;
        }
        temp->pNext = neu;
    }
    pPlaylist->anzahl += 1;
    return;
}

void print_playlist(Playlist *pPlaylist)
{
    Song *temp = pPlaylist->first;
    if(temp == NULL)
    {
        printf("fehler beim Speicher reservieren");
        return;
    }

    while(temp != NULL)
    {
        printf("Title: %s   Artist: %s \n\n", temp->title, temp->name);
        temp = temp->pNext;
    }
    return;
}

void delete_firstSong(Playlist *pPlaylist)
{
    Song *temp = pPlaylist->first;
    if(temp == NULL)
    {
        printf("fehler beim Speicher reservieren");
        return;
    }

    pPlaylist->first = temp->pNext;

    free(temp->name);
    free(temp->title);
    free(temp);
    pPlaylist->anzahl -= 1;
    return;
}

void delete_Playlist(Playlist *pPlaylist)
{
    Song *temp = pPlaylist->first;
    if(temp == NULL)
    {
        printf("Playlist ist leer");
        return;
    }

    while(pPlaylist->first != NULL)
    {
        temp = pPlaylist->first;
        pPlaylist->first = temp->pNext;

        free(temp->name);
        free(temp->title);
        free(temp);
    }
    return;
}