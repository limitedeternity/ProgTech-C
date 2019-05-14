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
