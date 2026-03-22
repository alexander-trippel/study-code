#include <stdio.h>
#include <assert.h>
#include <string.h>

void copy_first_line ()
{
    FILE *file = fopen("file.txt", "r");
    if(file == NULL)
    {
        printf("Fehler beim öffnen der Datei!!!");
        return;
    }

    FILE *targetFile = fopen("targetFile.txt", "w");
    if(targetFile == NULL)
    {
        printf("Fehler beim öffnen der Datei!!!");
        fclose(file);
        return;
    }

    char string[100];

    fgets(string, sizeof(string), file);
    fputs(string, targetFile);

    fclose(file);
    fclose(targetFile);
}

void test_opening_file(FILE *pFile)
{
    assert(pFile != NULL);
    printf("test bestanden\n");
}

int main()
{
    FILE *test = fopen("file.txt", "r");
    copy_first_line();

    FILE* neu = fopen("neueDatei.txt", "w");

    test_opening_file(test);
}