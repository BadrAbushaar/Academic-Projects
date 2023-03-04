# Badr Abushaar
# CS 100 2021F Section 035
# HW 10, November 08, 2021
# Problem 2

def initialLetters(wordList):
    letterDict = {}
    words = []
    for word in wordList:
        if word not in words:
            words.append(word)
        if word[0] not in letterDict:
            letterDict[word[0]] = []
        else:
            continue
    for key in letterDict.keys():
        for word in words:
            if word[0] == key:
                if word in letterDict[key]:
                    continue
                else:
                    letterDict[key].append(word)
    return letterDict

horton = ['I', 'say', 'what', 'I', 'mean', 'and', 'I', 'mean', 'what', 'I', 'say'] 
print(initialLetters(horton))
# Test Input 1
fruitsList = ['apple', 'banana', 'strawberry', 'blueberry', 'grapes', 'Jackfruit', 'Grapefruit']
print(initialLetters(fruitsList))
# Test Input 2
colorsList = ['blue', 'Blue', 'Brown', 'brown', 'beige', 'Beige', 'orange']
print(initialLetters(colorsList))
# Test Input 3
randomWordsList = ['shark', 'trophy', 'acorn', 'something', 'pets']
print(initialLetters(randomWordsList))
