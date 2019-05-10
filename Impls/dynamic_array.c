#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int capacity = 5;
  int used = 0;
  int *arr = (int *)malloc(sizeof(int) * capacity);

  printf("Insert numbers one by one, send -999 to break input flow: \n");
  for (;;)
  {
    int num;
    scanf("%d", &num);

    if (num == -999)
    {
      break;
    }

    if (used == capacity)
    {
      capacity *= 2;
      arr = (int *)realloc(arr, sizeof(int) * capacity);
    }

    arr[used] = num;
    used++;
  }

  int inc;
  printf("Done. Number to increment by: ");
  scanf("%d", &inc);

  for (int i = 0; i < used; i++)
  {
    arr[i] += inc;
  }

  printf("Done. Resulting array is: ");
  for (int i = 0; i < used; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\n");
  return 0;
}
