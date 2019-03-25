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
  /*
  а) можно, указатели одного типа
  б) type mismatch (int * и char *)
  в) можно
  г) можно
  д) type mismatch (int * и char)
  е) type mismatch (int и void *)
  */

  int val1 = 5;
  int val2 = 3;
  char ch1 = "x"[0];

  int *p = &val1;
  int *q = &val2;
  char *r = &ch1;

  p = q;     // а
  q = r;     // б
  p = NULL;  // в
  r = NULL;  // г
  q = *r;    // д
  *p = NULL; // е

  getch();
  return 0;
}
