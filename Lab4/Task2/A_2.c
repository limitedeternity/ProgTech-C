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

long int _bin_to_dec(long int b, int i)
{
  if (b == 0)
  {
    return 0;
  }
  else
  {
    return (b % 10 * (int)pow(2, i)) + _bin_to_dec(b / 10, i + 1);
  }
}

long int bin_to_dec(long int bin)
{
  return _bin_to_dec(bin, 0);
}

int main(int argc, char const *argv[])
{
  printf("%ld\n", bin_to_dec(111));
  printf("%ld\n", bin_to_dec(10001));
  printf("%ld\n", bin_to_dec(100));
  printf("%ld\n", bin_to_dec(11001));
  printf("%ld\n", bin_to_dec(0001));
  printf("%ld\n", bin_to_dec(10111));
  printf("%ld\n", bin_to_dec(1000));
  printf("%ld\n", bin_to_dec(11010));
  printf("%ld\n", bin_to_dec(11101));
  printf("%ld\n", bin_to_dec(000000));
  printf("%ld\n", bin_to_dec(100001));
  printf("%ld\n", bin_to_dec(11011));

  getch();
  return EXIT_SUCCESS;
}
