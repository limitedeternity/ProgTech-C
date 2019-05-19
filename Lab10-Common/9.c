#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int **matrix = (int **)malloc(5 * sizeof(int *));
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        int *vector = (int *)malloc(5 * sizeof(int));
        for (int j = 0; j < 5; j++)
        {
            *(vector + j) = rand() % 20;
            printf("%d ", *(vector + j));
        }

        printf("\n");
        *(matrix + i) = vector;
    }

    for (int j = 0; j < 5; j++)
    {
        int max = -1;

        for (int i = 0; i < 5; i++)
        {
            if (*(*(matrix + i) + j) > max)
                max = *(*(matrix + i) + j);
        }

        printf("Максимум в столбце %d: %d\n", j + 1, max);
    }

    for (int i = 0; i < 5; i++)
    {
        free(*(matrix + i));
    }

    free(matrix);
    return 0;
}
