from queue import Queue


def reverse_queue(queue):
    stack = []
    while not queue.empty():
        stack.append(queue.get())

    while stack:
        queue.put(stack.pop())


# Example usage:
if __name__ == "__main__":
    q = Queue()

    for i in range(1, 6):
        q.put(i)

    print("Original Queue:")
    while not q.empty():
        print(q.get(), end=" ")

    for i in range(1, 6):
        q.put(i)

    reverse_queue(q)

    print("\nReversed Queue:")
    while not q.empty():
        print(q.get(), end=" ")
