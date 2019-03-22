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

int main(int argc, char const *argv[])
{
  double x, y, z, q;
  printf("X: ");
  scanf("%lf", &x);
  printf("Y: ");
  scanf("%lf", &y);

  q = 2.8 * sin(x) + fabs(y);
  z = (x + (2 + y) / (x * x)) / (y + 1 / sqrt(x * x + 10));
  printf("Z=%lf, Q=%lf\n", z, q);
  getch();
  return 0;
}
