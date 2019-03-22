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

/*           | 1, если x<=0;
            | x, если x>0 & x<=1;
 y(x)=     | x+1, если 1<x<=2;
          | x+2, если 2<x<=3;
         | x+3, если 3<x.
*/

double y(double x)
{
  if (x <= 0) 
  {
    return 1;
  } else if (x > 0 && x <= 1) 
  {
    return x;
  } else if (x > 1 && x <= 2) 
  {
    return x + 1;
  } else if (x > 2 && x <= 3) 
  {
    return x + 2;
  } else 
  {
    return x + 3;
  }
}

int main(int argc, char const *argv[]) 
{
  double x;
  printf("Введите X: ");
  scanf("%lf", &x);
  printf("y(x) = %.2lf\n", y(x));
  getch();
  return 0;
}
