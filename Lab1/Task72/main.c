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

/* Вычислите значение функции z=f(x,y) по введённым с клавиатуры вещественным числам x и y: f(x,y)=y*x^2+5*x-2; */
double f(double x, double y)
{
  return y * x * x + 5 * x - 2;
}

int main(int argc, char const *argv[])
{
  double x, y;
  printf("Input: ");
  scanf("%lf%lf", &x, &y);
  printf("Result: %.2lf\n", f(x, y));
  getch();
  return 0;
}
