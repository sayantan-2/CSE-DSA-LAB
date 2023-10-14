from queue import Queue


def generate_binary_numbers(n):
    if n < 1:
        return

    result = []

    # Create an empty queue
    queue = Queue()

    # Enqueue the first binary number '1'
    queue.put("1")

    # Generate binary numbers from 1 to n
    while n > 0:
        # Dequeue a binary number
        binary_num = queue.get()

        # Append it to the result
        result.append(binary_num)

        # Enqueue the next binary number by appending '0' and '1'
        queue.put(binary_num + "0")
        queue.put(binary_num + "1")

        # Decrease the count
        n -= 1

    return result


# Example usage:
if __name__ == "__main__":
    n = 10  # You can change 'n' to any positive number

    binary_numbers = generate_binary_numbers(n)
    for binary_number in binary_numbers:
        print(binary_number)
