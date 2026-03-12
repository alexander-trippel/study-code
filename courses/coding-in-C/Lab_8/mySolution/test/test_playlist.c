#include <assert.h>
#include <stdio.h>
#include "../include/playlist.h"

/* === Unit-tests === */

// example unit test
void test_init_playlist(void)
{
    Playlist p;
    init_playlist(&p);

    assert(p.first == NULL);
    assert(p.anzahlSongs == 0);
}

void test_add_song()
{
    Playlist p;
    init_playlist(&p);

    add_song(&p, "rocky","Maikel" );

    assert(p.anzahlSongs == 1);
}

void test_delete_firstSong()
{
    Playlist p;
    init_playlist(&p);

    add_song(&p, "KeinBockMehr", "Maikel");
    add_song(&p, "KeinBock", "Alex");

    delete_firstSong(&p);

    assert(p.anzahlSongs == 1);
}

void test_delete_firstSong_empty()
{
    Playlist p;
    init_playlist(&p);

    delete_firstSong(&p);

    assert(p.first == NULL);
}


void test_delete_playlist()
{
    Playlist p;
    init_playlist(&p);

    add_song(&p, "KeinBockMehr", "Maikel");
    add_song(&p, "KeinBock", "Alex");

    delete_playlist(&p);

    assert(p.anzahlSongs == 0);
    assert(p.first == NULL);
}

void test_max_songs_limit()
{
    Playlist p;
    init_playlist(&p);

    for (int i = 0; i < 200; i++)
    {
        add_song(&p, "KeinBockMehr", "Maikel");
        add_song(&p, "KeinBock", "Alex");
    }

    assert(p.anzahlSongs == MAX_SONGS);
}
/* === Test-Runner === */

int main(void)
{
    test_init_playlist();
    test_add_song();
    test_delete_firstSong();
    test_delete_firstSong_empty(); // what happens if we delete first song from empty playlist
    test_delete_playlist();
    test_max_songs_limit(); // verify if the limit will be not be surpassed

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}