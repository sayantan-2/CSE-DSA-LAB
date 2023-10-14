#include <stdio.h>

void findMaxSubarrayWithSum(int arr[], int size, int targetSum)
{
   int maxLength = 0;
   int currentSum = 0;
   int end = -1;
   int startIndex = 0;

   for (int i = 0; i < size; i++)
   {
      currentSum += arr[i];

      if (currentSum == targetSum)
      {
         maxLength = i + 1;
         end = i;
      }

      if (currentSum - targetSum >= 0)
      {
         int startIndexTemp = startIndex;
         while (currentSum - targetSum >= 0)
         {
            currentSum -= arr[startIndexTemp];
            startIndexTemp++;
         }

         if (i - startIndexTemp + 1 > maxLength)
         {
            maxLength = i - startIndexTemp + 1;
            end = i;
         }
         startIndex = startIndexTemp;
      }
   }

   if (maxLength > 0)
   {
      printf("Maximum length subarray with sum %d is [%d, %d]\n", targetSum, startIndex, end);
   }
   else
   {
      printf("No subarray with sum %d found.\n", targetSum);
   }
}

int main()
{
   int arr[] = {4, 2, -3, 1, 6};
   int size = sizeof(arr) / sizeof(arr[0]);
   int targetSum = 6;

   findMaxSubarrayWithSum(arr, size, targetSum);

   return 0;
}
