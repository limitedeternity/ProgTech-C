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

void print_string(char *str, int from, int to)
{
  char *pos = str;
  int i;

  for (i = from; i < to; i++)
  {
    printf("%c", *(pos + i));
  }
}

int main(int argc, char const *argv[])
{
  int num;
  unsigned int rembit;

  printf("Число: ");
  scanf("%d", &num);

  printf("Позиция вычеркиваемого бита: ");
  scanf("%ud", &rembit);

  printf("Двоичное представление с вычеркнутым %d битом: ", rembit);

  /* 
  Размер числа:
  <= 255 -> 1 байт (2 ** 3 == 8)
  > 255 -> 2 байта (2 ** 4 == 16)
  > 65535 -> 3 байта (2 ** 5 == 32)

  И минус 1, потому что len([0..7]) = 8. 
  Если верхняя граница будет 8, то потребуется 2 байта, чтобы записать число, а не 1.

  Итого:
  <= 255 -> 7
  > 255 -> 15
  > 65535 -> 31

  C отрицательными - зеркально.
  */

  int size = (abs(num) > 255) ? (abs(num) > 65535) ? 31 : 15 : 7;
  char *bin = (char *)malloc(sizeof(char *));

  for (int bit = size; bit >= 0; bit--)
  {
    if (num >= 0)
    {
      bin[size - bit] = ((abs(num) >> bit) & 1) + '0';
    }
    else
    {
      if (bit != 0)
      {
        bin[size - bit] = (!((abs(num) >> bit) & 1)) + '0'; // !x == x ^ 1
      }
      else
      {
        bin[size - bit] = ((!((abs(num) >> bit) & 1)) + 1) + '0';
      }
    }
  }

  print_string(bin, 0, strlen(bin) - rembit);
  print_string(bin, strlen(bin) - rembit + 1, strlen(bin));
  printf("\n");

  getch();
  return 0;
}
