a = [1, 4, 2, 3, 5, 8, 13, 21, 34, 55, 89]
b = []
q = int(input("Enter a Number:"))
for x in a:
    if(x<q):
        # print(x)
        b.append(x)
print(b)