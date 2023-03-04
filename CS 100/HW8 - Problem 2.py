# Badr Abushaar
# CS 100 2021F Section 035
# HW 08, October 28, 2021
# Problem 2

def twoWordsV2(length, firstLetter):
    firstWord = ''
    secondWord = ''
    while len(firstWord) != length:
        firstWord = input('Enter a {}-letter word please: '.format(length))
    while firstLetter != secondWord:
            secondWord = input('Enter a word beginning with {} please: '.format(firstLetter))
            if (secondWord[0].lower() == firstLetter) or (secondWord[0].upper() == firstLetter):
                return [firstWord, secondWord]
        
wordList = twoWordsV2(4, 'B')
print(wordList)