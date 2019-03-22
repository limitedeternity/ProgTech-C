#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void getch()
{
#ifdef WIN32
  system("pause");
#else
  system("read -n1 -p '' key");
#endif
}

/* 28. Определите натуральное число, получаемое выписыванием в обратном порядке цифр заданного натурального числа. */
int main(int argc, char const *argv[]) 
{
  int num, numcopy;
  scanf("%d", &num);
  memcpy(&numcopy, &num, sizeof(int));

  int len;
  while (numcopy > 0) {
    len++;
    numcopy /= 10;
  }

  int i;
  for (i = 0; i < len; i++) {
    int digit = num / (int)pow(10, i) % 10;
    printf("%d", digit);
  }
  
  printf("\n");
  getch();
  return 0;
}
