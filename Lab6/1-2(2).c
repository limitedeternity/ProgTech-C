#include <stdio.h>

int mul(int lim)
{
  int accumulator = 1;
  for (int i = 2; i <= lim; i++)
  {
    accumulator *= i;
  }

  return accumulator;
}

int main(void)
{
  int n;
  printf("Введите натуральное число: ");
  scanf("%d", &n);

  if (n < 5)
  {
    printf("p=%d\n", mul(n));
  }
  else
  {
    printf("p=%d\n", mul(n) + 4);
  }

  return 0;
}
