/*
 * File: section.c
 * Description: Üben von malloc, calloc
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    char eingabe[100];
    
    printf ("gib zahl ein: ");
    int zahl;
    scanf("%d", &zahl);

    //int zahl2 = (int)fgets(eingabe, sizeof(eingabe), stdin);

    int *pZahl = malloc(sizeof *pZahl);
    //if(pZahl)
    *pZahl = zahl;

    printf("zahl: %d\n", *pZahl);


    zahl = zahl * 2;
    int *pArray = calloc(zahl, sizeof *pArray);
    *pArray = zahl;

    for (int i = 0; i <= zahl; i++)
    {
        pArray[i] = i*i;
        printf("zahl: %d\n", pArray[i]);
    }

    void free(void *pZahl);
    void free(void *pArray);
}