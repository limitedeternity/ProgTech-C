#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char word[256];
    scanf("%s", word);

    for (int i = 0; i < strlen(word); i++)
    {
        if (i != 0 && i % 2 == 0)
        {
            memmove(&word[i], &word[i + 1], strlen(word) - i);
        }
    }

    printf("%s", word);
    return 0;
}
