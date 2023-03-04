# Badr Abushaar
# CS 100 2021F Section 035
# HW 10, November 08, 2021
# Problem 3

def shareOneLetter(wordList):
    sharedDict = {}
    words = []
    for word in wordList:
        if word not in words:
            words.append(word)
    for word in words:
        if word not in sharedDict.keys():
            sharedDict[word] = []
        else:
            continue
    for word in words:
        for key in sharedDict.keys():
            for character in key:
                if character in word and word not in sharedDict[key]:
                    sharedDict[key].append(word)
    return sharedDict


horton = ['I', 'say', 'what', 'I', 'mean',
          'and', 'I', 'mean', 'what', 'I', 'say']
print(shareOneLetter(horton))

# Test Input 1
colors = ['yellow', 'red', 'pink', 'orange', 'orange']
print(shareOneLetter(colors))
# Test Input 2
fruits = ['apple', 'grapefruit', 'pear']
print(shareOneLetter(fruits))
# Test Input 3
animalsList = ['cat', 'cat', 'Cat', 'dog', 'Dog', 'fish']
print(shareOneLetter(animalsList))
