#include <stdio.h>
#include <string.h>

int main()
{
    FILE *pDatei = fopen("../sensor1.txt", "r+");
    
    if(pDatei == NULL)
    {
        printf("fehler beim öffnen der datei");
        return -1;
    }

    //char cEingelesen = fgetc (pDatei);
    //printf("%c\n", cEingelesen);


    
    char string[100];


    //fscanf(pDatei, "%s", string);
    //printf("%s", string);


    //char c = 'd';
    //fputc(c, pDatei);

    char string1[] = {'h','a','l','l','o'};
    //fputs(string1, pDatei);

    fgets(string, sizeof(string), pDatei);

    fprintf(pDatei, "%s", string);
    fprintf(pDatei, "%s", string);
    fprintf(pDatei, "%s", string);

    printf("%s", string);

    return 0;
}