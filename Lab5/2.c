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

int main(int argc, char const *argv[])
{
  int val1 = 5;
  int val2 = 3;

  /*
  а) Значение переменной p - указатель на адрес целочисленной переменной.
  Для получения значения нужно применить операцию разыменовывания.

  б) Следовательно, переменная *p - целое число 5.

  в) typeof(p) == "int *", typeof(*p) == "int"
  */

  int *p = &val1;
  int *q = &val2;

  printf("%d %d\n", *p, *q);
  getch();
  return 0;
}
