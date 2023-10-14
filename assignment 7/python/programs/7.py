from collections import deque


class StackUsingQueues:
    def __init__(self):
        self.queue1 = deque()
        self.queue2 = deque()

    def is_empty(self):
        return not self.queue1 and not self.queue2

    def push(self, item):
        if not self.queue1:
            self.queue1.append(item)
            while self.queue2:
                self.queue1.append(self.queue2.popleft())
        else:
            self.queue2.append(item)
            while self.queue1:
                self.queue2.append(self.queue1.popleft())

    def pop(self):
        if not self.is_empty():
            return self.queue1.popleft() if self.queue1 else self.queue2.popleft()
        else:
            print("Stack is empty. Cannot pop.")

    def top(self):
        if not self.is_empty():
            return self.queue1[0] if self.queue1 else self.queue2[0]
        else:
            print("Stack is empty. No top element.")


# Example usage:
if __name__ == "__main__":
    stack = StackUsingQueues()

    stack.push(10)
    stack.push(20)
    stack.push(30)

    print("Top element:", stack.top())
    print("Popped:", stack.pop())

    stack.push(40)
    print("Top element:", stack.top())

    print("Popped:", stack.pop())
    print("Popped:", stack.pop())

    print("Is stack empty?", stack.is_empty())
