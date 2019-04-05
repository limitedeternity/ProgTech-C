#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  int *s = NULL;
  int **p = &s;
  int ***q = &p;
  int ****r = &q;

  s = (int *)&r;

  printf("%p\n", s);
  printf("%p\n", r);
  printf("%p\n", q);
  printf("%p\n", p);

  printf("%p\n", *s);
  printf("%p\n", *r);
  printf("%p\n", *q);
  printf("%p\n", *p);
  return 0;
}
