def tower_of_hanoi(n, source, destination, auxiliary):
    if n == 1:
        print(f"Move disk 1 from rod {source} to rod {destination}")
        return
    tower_of_hanoi(n - 1, source, auxiliary, destination)
    print(f"Move disk {n} from rod {source} to rod {destination}")
    tower_of_hanoi(n - 1, auxiliary, destination, source)


# Example usage
num_disks = int(input("Enter the number of disks: "))
tower_of_hanoi(num_disks, "A", "C", "B")
