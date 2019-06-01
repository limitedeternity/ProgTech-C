#include <stdio.h>
#include <ctype.h>

void find_frequency(char str[], int count[])
{
    int c = 0;
    while (str[c] != '\0')
    {
        if (str[c] >= 'A' && str[c] <= 'Z')
        {
            count[str[c] + 32 - 'a']++;
        }
        else if (str[c] >= 'a' && str[c] <= 'z')
        {
            count[str[c] - 'a']++;
        }

        c++;
    }
}

int main(int argc, char const *argv[])
{
    char str[256];
    int count[26] = {0};

    printf("Input word: ");
    scanf("%s", str);

    find_frequency(str, count);

    int max_freq = 0;
    int max_freq_pos = -1;

    for (int c = 0; c < 26; c++)
    {
        if (count[c] > max_freq)
        {
            max_freq = count[c];
            max_freq_pos = c;
        }
    }

    printf("Most frequent char: %c\n", max_freq_pos + 'a');
    return 0;
}
