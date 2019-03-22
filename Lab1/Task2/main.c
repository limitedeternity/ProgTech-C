#include <stdio.h>
#include <math.h>

#include <stdlib.h>
void getch()
{
  #ifdef WIN32
  system("pause");
  #else
  system("read -n1 -p '' key");
  #endif
}

/* Вычислите объём цилиндра с радиусом основания 5 см и высотой 10 см. */
#define RADIUS 5
#define HEIGHT 10

int main(int argc, char const *argv[])
{
  printf("V = %.2lf\n", M_PI * RADIUS * RADIUS * HEIGHT);
  getch();
  return 0;
}
