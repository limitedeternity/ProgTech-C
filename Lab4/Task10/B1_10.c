#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

  long int bin;
  for (int bit = (abs(num) > 255) ? (abs(num) > 65535) ? 31 : 15 : 7; bit >= 0; bit--)
  {
    if (bit == rembit) {
      continue;
    }

    int bindig = (abs(num) >> bit) & 1;

    if (num >= 0)
    {
      bin += bindig * (int)pow(10, bit);
    }
    else
    {
      if (bit != 0)
      {
        bin += (!bindig) * (int)pow(10, bit); // !x == x ^ 1
      }
      else
      {
        bin += (!bindig) + 1;
      }
    }
  }

  printf("%ld\n", bin);
  getch();
  return 0;
}
