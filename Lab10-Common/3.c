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

    int evenAmount = 0;
    int endswithFiveAmount = 0;

    for (int i = 0; i < 10; i++)
    {
        if (*(array + i) % 2 == 0)
            evenAmount++;
        if (*(array + i) % 10 == 5)
            endswithFiveAmount++;
    }

    printf("Even elements: %d\n", evenAmount);
    printf("el.endswith(5): %d\n", endswithFiveAmount);

    free(array);
    return 0;
}
