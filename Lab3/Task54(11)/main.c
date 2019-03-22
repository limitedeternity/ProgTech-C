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

/* Определите, какие задачи решают приведённые ниже программы */
/* Ответ: Сумма ряда от 1 до 20 */
int main(int argc, char const *argv[])
{
  int count = 0;
  int sum = 0;
  while (count <= 20)
  {
    sum += count;
    count++;
  }

  printf("sum=%d\n", sum);
  getch();
  return 0;
}
