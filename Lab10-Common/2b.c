#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    double *array = (double *)malloc(sizeof(double) * 10);
    srand(time(NULL));

    printf("Array: ");
    for (int i = 0; i < 10; i++)
    {
        *(array + i) = (double)(rand() % 20) / (double)(RAND_MAX / rand());
        printf("%.3lf ", *(array + i));
    }
    printf("\n");

    printf("Result: ");
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            *(array + i) = abs(*(array + i));
        }

        printf("%.3lf ", *(array + i));
    }
    printf("\n");

    free(array);
    return 0;
}
