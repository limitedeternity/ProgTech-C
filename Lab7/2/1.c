#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void getch()
{
#ifdef WIN32
  system("pause");
#else
  system("read -n1 -p '' key");
#endif
}

long int seq(int n)
{
  if (n <= 1)
  {
    return 3;
  }

  return 6 * seq(n - 1);
}

long int ans(int n)
{
  return (int)(pow(2, n - 1) + 0.5) * (int)(pow(3, n) + 0.5);
}

int main(int argc, char const *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%ld\n", seq(n));
  printf("%ld\n", ans(n));
  getch();
  return 0;
}
