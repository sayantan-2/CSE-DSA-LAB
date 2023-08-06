#include <stdio.h>

int is_palindrome(char *s)
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char s[] = "racecar";
    printf("%s is %s palindrome\n", is_palindrome(s) ? "Yes" : "No",s);
    return 0;
}