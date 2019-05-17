#include <stdio.h>
#include <math.h>

long int seq(int n)
{
  if (n <= 0)
  {
    return 1;
  }
  else if (n == 1)
  {
    return -3;
  }

  return 3 * seq(n - 1) - 2 * seq(n - 2);
}

long int ans(int n)
{
  return 5 - (int)(pow(2, n + 2) + 0.5);
}

int main(int argc, char const *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%ld\n", seq(n));
  printf("%ld\n", ans(n));
  return 0;
}
