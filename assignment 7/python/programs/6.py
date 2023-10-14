import heapq


class PriorityQueue:
    def __init__(self):
        self.elements = []

    def is_empty(self):
        return not self.elements

    def enqueue(self, item, priority):
        heapq.heappush(self.elements, (priority, item))

    def dequeue(self):
        if not self.is_empty():
            priority, item = heapq.heappop(self.elements)
            return item
        else:
            print("Priority queue is empty. Cannot dequeue.")

    def display(self):
        for priority, item in self.elements:
            print(f"Priority: {priority}, Item: {item}")


# Example usage:
if __name__ == "__main__":
    priority_queue = PriorityQueue()

    priority_queue.enqueue("Task A", 3)
    priority_queue.enqueue("Task B", 2)
    priority_queue.enqueue("Task C", 1)
    priority_queue.enqueue("Task D", 4)

    print("Priority Queue:")
    priority_queue.display()

    while not priority_queue.is_empty():
        item = priority_queue.dequeue()
        print(f"Dequeued: {item}")
