#include <stdio.h>

int main()
{
    float zahl1;
    float zahl2;
    char operation;
    float erg;

    printf("bidde zahlen eingeben: ");
    scanf(" %f %f", &zahl1, &zahl2);
    
    if (operation != '+' || operation != '-' || operation != '*' || operation != '/')
    {
        printf ("falsche eingabe. bitte etwas anderes eingeben: ");
        scanf( "%c", &operation);
    }
    else 
    {
        printf("\n + oder - oder / oder * eingeben: ");
        scanf(" %c", &operation);
    }

    if (operation == '+')
    {
        erg = zahl1 + zahl2;
    }
    else if(operation == '-')
    {
        erg = zahl1 - zahl2;
    }
    else if(operation == '/')
    {
        erg = zahl1 / zahl2;
    }
    else
    {
        erg = zahl1 * zahl2;
    }
    

    printf("Lösung: %f", erg);
    printf("\n");

}