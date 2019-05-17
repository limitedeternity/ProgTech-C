#include <stdio.h>

int main(int argc, char const *argv[])
{
    long long int array[10];

    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            array[i] = 1;
        }
        else
        {
            array[i] = array[i - 1] * array[i - 1] + 1;
        }
    }

    printf("%lld\n", array[10]);
    return 0;
}
