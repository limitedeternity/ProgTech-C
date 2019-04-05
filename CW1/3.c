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
  double x, y;
  scanf("%lf %lf", &x, &y);

  if (pow(x, 2.0) + pow(y, 2.0) <= pow(6.0, 2.0) && x >= 2.0)
  {
    printf("+");
  }
  else
  {
    printf("-");
  }

  getch();
  return 0;
}
