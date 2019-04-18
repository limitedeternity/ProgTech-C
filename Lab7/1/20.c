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

long int fib(int n)
{
  if (n < 2)
  {
    return n;
  }

  return fib(n - 1) + fib(n - 2);
}

int main(int argc, char const *argv[])
{
  int h;
  scanf("%d", &h);

  int i = 2;
  for (;;)
  {
    long int tempfib = fib(i++);
    if (tempfib > h)
    {
      printf("%ld\n", tempfib);
      break;
    }
  }

  getch();
  return 0;
}
