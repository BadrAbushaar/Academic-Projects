# Badr Abushaar
# CS 100 2021F Section 035
# HW 08, October 28, 2021
# Problem 4

import random

def guessNumber():
    print('I\'m thinking of a number between 0 and 50. You have five tries to guess it.')
    generatedNum = random.randint(0,50)
    print(generatedNum)
    iteration = 0
    guessState = False
    while iteration < 5:
        userNum = int(input('Guess {}? '.format(iteration + 1)))
        iteration += 1
        if userNum != generatedNum:
            if userNum > generatedNum:
                print(userNum, ' is too high')
            else:
                print(userNum, ' is too low')
        else:
            print('You are right! I was thinking of {}!'.format(generatedNum))
            guessState = True
            break
        if guessState == False and iteration == 5:
            print('The correct number was {}'.format(generatedNum))

guessNumber()