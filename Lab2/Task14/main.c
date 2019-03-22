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

/* 14. Напишите программу, которая по номеру дня недели выводит его название. */
int main(int argc, char const *argv[]) 
{
  int day_number;
  printf("Введите номер дня недели: ");
  scanf("%d", &day_number);

  switch (day_number % 7) {
    case 1:
      printf("ПН\n");
      break;

    case 2:
      printf("ВТ\n");
      break;

    case 3:
      printf("СР\n");
      break;

    case 4:
      printf("ЧТ\n");
      break;

    case 5:
      printf("ПТ\n");
      break;

    case 6:
      printf("СБ\n");
      break;

    case 0:
      printf("ВС\n");
      break;

    default:
      break;
  }

  getch();
  return 0;
}
