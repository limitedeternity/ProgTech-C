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

long int mulRow(int start, int end)
{
  if (start > end)
  {
    return 1;
  }

  return start * mulRow(start + 1, end);
}

int main(int argc, char const *argv[])
{
  /* 
  1 + 1 / 2 + 1 / 3 + 1/ ... / 19 + 1 / 20

  Заметим три вещи:
  1) В числителе будет число 2
  2) Знаменатель - ряд произведения от 3 до 20
  3) В конце к знаменателю число 20 домножается ещё раз
  
  Следовательно, числитель и знаменатель можно поделить на 2, и дробь примет несократимый вид.
  */

  /*
  Поскольку произведение ряда от 3 до 20 помещается в памяти, 
  но если его домножить на 10 (20 / 2), то число не поместится,
  поэтому допишем нолик при выводе.
  */

  printf("1 / %ld0\n", mulRow(3, 20));
  getch();
  return 0;
}
