print(5)
print("hello")

# user_input = input("Enter something: ")
# print("You entered:", user_input)

strings = "Artificial,Intelligence"
# strings = strings.casefold()
print(strings)

print(strings.isalpha())
print(strings.isalnum())
# print(strings.is())
new_string = strings.replace("Intelligence", "Learning")
print(new_string)

for i in strings:
    print(i , end="  ")
print('/n')
for index in range(1,20):
    print(index, end=" ")

new_list = [1,2,3,4,5,6,7,8,9,10]
print(new_list)

new_list2 = ["a","b",1,2,True]
print(new_list2)

print(*new_list2)

y = new_list + new_list2
print(y)

tuple1 = (1,2,3,4,5)
print(tuple1)

example_dict = {
    "name": "John",
    "age": 30,
    "city": "New York"
}
print(example_dict)
example_dict["name"] + " Doe"
example_dict["name"] = example_dict["name"] + " Doe"
print(example_dict)

for key in example_dict.values():
    print(key)

print(example_dict.values())

set1 = {1,2,3,4,5,6,7,8,9,10}
set2 = {1,2,3,4,5,7,8,9,10}

MI = set1-set2
print(MI)

str_with_spaces = "   Hello, AI Lab!   "
stripped_str = str_with_spaces.strip(" ")
print(f"Original string: '{str_with_spaces}'")
print(f"Stripped string: '{stripped_str}'")

split_str = strings.split("g")
print(split_str)

place = "Earth"
new = f"I am from {place}"
print(new)

def name(*name1):
    print(f"Name = {name1}")

name(x="John", y="Doe")
