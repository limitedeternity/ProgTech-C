#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int **matrix = (int **)malloc(6 * sizeof(int *));

    for (int i = 0; i < 6; i++)
    {
        int *vector = (int *)malloc(6 * sizeof(int));

        if (i == 0)
        {
            for (int j = 0; j < 6; j++)
            {
                *(vector + j) = 1;
            }
        }
        else
        {
            *(vector + 0) = 1;
        }

        *(matrix + i) = vector;
    }

    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            *(*(matrix + i) + j) = *(*(matrix + i - 1) + j) + *(*(matrix + i) + j - 1);
        }
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%3d ", *(*(matrix + i) + j));
        }

        printf("\n");
    }

    for (int i = 0; i < 6; i++)
    {
        free(*(matrix + i));
    }

    free(matrix);
    return 0;
}
