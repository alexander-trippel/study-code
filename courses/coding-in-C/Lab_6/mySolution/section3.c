#include <stdio.h>
#include <string.h>

typedef struct
{
    float time;
    double probability;
}SensorData;

typedef struct 
{ 
    int id;
    double threshold;
    SensorData data[100];
    int object_detection[];
}Sensor;


int main()
{
    FILE *data1 = fopen("sensor1.txt", "r");
    FILE *data2 = fopen("sensor2.txt", "r");

    if(data1 = NULL)
    {
        printf("problem");
    }
    
    if(data2 = NULL)
    {
        printf("problem");
    }
    Sensor sensor1;
    Sensor sensor2;


}