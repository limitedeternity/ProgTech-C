#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int *array = (int *)malloc(sizeof(int) * 10);
    srand(time(NULL));

    printf("Array: ");
    for (int i = 0; i < 10; i++)
    {
        *(array + i) = rand() % 100;
        printf("%d ", *(array + i));
    }
    printf("\n");

    printf("Indices of el.endswith(0): ");
    for (int i = 0; i < 10; i++)
    {
        if (*(array + i) % 10 == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(array);
    return 0;
}
