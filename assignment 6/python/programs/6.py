# Recursive version to find factorial of a number
def recursive_factorial(n):
    if n == 0:
        return 1
    else:
        return n * recursive_factorial(n - 1)


# Tail recursive version to find factorial of a number
def tail_recursive_factorial(n, acc=1):
    if n == 0:
        return acc
    else:
        return tail_recursive_factorial(n - 1, acc * n)


# Recursive version to find Fibonacci series
def recursive_fibonacci(n):
    if n <= 1:
        return n
    else:
        return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2)


# Tail recursive version to find Fibonacci series
def tail_recursive_fibonacci(n, a=0, b=1):
    if n == 0:
        return a
    elif n == 1:
        return b
    else:
        return tail_recursive_fibonacci(n - 1, b, a + b)


print(recursive_factorial(5))
print(tail_recursive_factorial(5))
print(recursive_fibonacci(7))
print(tail_recursive_fibonacci(7))
