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

long int factorial(int n)
{
  if (n < 1)
  {
    return 1;
  }

  return n * factorial(n - 1);
}

double F(int m, int n)
{
  return (double)(factorial(n) * factorial(m)) / (double)factorial(n + m);
}

int main(int argc, char const *argv[])
{
  int m, n;
  scanf("%d %d", &m, &n);
  printf("%.12lf\n", F(m, n));
  getch();
  return 0;
}
