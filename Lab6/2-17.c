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

long int gcd(long int x, long int y)
{
  return (x == y) ? x : gcd((x < y) ? x : y, (x > y) ? x - y : y - x);
}

long int factorial(int n)
{
  if (n < 1)
  {
    return 1;
  }

  return n * factorial(n - 1);
}

int main(int argc, char const *argv[])
{
  int rowLength = 20;
  long int finalDenominatorLim = factorial(rowLength);

  long int numeratorSum = 0;
  for (int i = 1; i <= rowLength; i++)
  {
    numeratorSum += 1 * (finalDenominatorLim / i);
  }

  long int commonDivisor = gcd(numeratorSum, finalDenominatorLim);
  printf("%ld / %ld\n", numeratorSum / commonDivisor, finalDenominatorLim / commonDivisor);
  getch();
  return 0;
}
