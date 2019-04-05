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
  а) можно, в char можно записать int
  б) type mismatch (char и void), присвоить не получится
  в) указатель - не число, нужно разыменовать, чтобы вывести
  г) можно, char можно преобразовать к int и записать в адрес, указанный q
  д) можно
  е) type mismatch (int * и char *), сравнение некорректно
  */

  int val1 = 5;
  int val2 = 3;
  char ch1 = "x"[0];

  int *p = &val1;
  int *q = &val2;
  char *r = &ch1;

  *r = *p;      // а
  *q = (int)*r; // б

  if (r != NULL) // <-- в
    *r = *NULL;  // <-- в

  if (q > NULL) // <-- г
    *q = *p;    // <-- г

  if (q == p)        // <-- д
    printf("%d", q); // <-- д

  if (q != r)       // <-- е
    scanf("%c", r); // <-- е

  getch();
  return 0;
}
