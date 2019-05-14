#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Set N for [N x N] matrix (at least 3): ");
    scanf("%d", &n);

    if (n < 3)
        return 1;

    srand(time(NULL));

    int **matrix = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        int *vector = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            *(vector + j) = rand() % 10;
            printf("%d ", *(vector + j));
        }

        printf("\n");
        *(matrix + i) = vector;
    }

    int global_min_sum = 999;
    int shift = 1;

    printf("\n-----\n");
    while (shift < n)
    {
        int sum = 0;

        for (int row = n - 1, col = n - 1 - shift; col >= 0; row--, col--)
        {
            printf("Looking at [%d, %d]\n", row + 1, col + 1);
            int number = *(*(matrix + row) + col);
            sum += abs(number);
        }

        printf("-----\n");

        if (sum < global_min_sum)
        {
            global_min_sum = sum;
        }

        shift++;
    }

    shift = 1;
    printf("\n-----\n");

    while (shift < n)
    {
        int sum = 0;

        for (int col = n - 1, row = n - 1 - shift; row >= 0; col--, row--)
        {
            printf("Looking at [%d, %d]\n", row + 1, col + 1);
            int number = *(*(matrix + row) + col);
            sum += abs(number);
        }

        printf("-----\n");

        if (sum < global_min_sum)
        {
            global_min_sum = sum;
        }

        shift++;
    }

    printf("\nMin sum: %d\n", global_min_sum);

    for (int i = 0; i < n; i++)
    {
        free(*(matrix + i));
    }

    free(matrix);

    return 0;
}
