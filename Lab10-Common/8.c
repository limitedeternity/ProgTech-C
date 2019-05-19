#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int **matrix = (int **)malloc(5 * sizeof(int *));
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        int *vector = (int *)malloc(20 * sizeof(int));
        for (int j = 0; j < 20; j++)
        {
            *(vector + j) = rand() % 101;
            printf("%d ", *(vector + j));
        }

        printf("\n");
        *(matrix + i) = vector;
    }

    int pos;
    printf("Выберите спортсмена (1-20): ");
    scanf("%d", &pos);
    pos = (pos - 1) % 20;

    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += *(*(matrix + i) + pos);
    }

    printf("Сумма баллов: %d\n", sum);

    for (int i = 0; i < 5; i++)
    {
        free(*(matrix + i));
    }

    free(matrix);
    return 0;
}
