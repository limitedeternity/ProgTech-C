#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

void read_stdin_to_vector(Vector *vector, int lower_bound, char stopword[])
{
    char line[256];

    for (;;)
    {
        scanf("%s", line);

        if (strcmp(line, stopword) == 0)
        {
            if (vector_get_size(vector) >= lower_bound)
            {
                break;
            }
            else
            {
                printf("Not enough values\n");
                continue;
            }
        }
        else
        {
            vector_append(vector, atoi(line));
        }
    }
}

int main(int argc, char const *argv[])
{
    Vector vector;
    vector_init(&vector);

    printf("Insert numbers to array one by one, send STOP to break input flow: \n");
    read_stdin_to_vector(&vector, 5, "STOP");

    int thereAreTwoSequentialZeros = 0;

    for (int i = 0; i < vector_get_size(&vector) - 1; i++)
    {
        if (vector_get(&vector, i) == 0 && vector_get(&vector, i + 1) == 0)
        {
            thereAreTwoSequentialZeros = 1;
            break;
        }
    }

    thereAreTwoSequentialZeros ? printf("+\n") : printf("-\n");
    return 0;
}
