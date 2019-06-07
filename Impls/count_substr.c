#include <string.h>
#include <stdio.h>

int count_substr(char str[], char *substr)
{
    int lengthofsubstr = strlen(substr);
    int cnt = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        char frag[lengthofsubstr];

        for (int j = 0; j < lengthofsubstr; j++)
        {
            frag[j] = str[i + j - 1];
        }

        if (strncmp(frag, substr, lengthofsubstr) == 0)
        {
            cnt++;
        }
    }

    return cnt;
}

int main(int argc, char const *argv[])
{
    char str[256];
    scanf("%s", str);
    printf("%d\n", count_substr(str, "tt"));
    return 0;
}
