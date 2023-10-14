#include <stdio.h>

// Recursive version to find factorial of a number
int recursiveFactorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * recursiveFactorial(n - 1);
    }
}

// Tail recursive version to find factorial of a number
int tailRecursiveFactorial(int n, int acc)
{
    if (n == 0)
    {
        return acc;
    }
    else
    {
        return tailRecursiveFactorial(n - 1, n * acc);
    }
}

// Recursive version to find the Fibonacci series using a stack
int recursiveFibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
    }
}

int main()
{
    // Example usage
    printf("%d\n", recursiveFactorial(5));
    printf("%d\n", tailRecursiveFactorial(5, 1));
    printf("%d\n", recursiveFibonacci(10));
    return 0;
}
