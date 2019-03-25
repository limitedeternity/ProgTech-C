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

long int _dec_to_oct(long int d, int i)
{
  if (d == 0)
  {
    return 0;
  }
  else
  {
    return (d % 8 * (int)pow(10, i)) + _dec_to_oct(d / 8, i + 1);
  }
}

long int dec_to_oct(long int dec)
{
  return _dec_to_oct(dec, 0);
}

int main(int argc, char const *argv[])
{
  int num;
  scanf("%d", &num);

  printf("%ld\n", dec_to_oct(num));
  getch();
  return 0;
}
