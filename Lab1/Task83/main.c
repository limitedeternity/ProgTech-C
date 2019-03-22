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

/* Объясните результат работы следующих программ */
int main()
{
  int x, y, z, k;
  x = 2;
  x *= 3 + 2;
  printf("x=%d\n", x); // 2 * 5 = 10
  x *= y = z = 4;
  printf("x=%d\n", x); // y = 4; z = 4; 10 * 4 = 40
  x = y == z;
  printf("x=%d\n", x); // y == z -> 1
  k = x == (y = z);
  printf("k=%d,x=%d\n", k, x); // x с предыдущего раза = 1, а k = 40 == 4 -> 0
  getch();
  return 0;
}
