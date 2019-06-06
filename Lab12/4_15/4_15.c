#include <stdio.h>
#include <locale.h>
#include <wchar.h>

void getwstring(wchar_t *ws, int count)
{
    int x = 0;
    wchar_t *a, wch;

    a = ws;
    while (x < count - 1)
    {
        wch = getwchar();
        if (wch == '\n')
            break;
        *a = wch;
        a++;
        x++;
    }

    *a = '\0';
}

/*
   15. Напишите программу для подсчета числа букв "о", стоящих пос-
ле буквы "л" в слове X.
*/
int main(int argc, char const *argv[])
{
    int lFound = 0;
    int oCount = 0;
    wchar_t str[20];

    setlocale(LC_ALL, "");
    wprintf(L"Введите слово: ");
    getwstring(str, 20);

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

    wprintf(L"%d\n", oCount);
    return 0;
}
