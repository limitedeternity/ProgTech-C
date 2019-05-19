#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
  srand(time(NULL));
  printf("%d\n", rand() % 2);
  getch();
  return 0;
}
