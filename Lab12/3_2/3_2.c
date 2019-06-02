#include <stdio.h>
#include <ctype.h> // tolower
#include <string.h>

int isUnique(char *str)
{
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        for (int j = i + 1; j < strlen(str); j++)
        {
            if (tolower(str[i]) == tolower(str[j]))
            {
                return 0;
            }
        }
    }

    return 1;
}

/*
   2. Напишите программу, проверяющую, есть ли в слове X две одина-
ковые буквы.
*/
int main(int argc, char const *argv[])
{
    char str[256];
    printf("Input word: ");
    scanf("%s", str);
    printf("%s\n", isUnique(str) ? "Unique" : "Not unique");
    return 0;
}
