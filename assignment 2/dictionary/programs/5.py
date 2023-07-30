my_dict = {'a': 1, 'b': 2, 'c': 3, 'd': 4}
keys_to_delete = ['b', 'c']
for key in keys_to_delete:
    del my_dict[key]
print(my_dict)
