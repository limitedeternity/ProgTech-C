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
  int k;
  int A;
  scanf("%d %d", &k, &A);
  srand(time(NULL));

  for (int i = 0; i < k; i++)
  {
    printf("%d\n", rand() % (A + 1));
  }

  getch();
  return 0;
}
