class QueueUsingStacks:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def is_empty(self):
        return not self.stack1 and not self.stack2

    def enqueue(self, item):
        self.stack1.append(item)

    def dequeue(self):
        if self.is_empty():
            print("Queue is empty. Cannot dequeue.")
            return None

        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())

        return self.stack2.pop()


# Example usage:
if __name__ == "__main__":
    queue = QueueUsingStacks()

    queue.enqueue(10)
    queue.enqueue(20)
    queue.enqueue(30)

    print("Dequeued:", queue.dequeue())
    print("Dequeued:", queue.dequeue())

    queue.enqueue(40)
    queue.enqueue(50)

    print("Dequeued:", queue.dequeue())
    print("Is queue empty?", queue.is_empty())
