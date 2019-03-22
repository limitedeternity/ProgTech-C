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

void permute(char *a, int l, int r)
{
  int i;
  if (l == r)
  {
    printf("%s\n", a);
  }
  else
  {
    for (i = l; i <= r; i++)
    {
      swap((a + l), (a + i));
      permute(a, l + 1, r);
      swap((a + l), (a + i));
    }
  }
}

int main(int argc, char const *argv[])
{
  char *str = (char *)malloc(sizeof(char *));
  printf("Input: ");
  scanf("%s", str);

  permute(str, 0, strlen(str) - 1); /* -1 for \0 */
  getch();
  return 0;
}
