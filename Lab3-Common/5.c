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
  char *str = (char *)malloc(sizeof(char *));
  printf("Input number: ");
  scanf("%s", str);

  int a;
  printf("Input a: ");
  scanf("%d", &a);

  int i;
  int digitsum = 0;
  int digitmul = 1;

  for (i = 0; i < strlen(str); i++) {
    digitsum += *(str + i) - '0';
    digitmul *= *(str + i) - '0';
  }

  if (digitsum >= 10 && digitsum < 100)
  {
    printf("A: +\n");
  }
  else
  {
    printf("A: -\n");
  }

  if (digitmul >= 100 && digitmul < 1000)
  {
    printf("B: +\n");
  }
  else
  {
    printf("B: -\n");
  }

  if (digitmul > a)
  {
    printf("C: +\n");
  }
  else
  {
    printf("C: -\n");
  }

  if (digitsum % 5 == 0)
  {
    printf("D: +\n");
  }
  else
  {
    printf("D: -\n");
  }

  if (digitsum % a == 0)
  {
    printf("E: +\n");
  }
  else
  {
    printf("E: -\n");
  }

  getch();
  return 0;
}
