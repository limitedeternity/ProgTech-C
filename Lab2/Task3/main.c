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

/* 3. Дано  натуральное  число  n (n<10000). Определите сумму цифр данного числа n. */
int main(int argc, char const *argv[]) 
{
  int n;
  printf("Введите число: ");
  scanf("%d", &n);
  
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }

  printf("Digit sum is %d\n", sum);
  getch();
  return 0;
}
