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

void fn1()
{
  int val1 = 5;
  int val2 = 3;

  int *p = &val1;
  int *q = &val2;

  *p = *q;    // По адресу, куда указывает p, записано число 3 из адреса, на который указывает q
  if (p == q) // нет, указатели не указывают на один и тот же адрес
    p = NULL;
  else if (*p == *q)  // да, значения, хранящиеся по адресам, равны
    q = p;            // q наследует свойства p, теперь q и p указывают в одно место - на число 3.
  if (p == q)         // да, они указывают на один и тот же адрес
    *q = 4;           // В адрес, куда указывает q, теперь записано число 4
  printf("%d\n", *p); // разыменовывание p вернет 4
}

void fn2()
{
  int val1 = 5;
  int val2 = 3;

  int *p = &val1;
  int *q = &val2;

  *p = *q;
  if (p == q)
    p = NULL;
  else if (*p == *q)
    q = p;
  if (p != q)
    *q = 4;
  else
    *p = 6;
  printf("%d\n", *p); // разыменовывание p вернет 6 (аналогично fn1)
}

void fn3()
{
  int val1 = 5;
  int val2 = 3;

  int *p = &val1;
  int *q = &val2;

  *p = *q;    // По адресу, куда указывает p, записано число 3 из адреса, на который указывает q
  if (p != q) // да, p и q не указывают на один адрес
    p = NULL; // p - теперь null pointer
  else if (*p == *q)
    q = p;
  if (p != q) // да, p и q не указывают на один адрес
    *q = 4;   // В адрес, куда указывает q, теперь записано число 4
  else
    *p = 6;
  printf("%d\n", *p); // Segfault, доступ к области памяти, куда указывает p, запрещен (прим: никуда)
}

int main(int argc, char const *argv[])
{
  fn1();
  fn2();
  fn3();
  getch();
  return 0;
}
