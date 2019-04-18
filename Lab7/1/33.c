#include <stdio.h>
#include <math.h>

double E_i_g_h_t(int n, double a, double b)
{
  if (n <= 1)
  {
    return sqrt(6.0);
  }

  return sqrt(a + b * E_i_g_h_t(n - 1, a + 1.0, b + 1.0));
}

// sqrt(6 + 2 * sqrt(7 + 3 * ...)). Это 27 задание только в конце остается sqrt(6)
int main(void)
{
  int n;
  scanf("%d", &n);
  printf("%lf\n", E_i_g_h_t(n, 6.0, 2.0));
  return 0;
}
