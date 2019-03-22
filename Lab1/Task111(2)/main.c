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

/* В приведённых ниже программах используются действия  над  целыми числами. Определите: значения переменных a и b */
int main(int argc, char const *argv[])
{
  int a, b;
  b = a / 100 * 10 + 9;                    // 0 / 100 = 0; 0 * 10 = 0; 0 + 9 = 9;
  a = (10 * b - a) % 100;                  // 10 * 9 = 90; 90 - 0 = 90; 90 % 100 = 90;
  printf("Значение переменной а=%d\n", a); // 90
  printf("Значение переменной b=%d\n", b); // 9
  getch();
  return 0;
}
