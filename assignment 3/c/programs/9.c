#include <stdio.h>

int main() {
    char w[100];
    printf("Enter a word: ");
    scanf("%s", w);

    char abr = w[0];

    printf("abbreviation: %c\n", abr);

    return 0;
}