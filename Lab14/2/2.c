#include <stdio.h>
#include <string.h>
#include <json.h>

int main(int argc, char *argv[])
{
    struct json_object *parsedJson, *items, *item, *volumeInfo, *authors, *titlePointer;
    const char *author, *title;

    parsedJson = json_object_from_file("volumes.json");
    json_object_object_get_ex(parsedJson, "items", &items);
    for (int i = 0; i < json_object_array_length(items); i++)
    {
        item = json_object_array_get_idx(items, i);
        json_object_object_get_ex(item, "volumeInfo", &volumeInfo);
        json_object_object_get_ex(volumeInfo, "title", &titlePointer);

        title = json_object_get_string(titlePointer);
        json_object_object_get_ex(volumeInfo, "authors", &authors);

        int flag = 0;
        for (int j = 0; j < json_object_array_length(authors); j++)
        {
            author = json_object_get_string(json_object_array_get_idx(authors, j));

            if (strcmp(author, "Валентин Пикуль") == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag)
        {
            printf("%s - %s\n", author, title);
        }
    }
}
