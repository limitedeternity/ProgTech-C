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
  int x;
  scanf("%d", &x);
  printf("%s\n", (x & 1) ? "No" : "Yes");
  getch();
  return 0;
}
