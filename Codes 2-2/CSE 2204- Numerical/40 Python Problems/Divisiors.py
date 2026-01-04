x = int(input("Enter a Number:"))
a = range(1,x+1)
b =[]
for num in a:
    if(x%num ==0):
        b.append(num)
print(b)