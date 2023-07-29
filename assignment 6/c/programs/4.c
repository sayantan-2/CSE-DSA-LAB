#include <stdio.h>
int main()
{
   int n;
   printf("Enter limit: ");
   scanf("%d", &n);
   int a = 0;
   int b = 1;
   int c = a + b;
   int s = 1 + c * c;
   while (s <= n)
   {
      a = b;
      b = c;
      c = a + b;
      s = s + c * c;
   }
   printf("%d\n", s);
   return 0;
}