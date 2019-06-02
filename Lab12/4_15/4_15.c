#include <stdio.h>
#include <string.h>
#include <wchar.h>

/*
   15. Напишите программу для подсчета числа букв "о", стоящих пос-
ле буквы "л" в слове X.
*/
int main(int argc, char const *argv[])
{
    wchar_t *str = L"Олово";

    int lFound = 0;
    int oCount = 0;

    for (int i = 0; i < wcslen(str); i++)
    {
        if (!lFound)
        {
            if (str[i] == L'л' || str[i] == L'Л')
            {
                lFound = 1;
            }

            continue;
        }

        if (str[i] == L'о' || str[i] == L'О')
        {
            oCount++;
        }
    }

    printf("%d\n", oCount);
    return 0;
}
