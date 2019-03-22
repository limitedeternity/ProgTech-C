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
  int suite, quant;
  char* suites[4] = { "пик", "треф", "бубен", "червей" };
  char* quants[14] = { "null", "null", "null", "null", "null", "Шестерка", "Семерка", "Восьмерка", "Девятка", "Десятка", "Валет", "Дама", "Король", "Туз" };

  printf("Масть: ");
  scanf("%d", &suite);

  printf("Достоинство: ");
  scanf("%d", &quant);

  printf("%s %s\n", quants[quant - 1], suites[suite - 1]);
  getch();
  return 0;
}
