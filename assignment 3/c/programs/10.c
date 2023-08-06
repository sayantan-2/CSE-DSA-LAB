#include <stdio.h>
#include <string.h>

void sort(char **words, int size)
{
    char *temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(words[i], words[j]) > 0)
            {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

int main()
{
    char *words[] = {"cat", "dog", "bird", "fish"};
    int size = sizeof(words) / sizeof(words[0]);
    char target[100];

    printf("Enter a word: ");
    scanf("%s", target);

    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(target, words[i]) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        printf("The word is in the list\n");
    }
    else
    {
        printf("Word not in list\n");
    }

    sort(words, size);

    printf("Sorted list of words: ");
    for (int i = 0; i < size; i++)
    {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}