#include <stdio.h>

int time_diff(int start_hr, int start_min, int start_sec, int end_hr, int end_min, int end_sec)
{
    int start_time_in_sec = start_hr * 3600 + start_min * 60 + start_sec;
    int end_time_in_sec = end_hr * 3600 + end_min * 60 + end_sec;
    return end_time_in_sec - start_time_in_sec;
}

int main()
{
    int start_hr, start_min, start_sec;
    int end_hr, end_min, end_sec;
    printf("Enter the start time in the format hr:min:sec: ");
    scanf("%d:%d:%d", &start_hr, &start_min, &start_sec);
    printf("Enter the end time in the format hr:min:sec: ");
    scanf("%d:%d:%d", &end_hr, &end_min, &end_sec);
    printf("%d\n", time_diff(start_hr, start_min, start_sec, end_hr, end_min, end_sec));
    return 0;
}
