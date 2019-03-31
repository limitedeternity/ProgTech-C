#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  long value1 = 20000;
  long value2;

  long *lPtr;            // a
  lPtr = &value1;        // б
  printf("%d\n", *lPtr); // в

  value2 = *lPtr;          // г
  printf("%d\n", value2);  // д
  printf("%p\n", &value1); // е
  printf("%p\n", lPtr);
  return 0;
}
