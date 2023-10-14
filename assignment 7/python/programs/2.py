class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinearQueue:
    def __init__(self):
        self.front = self.rear = None

    def is_empty(self):
        return self.front is None

    def enqueue(self, item):
        new_node = Node(item)
        if self.rear is None:
            self.front = self.rear = new_node
            return
        self.rear.next = new_node
        self.rear = new_node

    def dequeue(self):
        if self.is_empty():
            print("Queue is empty. Cannot dequeue.")
            return
        item = self.front.data
        self.front = self.front.next
        if self.front is None:
            self.rear = None
        print(f"Dequeued: {item}")
        return item

    def display(self):
        if self.is_empty():
            print("Queue is empty.")
        else:
            current = self.front
            while current:
                print(current.data, end=" ")
                current = current.next
            print()


# Example usage:
if __name__ == "__main__":
    queue = LinearQueue()

    queue.enqueue(10)
    queue.enqueue(20)
    queue.enqueue(30)
    queue.enqueue(40)
    queue.enqueue(50)
    queue.display()

    queue.dequeue()
    queue.dequeue()
    queue.display()

    queue.enqueue(60)
    queue.enqueue(70)
    queue.display()
