#include <stdio.h>

long long a(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return a(n - 1) * a(n - 1) + 1;
}

int main(int argc, char const *argv[])
{
    printf("%lld\n", a(10));
    return 0;
}
