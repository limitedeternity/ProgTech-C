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

/* Вычислите сумму цифр данного двузначного натурального числа. */
int main(int argc, char const *argv[])
{
  int num;
  printf("Input: ");
  scanf("%d", &num);

  printf("Sum of digits: %d\n", num % 10 + num / 10);
  getch();
  return 0;
}
