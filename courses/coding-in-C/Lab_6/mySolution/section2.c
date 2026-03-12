#include <stdio.h>
#include <string.h>

typedef struct 
{
    float fuel_level;
    float max_fuel_level;
    char model[100];
}Car;

void refuel(Car *pCar, float addFuel)
{
    if(pCar->fuel_level + addFuel > pCar->max_fuel_level)
    {
        printf("zu wenig platz im tank!");
    }
    else
    {
        pCar->fuel_level += addFuel;
    }
}

int main()
{
    Car lambo;
    lambo.fuel_level = 2;
    lambo.max_fuel_level = 100;
    strcpy(lambo.model, "lambo");

    refuel(&lambo, 89.36);

    printf("%f", lambo.fuel_level);

}