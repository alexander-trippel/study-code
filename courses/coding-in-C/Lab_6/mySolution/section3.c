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
    SensorData data[3000];
    int object_detection[3000];
}Sensor;


void read_measurement_files(char *pFilename, Sensor *pSensor)
{
    FILE *temp = fopen(pFilename, "r");
    if(temp = NULL)
    {
        printf("Problem");
        return;
    }

    int i = 0;
    while(i < 3000)
    {
        if(fscanf(temp, "%f%f", pSensor->data[i].time, pSensor->data[i].probability) == 2)
        {
            i++;
        }
        else
        {
            printf("Datei konnte nicht gelesen werden");
            fclose(temp);
            return;
        }
    }
    fclose(temp);
    return;
}


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
    sensor1.threshold = 0.8;
    Sensor sensor2;
    sensor2.threshold = 0.7;

    

}