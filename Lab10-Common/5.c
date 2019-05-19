#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp(const void *a, const void *b)
{
    return (*(double *)a > *(double *)b) - (*(double *)b > *(double *)a);
}

int main(int argc, char const *argv[])
{
    double *array = (double *)malloc(sizeof(double) * 22);
    srand(time(NULL));

    printf("Array: ");
    for (int i = 0; i < 22; i++)
    {
        *(array + i) = (double)(rand() % 5) + 11.0 + (1.0 / (double)((rand() + 1) % 100));
        printf("%.5lf ", *(array + i));
    }
    printf("\n");

    qsort((void *)array, 22, sizeof(*(array + 0)), cmp);

    printf("1st place: %.5lf\n", *(array + 0));
    printf("2nd place: %.5lf\n", *(array + 1));

    free(array);
    return 0;
}
