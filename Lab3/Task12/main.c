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

/* 12. Пусть k>0 - целое число. Вычислите k-й член последовательности {x_n}, 
где x0=1, x_n = n * x_(n-1) + 1 / n, n=1,2,3,... */
double p_n(int k) {
  double x_n = 1.0;
  int n = 1;

  while (n <= k) {
    x_n = n * x_n + 1 / n;
    n++;
  }

  return x_n;
}

int main(int argc, char const *argv[]) 
{
  int k;
  printf("K: ");
  scanf("%d", &k);

  printf("Pn: %.2lf\n", p_n(k));
  getch();
  return 0;
}
