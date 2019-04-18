#include <stdio.h>
#include <stdlib.h>

void getch()
{
#ifdef WIN32
  system("pause");
#else
  system("read -n1 -p '' key");
#endif
}

/* 
y_n = 6 * y_(n-1), y1 = 1;
a_n = 3 * a_(n-1) - 2 * a_(n-2), a0 = 2, a1 = 4;
6 * a_(n+1) - 5 * a_n + a_(n-1) = 0, a0 = 2, a1 = 4;
9 * a_(n+1) - 6 * a_n + a_(n-1) = 0, a0 = 2, a1 = 6;
*/

long int fn1(int n)
{
  if (n <= 1)
  {
    return 1;
  }

  return 6 * fn1(n - 1);
}

long int fn2(int n)
{
  if (n <= 0)
  {
    return 2;
  }
  else if (n == 1)
  {
    return 4;
  }

  return 3 * fn2(n - 1) - 2 * fn2(n - 2);
}

double fn3(int n)
{
  if (n <= 0)
  {
    return 2;
  }
  else if (n == 1)
  {
    return 4;
  }

  return (5.0 / 6.0) * fn3(n - 1) - (1.0 / 6.0) * fn3(n - 2);
}

double fn4(int n)
{
  if (n <= 0)
  {
    return 2;
  }
  else if (n == 1)
  {
    return 6;
  }

  return (2.0 / 3.0) * fn4(n - 1) - (1.0 / 9.0) * fn4(n - 2);
}

int main(int argc, char const *argv[])
{
  int n;
  scanf("%d", &n);

  printf("%ld\n", fn1(n));
  printf("%ld\n", fn2(n));
  printf("%lf\n", fn3(n));
  printf("%lf\n", fn4(n));

  getch();
  return 0;
}
