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

int gcd(int x, int y)
{
  return (x == y) ? x : gcd((x < y) ? x : y, (x > y) ? x - y : y - x);
}

void Socr(int a, int b, int p, int q)
{
  int tempGcd = gcd(a, b);

  if (a / tempGcd == p && b / tempGcd == q)
  {
    printf("+\n");
  }
  else
  {
    printf("-\n");
  }
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

  int a, b, p, q;
  scanf("%d %d %d %d", &a, &b, &p, &q);
  Socr(a, b, p, q);

  printf("1 / %ld0\n", mulRow(3, 20));
  getch();
  return 0;
}
