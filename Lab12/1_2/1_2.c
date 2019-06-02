#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void reverse_string(char *str)
{
    char *start = str;
    char *end = start + strlen(str) - 1; /* -1 for \0 */

    while (end > start)
    {
        swap(start, end);

        start++;
        end--;
    }
}

/* Напишите, программу, записывающую слово Х в обратном порядке */
int main(int argc, char const *argv[])
{
    char str[256];
    printf("Input word: ");
    scanf("%s", str);
    reverse_string(str);
    printf("Reverse: %s\n", str);
    return 0;
}
