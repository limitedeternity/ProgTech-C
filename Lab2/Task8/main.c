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

/* 8. Составьте программу, которая определяет, принадлежит ли точка 
M(x,y) окружности с центром в точке (-1.2,0.1) и радиусом равным 7,
если x и y - заданные действительные числа. 
*/
#define X_AXIS_CENTER -1.2
#define Y_AXIS_CENTER 0.1
#define RADIUS 7

int main(int argc, char const *argv[]) 
{
  double x, y;
  printf("Input: ");
  scanf("%lf%lf", &x, &y);

  if (
    x > X_AXIS_CENTER + RADIUS ||
    x < X_AXIS_CENTER - RADIUS || 
    y > Y_AXIS_CENTER + RADIUS ||
    y < Y_AXIS_CENTER - RADIUS
  ) {
    printf("Не принадлежит\n");
  } else {
    printf("Принадлежит\n");
  }

  getch();
  return 0;
}
