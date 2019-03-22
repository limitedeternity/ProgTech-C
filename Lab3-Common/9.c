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

void reverse_string(char *str)
{
  char *start = str;
  char *end = start + strlen(str) - 1; /* -1 for \0 */

  while (end > start)
  {
    swap(start, end);

    start++;
    end--;
  }
}

int cmpfunc(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

int main(int argc, char const *argv[])
{
  char *num = (char *)malloc(sizeof(char *));
  printf("Введите число: ");
  scanf("%s", num);

  reverse_string(num);

  int i;
  int numLength = strlen(num);
  int digits[numLength];
  int digitsCopy[numLength];

  for (i = 0; i < numLength; i++)
  {
    digits[i] = *(num + i) - '0';
    digitsCopy[i] = *(num + i) - '0';
  }

  qsort(digitsCopy, numLength, sizeof(int), cmpfunc);

  int equalityFlag = 1;
  for (i = 0; i < numLength; i++) {
    if (digits[i] != digitsCopy[i]) {
      equalityFlag = 0;
      break;
    }
  }

  if (equalityFlag)
  {
    printf("Yes\n");
  }
  else
  {
    printf("No\n");
  }

  getch();
  return 0;
}
