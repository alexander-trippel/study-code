#include <stdio.h>
#include <assert.h>
#include <string.h>

void copy_first_line (const char *lesen,const char *schreiben)
{
    FILE *file = fopen(lesen, "r");
    assert(file != NULL);

    FILE *targetFile = fopen(schreiben, "w");
    assert(targetFile != NULL && "öffnen der Datei hat nicht geklappt");

    char string[100];

    if(fgets(string, sizeof(string), file) != NULL)
    {
        fputs(string, targetFile);
    }

    fclose(file);
    fclose(targetFile);
}


int main()
{
    FILE *neu = fopen("neu.txt", "w");
    assert(neu != NULL && "öffnen der Datei hat nicht geklappt");

    fputs("Hallo wie gehts \nMoin Moin", neu);

    fclose(neu);

    copy_first_line("neu.txt", "erstellteDatei.txt");

    // alles testen
    FILE *test = fopen("neu.txt", "r");
    assert(test != NULL);

    char test_string[100];
    if(fgets(test_string, sizeof(test_string), test) != NULL)
    {
        assert(strcmp(test_string, "Hallo wie gehts\n"));
    }
    else
    {
        assert(0 && "Datei ist leer");
    }
    return 0;
}