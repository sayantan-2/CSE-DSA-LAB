my_dict = {'a': 1, 'b': 2, 'c': 3}
value_to_find = int(input("enter the number for search:"))
if value_to_find in my_dict.values():
    print(f"The value {value_to_find} exists in the dictionary")
else:
    print(f"The value {value_to_find} does not exist in the dictionary")
