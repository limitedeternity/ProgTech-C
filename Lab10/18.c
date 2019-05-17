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

    for (int i = 0; i < (vector_get_size(&vector) - (vector_get_size(&vector) & 1)) / 2; i++)
    {
        int swap = vector_get(&vector, i);
        vector_set(&vector, i, vector_get(&vector, vector_get_size(&vector) - 1 - i));
        vector_set(&vector, vector_get_size(&vector) - 1 - i, swap);
    }

    printf("Reversed array: ");
    for (int i = 0; i < vector_get_size(&vector); i++)
    {
        printf("%d ", vector_get(&vector, i));
    }

    printf("\n");

    vector_free(&vector);
    return 0;
}
