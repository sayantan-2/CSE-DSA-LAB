class MultipleQueue:
    def __init__(self, num_queues, queue_size):
        self.num_queues = num_queues
        self.queue_size = queue_size
        self.array = [None] * (num_queues * queue_size)
        self.front = [-1] * num_queues
        self.rear = [-1] * num_queues

    def is_empty(self, queue_num):
        return self.front[queue_num] == -1

    def is_full(self, queue_num):
        return (self.rear[queue_num] + 1) % self.queue_size == self.front[queue_num]

    def enqueue(self, queue_num, item):
        if self.is_full(queue_num):
            print(f"Queue {queue_num} is full. Cannot enqueue item.")
        else:
            if self.is_empty(queue_num):
                self.front[queue_num] = self.rear[queue_num] = 0
            else:
                self.rear[queue_num] = (self.rear[queue_num] + 1) % self.queue_size
            self.array[queue_num * self.queue_size + self.rear[queue_num]] = item
            print(f"Enqueued in Queue {queue_num}: {item}")

    def dequeue(self, queue_num):
        if self.is_empty(queue_num):
            print(f"Queue {queue_num} is empty. Cannot dequeue.")
        else:
            item = self.array[queue_num * self.queue_size + self.front[queue_num]]
            if self.front[queue_num] == self.rear[queue_num]:
                self.front[queue_num] = self.rear[queue_num] = -1
            else:
                self.front[queue_num] = (self.front[queue_num] + 1) % self.queue_size
            print(f"Dequeued from Queue {queue_num}: {item}")
            return item

    def display(self, queue_num):
        if self.is_empty(queue_num):
            print(f"Queue {queue_num} is empty.")
        else:
            print(f"Queue {queue_num} elements:", end=" ")
            i = self.front[queue_num]
            while True:
                print(self.array[queue_num * self.queue_size + i], end=" ")
                if i == self.rear[queue_num]:
                    break
                i = (i + 1) % self.queue_size
            print()


# Example usage:
if __name__ == "__main__":
    num_queues = 3
    queue_size = 5
    multi_queue = MultipleQueue(num_queues, queue_size)

    multi_queue.enqueue(0, 10)
    multi_queue.enqueue(1, 20)
    multi_queue.enqueue(2, 30)
    multi_queue.enqueue(0, 40)
    multi_queue.enqueue(1, 50)
    multi_queue.enqueue(2, 60)
    multi_queue.display(0)
    multi_queue.display(1)
    multi_queue.display(2)

    multi_queue.dequeue(0)
    multi_queue.dequeue(1)
    multi_queue.dequeue(2)
    multi_queue.display(0)
    multi_queue.display(1)
    multi_queue.display(2)
