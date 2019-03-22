#include <stdio.h>

/* Алгоритм Евклида (Поиск НОД) */
int gcd(int x, int y)
{
  return (x == y) ? x : gcd((x < y) ? x : y, (x > y) ? x - y : y - x);
}

/* Поиск результатов деления первого и второго числа на их НОД */
int main(int argc, char const *argv[])
{
  int x, y;
  scanf("%d %d", &x, &y);

  if (x > 0 && y > 0)
  {
    printf("%d %d\n", x / gcd(x, y), y / gcd(x, y));
  }

   return 0;
}
