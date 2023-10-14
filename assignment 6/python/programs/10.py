class MultiStack:
    def __init__(self, num_stacks, stack_size):
        self.num_stacks = num_stacks
        self.stack_size = stack_size
        self.array = [None] * (num_stacks * stack_size)
        self.stack_pointers = [-1] * num_stacks

    def push(self, stack_num, value):
        if self.stack_pointers[stack_num] == self.stack_size - 1:
            raise Exception("Stack overflow")
        self.stack_pointers[stack_num] += 1
        self.array[self.index_of_top(stack_num)] = value

    def pop(self, stack_num):
        if self.stack_pointers[stack_num] == -1:
            raise Exception("Stack underflow")
        value = self.array[self.index_of_top(stack_num)]
        self.array[self.index_of_top(stack_num)] = None
        self.stack_pointers[stack_num] -= 1
        return value

    def peek(self, stack_num):
        if self.stack_pointers[stack_num] == -1:
            raise Exception("Stack is empty")
        return self.array[self.index_of_top(stack_num)]

    def is_empty(self, stack_num):
        return self.stack_pointers[stack_num] == -1

    def index_of_top(self, stack_num):
        return stack_num * self.stack_size + self.stack_pointers[stack_num]


# Example usage
multi_stack = MultiStack(3, 5)
multi_stack.push(0, 1)
multi_stack.push(0, 2)
multi_stack.push(0, 3)
multi_stack.push(1, 4)
multi_stack.push(1, 5)
multi_stack.push(2, 6)
print(multi_stack.pop(0))
print(multi_stack.pop(1))
print(multi_stack.pop(2))
