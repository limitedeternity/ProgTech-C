/* 
Да, присваивания эквивалентны. Компилятор не даёт связать переменные, поэтому побочных эффектов не будет.
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
  int x = 5;
  int y = 7;
  int *py;

  x = y;

  printf("%d %d\n", x, y); // 7 7
  y++;
  printf("%d %d\n", x, y); // 7 8

  py = &y;
  y = *py;

  printf("%d %d\n", x, y); // 8 8
  y++;
  printf("%d %d\n", x, y); // 8 9
  return 0;
}
