# Badr Abushaar
# CS 100 2021F Section 035
# HW 08, October 28, 2021
# Problem 1

def twoWords(length, firstLetter):
    firstWord = ''
    secondWord = ''
    while True:
        firstWord = input('Enter a {}-letter word please: '.format(length))
        if len(firstWord) == length:
            break
    while True:
        secondWord = input('Enter a word beginning with {} please: '.format(firstLetter))
        if (secondWord[0].lower() == firstLetter) or (secondWord[0].upper() == firstLetter):
            break
    return [firstWord, secondWord]
        
wordList = twoWords(4, 'B')
print(wordList)