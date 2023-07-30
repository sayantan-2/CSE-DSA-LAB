my_dict = {'a': 1, 'b': 2, 'c': 3}
old_key = 'b'
new_key = 'd'
my_dict[new_key] = my_dict.pop(old_key)
print(my_dict)
