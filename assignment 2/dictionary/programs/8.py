my_dict = {'a': 3, 'b': 2, 'c': 1}
min_key = min(my_dict, key=my_dict.get)
print(min_key) 