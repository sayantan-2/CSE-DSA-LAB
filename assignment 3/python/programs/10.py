def sort(words):
    return sorted(words)

words = ['cat', 'dog', 'bird', 'fish']
target = input("enter a word:")

print("The word is in the list" if target in words else "word not in list")
print(f"Sorted list of words: {sort(words)}")