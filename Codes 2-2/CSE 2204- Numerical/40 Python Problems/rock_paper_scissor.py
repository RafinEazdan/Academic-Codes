while True:
    u1 = input("First Player Move: ")
    u2 = input("Second Player Move: ")
    if(u1=='rock' and u2 =='scissor'):
        print('Congratulations Player 1, YOU ARE THE WINNER!\n')
        f = input('Do you want to start a new game?')
        if f=='no':
            break
    elif(u1=='scissor' and u2 =='rock'):
        print('Congratulations Player 2, YOU ARE THE WINNER!\n')
        f = input('Do you want to start a new game?')
        if f=='no':
            break
    elif(u1=='scissor' and u2 =='paper'):
        print('Congratulations Player 1, YOU ARE THE WINNER!\n')
        f = input('Do you want to start a new game?')
        if f=='no':
            break
    elif(u1=='paper' and u2 =='scissor'):
        print('Congratulations Player 2, YOU ARE THE WINNER!\n')
        f = input('Do you want to start a new game?')
        if f=='no':
            break
    elif(u1=='paper' and u2 =='rock'):
        print('Congratulations Player 1, YOU ARE THE WINNER!\n')
        f = input('Do you want to start a new game?')
        if f=='no':
            break
    elif(u1=='rock' and u2 =='paper'):
        print('Congratulations Player 2, YOU ARE THE WINNER!\n')
        f = input('Do you want to start a new game? ')
        if f=='no':
            break
    elif u1==u2:
        print("DRAW! Please Continue.\n")
    else:
        print("Please enter valid input\n")
    
    