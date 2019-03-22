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

/* В приведённых ниже программах замените символы "???" на допустимые символы преобразования: */
int main()
{
  int x, y, z;
  printf("Введите значение X: ");
  scanf("%d", &x); // tut
  printf("Введите значение Y: ");
  scanf("%d", &y); // tut
  z = x + y;
  printf("Значение Z: %d\n", z); // i tut
  getch();
  return 0;
}
