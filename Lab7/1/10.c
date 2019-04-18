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

long int F(int n)
{
  if (n > 23)
  {
    return n - 3;
  }

  return F(F(n + 4));
}

int main(int argc, char const *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%ld\n", F(n));
  getch();
  return 0;
}
