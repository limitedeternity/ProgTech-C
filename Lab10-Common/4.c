#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int *array = (int *)malloc(sizeof(int) * 25);
    srand(time(NULL));

    printf("Array: ");
    for (int i = 0; i < 25; i++)
    {
        *(array + i) = rand() % 70 + 150;
        printf("%d ", *(array + i));
    }
    printf("\n");

    int max = -1;
    int min = 500;

    for (int i = 0; i < 25; i++)
    {
        if (*(array + i) > max)
            max = *(array + i);
        if (*(array + i) < min)
            min = *(array + i);
    }

    printf("Diff(%d, %d): %d\n", max, min, max - min);

    free(array);
    return 0;
}
