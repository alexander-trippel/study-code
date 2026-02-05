#include <stdio.h>

int main()
{
    int i = 0;
    for (int j = 8; j > 0; j--)
    {
        for (i < 8; i++;)
        {
            printf ("+---");
        }
        printf ("+");
        printf("\n");
        if (i % 2 == 0)
        {
            printf("|   ");
        }
    }
    printf ("Moin"); //Moin anzeigen

    return 0; //Aufgeben
}
//actively using Durchfall