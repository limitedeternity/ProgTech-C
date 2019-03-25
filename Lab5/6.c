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

int main(int argc, char const *argv[])
{

  *q + 2; // Корректно. Разыменовывание q вернет число. А к числу можно прибавить 2.

  **q; /* Да, в языке C такая конструкция корректна, если q - указатель на указатель. 
            Вернет содержимое конечного адреса. */

  ++*q; /* Можно. Разыменовывание q вернет число. 
           Оператор префиксного инкремента увеличит полученное число и запишет назад по адресу,
            на который указывает q */

  *++q; /* Нет, оператор префиксного инкремента нельзя применять на указателе. 
            А если q не указатель, а число, то и указывать не на что. */

  getch();
  return 0;
}