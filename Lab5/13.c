#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  int *s = NULL;
  int **p = &s;
  int ***q = &p;
  int ****r = &q;

  s = (int *)&r;

  return 0;
}
