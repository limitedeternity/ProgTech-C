#include <stdio.h>

/* (a|(((4+c)>>b)&7))||(b>(a%3)) */
void main(int argc, char const *argv[]) 
{
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  printf("%d", (a | 4 + c >> b & 7 || b > a % 3) == (a|(((4+c)>>b)&7))||(b>(a%3)) ? 1 : 0);

  // a | 4 + c >> b & 7 || b > a % 3;
  /* From left: 
           1) + 
           2) >>
           3) &
           4) |
           5) %
           6) >
           7) ||
  */
}
