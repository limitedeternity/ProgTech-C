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

int main(int argc, char const *argv[])
{
  double minutes;
  int g;

  printf("Input: ");
  scanf("%lf", &minutes);

  if (minutes <= 3)
  {
    g = 1;
  }
  else
  {
    if (fmod(minutes, 5.0) == 0)
    {
      g = 0;
    }
    else
    {
      if (fmod(minutes, 5.0) <= 3.0)
      {
        g = 1;
      }
      else
      {
        g = 0;
      }
    }
  }

  if (g == 1)
  {
    printf("Green\n");
  }
  else
  {
    printf("Red\n");
  }

  getch();
  return 0;
}
