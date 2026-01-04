word = input("Enter a word: ")
word = str(word)

#no built-in function to reverse a string but this method can do the reversing easily
reverse = word[::-1] #Slice the string starting at the end of the string and move backwards

if word == reverse:
    print("Palindrome.\n")
else:
    print("Not Palindrome.\n")