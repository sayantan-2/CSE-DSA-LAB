#include <stdio.h>

int findOddOccurrence(int arr[], int size)
{
   int result = 0;
   for (int i = 0; i < size; i++)
   {
      result ^= arr[i];
   }
   return result;
}

int main()
{
   int arr[] = {4, 5, 2, 4, 5, 2, 3, 1, 1};
   int size = sizeof(arr) / sizeof(arr[0]);

   int oddOccurrenceNumber = findOddOccurrence(arr, size);

   printf("The number occurring an odd number of times is: %d\n", oddOccurrenceNumber);

   return 0;
}
