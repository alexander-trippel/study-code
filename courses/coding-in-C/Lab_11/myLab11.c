#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    Element *pStart;
}Liste;

typedef struct 
{
    Element *pNext;
    int adresse;
}Element;

void elementEinfügen(Element element, Liste liste)
{
    Element temp;
    temp = liste.pStart;

    while (temp.pNext != NULL)
    {
        temp = temp.pNext;
    }

    temp.pNext = element;
}

void elementLöschen(Element element, Liste liste)
{
    Element temp;
    temp = liste.pStart;

    if(temp.adresse == element.adresse)
    {
        liste.pStart = temp.pNext;
    }
    while (temp.adresse != element.adresse)
    {
        temp = temp.pNext;
    }
}

int main ()
{
}