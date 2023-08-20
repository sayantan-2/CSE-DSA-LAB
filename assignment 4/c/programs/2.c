#include <stdio.h>

// Define a structure to store student data
struct student
{
    float height;
    float weight;
};

int main()
{
    int N;
    printf("Enter the number of students: ");
    scanf("%d", &N);
    // Declare an array of structures to store N students
    struct student students[N];
    float ratio, max_ratio = 0;
    for (int i = 0; i < N; i++)
    {
        printf("Enter the height of student %d: ", i + 1);
        scanf("%f", &students[i].height);
        printf("Enter the weight of student %d: ", i + 1);
        scanf("%f", &students[i].weight);
        ratio = students[i].weight / students[i].height;
        if (ratio > max_ratio)
        {
            max_ratio = ratio;
        }
    }
    printf("The highest weight/height ratio is: %f\n", max_ratio);
    return 0;
}
