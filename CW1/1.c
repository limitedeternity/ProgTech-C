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

int main(int argc, char const *argv[])
{
  double x, y;
  scanf("%lf %lf", &x, &y);

  if ((2.0 * x) + y >= 4.0 && x + y <= 6.0 && y >= 0.0 && x >= 0.0)
  {
    printf("+\n");
  }
  else
  {
    printf("-\n");
  }

  getch();
  return 0;
}
