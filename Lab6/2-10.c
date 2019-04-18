#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void getch()
{
#ifdef WIN32
  system("pause");
#else
  system("read -n1 -p '' key");
#endif
}

double _infRadicalExpr(int iter, int limit)
{
  if (iter >= limit)
  {
    return 0;
  }

  if (iter % 3 == 0)
  {
    return sqrt(23 - 2 * _infRadicalExpr(iter + 1, limit));
  }
  else
  {
    return sqrt(23 + 2 * _infRadicalExpr(iter + 1, limit));
  }
}

double infRadicalExpr(int limit)
{
  return _infRadicalExpr(0, limit);
}

int main(int argc, char const *argv[])
{
  int n = 1;
  double result = 0.0;
  double prevIter = 0.0;

  do
  {
    prevIter = result;
    result = infRadicalExpr(n);
    n++;
  } while (fabs(result - prevIter) >= pow(10, -12));

  printf("Infinite radical expression = %.12lf\n", result);
  printf("Shortand = %.12lf\n", 1.0 + 4.0 * sqrt(3.0) * sin(M_PI / 9.0));
  getch();
  return 0;
}
