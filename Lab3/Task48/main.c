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

/* 48. Найдите наибольшую степень числа  2,  делящую  данное  целое
число a. */
int main(int argc, char const *argv[]) 
{
  long a;
  printf("Введите а: ");
  scanf("%ld", &a);

  long result = 0;
  long temp;

  for (temp = 2; temp <= a; temp *= 2) {
    if (a % temp == 0) {
      result = temp;
    }
  }

  if (result != 0) {
    printf("Наибольшая степень числа 2, делящая данное целое число %ld = %ld.\n", a, result);
  } else {
    printf("Результат не найден.\n");
  }
  
  getch();
  return 0;
}
