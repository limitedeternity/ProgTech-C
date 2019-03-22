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

void swap(char *x, char *y)
{
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int main(int argc, char const *argv[])
{
  char *str = (char *)malloc(sizeof(char *));
  printf("Input: ");
  scanf("%s", str);

  int i;
  for (i = 0; i < strlen(str) - 1; i++) {
    char *x = str + i;
    char *y = str + i + 1;
    swap(x, y);
  }

  printf("%s\n", str);
  getch();
  return 0;
}
