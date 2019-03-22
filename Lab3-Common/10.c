#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  char *num = (char *)malloc(sizeof(char *));
  int a;
  int b;

  printf("Введите число: ");
  scanf("%s", num);
  
  printf("Введите цифру a: ");
  scanf("%d", &a);

  printf("Введите цифру b: ");
  scanf("%d", &b);

  int i;
  int numLength = strlen(num);
  int aPos = (-1);
  int bPos = (-1);

  for (i = 0; i < numLength; i++)
  {
    if (*(num + i) - '0' == a) {
      aPos = i;
    }

    if (*(num + i) - '0' == b) {
      bPos = i;
    }
  }

  if (aPos == -1 && bPos == -1) 
  {
    printf("Указанных цифр в числе нет.\n");
  }
  else 
  {
    if (a == b) 
    {
      printf("a и b - одна и та же цифра.\n");
    }
    else
    {
      printf("Цифра %s расположена в данном числе правее.\n", aPos > bPos ? "a" : "b");
    }
  }

  getch();
  return 0;
}
