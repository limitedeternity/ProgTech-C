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
/* Ответ: Проверка на четность */
int main(int argc, char const *argv[]) 
{
  int x;
  printf("Введите число x: "); 
  scanf("%d", &x);

  if (x % 2 == 0) {
    printf("Число x является нечётным.\n");
  } else {
    printf("Число x не является нечётным.\n");
  }
  
  getch();
  return 0;
}
