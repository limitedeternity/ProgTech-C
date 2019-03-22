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

void pair_swap(char *str)
{
  int len = strlen(str);

  if (len % 2 == 1) {
    len--;
  }

  char *pos = str;
  while (pos < str + len - 1)
  {
    swap(pos + 1, pos);
    pos += 2;
  }
}

void swap_first_pair_and_last_pair(char *str)
{
  char *first = str;
  char *second = str + 1;
  char *prelast = str + strlen(str) - 2;
  char *last = str + strlen(str) - 1;

  swap(first, prelast);
  swap(second, last);
}

int char_at_pos_is(char *str, int pos, char *is)
{
  return *(str + pos) == *is ? 1 : 0;
}

void print_string(char *str, int from, int to)
{
  char *pos = str;
  int i;

  for (i = from; i < to; i++) {
    printf("%c", *(pos + i));
  }
}

int main(int argc, char const *argv[])
{
  char *str = (char *)malloc(sizeof(char *));
  printf("Input: ");
  scanf("%s", str);

  reverse_string(str);
  printf("A: %s\n", str);
  reverse_string(str);

  pair_swap(str);

  if (char_at_pos_is(str, 0, "0"))
  {
    printf("B: ");
    print_string(str, 1, strlen(str));
    printf("\n");
  }
  else
  {
    printf("B: %s\n", str);
  }

  pair_swap(str);

  swap(str + 1, str + 2);
  printf("C: %s\n", str);
  swap(str + 1, str + 2);

  swap_first_pair_and_last_pair(str);

  if (char_at_pos_is(str, 0, "0"))
  {
    printf("D: ");
    print_string(str, 1, strlen(str));
    printf("\n");
  }
  else
  {
    printf("D: %s\n", str);
  }

  swap_first_pair_and_last_pair(str);
  getch();
  return 0;
}
