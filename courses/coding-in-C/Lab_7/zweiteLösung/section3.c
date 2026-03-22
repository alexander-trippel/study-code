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
    Song *first;
}Playlist;

void init_Playlist(Playlist *pPlaylist)
{
    pPlaylist->first = NULL;
    return;
}

void add_Song(Playlist *pPlaylist, char *pTitle, char *pName)
{
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