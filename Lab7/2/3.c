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

double seq(int n)
{
  if (n <= 0)
  {
    return 2;
  }
  else if (n == 1)
  {
    return 4;
  }

  return (5.0 / 6.0) * seq(n - 1) - (1.0 / 6.0) * seq(n - 2);
}

double ans(int n)
{
  return 5 * pow(2, 2 - n) - 2 * pow(3, 2 - n);
}

int main(int argc, char const *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%lf\n", seq(n));
  printf("%lf\n", ans(n));
  getch();
  return 0;
}
