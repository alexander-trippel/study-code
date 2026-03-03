#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    struct Element *pNext;
    int adresse;
}Element;

typedef struct 
{
    Element *pStart;
}Liste;

void elementEinfügen(Element *element, Liste *liste)
{
    Element *temp;
    temp = liste -> pStart;

    while (temp -> pNext != NULL)
    {
        temp = temp -> pNext;
    }

    temp -> pNext = element;
}

void elementLöschen(Element *element, Liste *liste)
{
    Element *temp;
    Element *löschen;
    temp = liste -> pStart;

    if(temp == element)
    {
        liste -> pStart = temp -> pNext;
        return;                             // wieso braucht man hier free(temp)
    }
    while (temp -> pNext != element)
    {
        temp = temp -> pNext;
    }
    löschen = temp -> pNext;
    temp -> pNext = löschen -> pNext;   // geht auch temp -> pNext -> pNext ???
}   

void ausgabe(Liste *liste)
{
    Element *temp;
    temp = liste -> pStart;

    while (temp != NULL)
    {
        printf("adresse: %d\n", temp -> adresse);
        temp = temp -> pNext;
    }
    printf("--------------------------------\n");
}

int main ()
{
    Liste liste;
    Element *daniel = malloc(sizeof(*daniel));
    Element *paul = malloc(sizeof(*paul));
    Element *alex = malloc(sizeof(*alex));

    daniel -> adresse = 10;
    paul -> adresse = 20;
    alex -> adresse = 30;

    daniel -> pNext = NULL;
    paul -> pNext = NULL;
    alex -> pNext = NULL;

    liste.pStart = daniel;

    elementEinfügen(paul, &liste);
    elementEinfügen(alex, &liste);
    ausgabe(&liste);

    elementLöschen(daniel, &liste);
    ausgabe(&liste);

    return 0;
}