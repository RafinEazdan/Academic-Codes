import random
a = random.randint(1,9)
i=0
while True:
    b = int(input("Enter your Guess: "))
    i=i+1
    if(b==a):
        print("Your guess is RIGHT!")
        print(f'Your guessed {i} times.')
        break
    elif(b>a):
        print("Your guess is high. Try again!\n")
    elif(b<a):
        print("Your guess is low.Try again!\n")
    else:
        print("GAME OVER!")
        print(f'Your guessed {i} times.')
        break