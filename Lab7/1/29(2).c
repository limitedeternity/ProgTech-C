#include <stdio.h>
int pow(int, int);
/* ---------------- */
/* Возведение в степень рекурсией */
int main()
{
  int x, y;
  printf("Введите x и y: ");
  scanf("%d %d", &x, &y);
  printf("Результат: %d", pow(x, y));
  return 0;
}
/* ---------------- */
int pow(int m, int n)
{
  if (n == 0)
    return 1;
  else
    return m * pow(m, n - 1);
}
