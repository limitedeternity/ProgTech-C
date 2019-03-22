#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  char *num = (char *)malloc(sizeof(char *));
  printf("Введите число: ");
  scanf("%s", num);

  int i;
  int numLength = strlen(num);
  int digits[numLength];

  for (i = 0; i < numLength; i++) {
    digits[i] = *(num + i) - '0';
  }

  int min = digits[0];
  int max = digits[0];

  for (i = 1; i < numLength; i++)
  {
    if (digits[i] > max) {
      max = digits[i];
    }

    if (digits[i] < min) {
      min = digits[i];
    }
  }

  printf("Максимальная цифра: %d\n", max);
  printf("Минимальная цифра: %d\n", min);
  printf("Максимальная цифра больше минимальной на %d\n", max - min);
  printf("Сумма максимальной и минимальной цифр: %d\n", max + min);

  getch();
  return 0;
}
