#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_STRING_LENGTH 128

typedef struct
{
    char mDate[MAX_STRING_LENGTH];
    float mAngle[3];
} Data;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Please provide a filename as a command line argument.\n");
        return -1;
    }

    const char* filename = argv[1];

    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file))
    {
        Data data;

        char* token = strtok(line, ",");
        if (token != NULL)
        {
            strncpy(data.mDate, token, sizeof(data.mDate));
            token = strtok(NULL, ",");
        }

        for (int i = 0; i < 3; i++)
        {
            if (token != NULL)
            {
                data.mAngle[i] = atof(token);
                token = strtok(NULL, ",");
            }
        }
        // printf("Read row: date = '%s', angleX = %.2f, angleY = %.2f, angleZ = %.2f\n", data.mDate, data.mAngle[0], data.mAngle[1], data.mAngle[2]);
        // call your function!
    }

    fclose(file);

    return 0;
}
