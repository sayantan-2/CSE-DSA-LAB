class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def create_node(data):
    return Node(data)


def insert(head, data):
    new_node = create_node(data)

    if head is None:
        head = new_node
    else:
        temp = head
        while temp.next is not None:
            temp = temp.next
        temp.next = new_node

    return head


def merge_sorted_lists(list1, list2):
    if list1 is None:
        return list2
    if list2 is None:
        return list1

    merged_list = None
    if list1.data < list2.data:
        merged_list = list1
        merged_list.next = merge_sorted_lists(list1.next, list2)
    else:
        merged_list = list2
        merged_list.next = merge_sorted_lists(list1, list2.next)

    return merged_list


def print_list(head):
    current = head
    while current is not None:
        print(current.data, end=" ")
        current = current.next
    print()


if __name__ == "__main__":
    list1 = None
    list2 = None

    num1 = int(input("Enter the number of elements in the first sorted list: "))
    print("Enter the elements in ascending order:")
    for _ in range(num1):
        data = int(input())
        list1 = insert(list1, data)

    num2 = int(input("Enter the number of elements in the second sorted list: "))
    print("Enter the elements in ascending order:")
    for _ in range(num2):
        data = int(input())
        list2 = insert(list2, data)

    print("List 1:", end=" ")
    print_list(list1)

    print("List 2:", end=" ")
    print_list(list2)

    merged_list = merge_sorted_lists(list1, list2)
    print("Merged Sorted List:", end=" ")
    print_list(merged_list)
