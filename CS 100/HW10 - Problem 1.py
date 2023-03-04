# Badr Abushaar
# CS 100 2021F Section 035
# HW 10, November 08, 2021
# Problem 1

def initialLetterCount(wordList):
    letterDict = {}
    for word in wordList:
        if word[0] not in letterDict:
            letterDict[word[0]] = 1
        else:
            letterDict[word[0]] += 1    
    return letterDict

horton = ['I', 'say', 'what', 'I', 'mean', 'and', 'I', 'mean', 'what', 'I', 'say'] 
print(initialLetterCount(horton))

# Test Input 1
carBrandsList = ['Lexus', 'Toyota', 'Acura', 'Honda', 'BMW', 'Kia', 'lexus', 'toyota', 'acura', 'honda', 'bmw', 'kia']
print(initialLetterCount(carBrandsList))
# Test Input 2
randomList = ['Rose', 'gold', 'As', 'the', 'sun', 'shines', 'through', 'my', 'window']
print(initialLetterCount(randomList))
# Test Input 3
repititionList = ['hello', 'hello', 'hello', 'hello', 'hello', 'hello', 'Hello']
print(initialLetterCount(repititionList))