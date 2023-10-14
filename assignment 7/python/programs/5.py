class Deque:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def size(self):
        return len(self.items)

    def add_front(self, item):
        self.items.insert(0, item)

    def add_rear(self, item):
        self.items.append(item)

    def remove_front(self):
        if not self.is_empty():
            return self.items.pop(0)
        else:
            print("Deque is empty. Cannot remove from the front.")

    def remove_rear(self):
        if not self.is_empty():
            return self.items.pop()
        else:
            print("Deque is empty. Cannot remove from the rear.")

    def display(self):
        print("Deque:", self.items)


# Example usage:
if __name__ == "__main__":
    deque = Deque()

    deque.add_rear(10)
    deque.add_rear(20)
    deque.add_front(5)
    deque.add_front(2)
    deque.display()

    front_item = deque.remove_front()
    rear_item = deque.remove_rear()
    deque.display()

    print("Removed front item:", front_item)
    print("Removed rear item:", rear_item)
