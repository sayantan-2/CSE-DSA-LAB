#include <stdio.h>

void reverseString(char *str)
{
    int length = 0;
    while (str[length] != '\0')
        length++;

    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    char w[100];
    printf("enter a word:");
    scanf("%s",w);
    printf("original: %s\n", w);
    reverseString(w);

    printf("reverse: %s\n", w);

    return 0;
}