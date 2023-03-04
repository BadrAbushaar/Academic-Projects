# Badr Abushaar
# CS 100 2021F Section 035
# HW 06, October 18, 2021

# 1a
def hasFinalLetter(strList, letters):
    strEndingWithLetter = []
    for word in strList:
        if word[-1] in letters:
            strEndingWithLetter.append(word)
    return strEndingWithLetter


# 1b
lstTestCaseOne = ['Lexus', 'Toyota', 'Honda', 'Audi', 'BMW', 'Porsche', 'Mercedes', 'Acura', 'Chevorlet', 'Infiniti',
                  'Ferrari']
strTestCaseOne = 'aeiouAEIOU'
print(hasFinalLetter(lstTestCaseOne, strTestCaseOne))

lstTestCaseTwo = ['NFLX', 'AMZN', 'GOOG', 'FB', 'SPY', 'NVDA', 'SHOP', 'AAPL', 'TSLA', 'BA', 'DAL', 'UAL', 'AAL', 'V']
strTestCaseTwo = 'lL'
print(hasFinalLetter(lstTestCaseTwo, strTestCaseTwo))

lstTestCaseThree = ['Black', 'Gray', 'White', 'Red', 'Orange', 'Yellow', 'Green', 'Blue', 'Purple', 'Pink', 'Brown',
                    'Beige', 'Turquise']
strTestCaseThree = 'fFx'
print(hasFinalLetter(lstTestCaseThree, strTestCaseThree))


# 2a
def isDivisible(maxInt, twoInts):
    numList = range(1, maxInt)
    divisibleList = []
    for num in numList:
        if num % twoInts[0] == 0 and num % twoInts[-1] == 0:
            divisibleList.append(num)
    return divisibleList


# 2b
maxTestCaseOne = 50
intTestCaseOne = (3, 5)
print(isDivisible(maxTestCaseOne, intTestCaseOne))

maxTestCaseTwo = 900
intTestCaseTwo = (10, 65)
print(isDivisible(maxTestCaseTwo, intTestCaseTwo))

maxTestCaseThree = -10
intTestCaseThree = (50, 100)
print(isDivisible(maxTestCaseThree, intTestCaseThree))
