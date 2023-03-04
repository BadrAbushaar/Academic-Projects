# Badr Abushaar
# CS 100 2021F Section 035
# HW 01, September 9, 2021

# Exercise 5b
numOfStudents = 856
numOfColleges = 5
studentsWithoutCars = 34

#Exercise 5c
weightOfStudent = 153.59
heightOfStudent = 5.91
lengthOfMonitor = 27.4

# Exercise 5d
languageOfJapan = 'Japanese'
universityName = 'NJIT'
favoriteFood = 'Sushi'

# Exercise 1.1
# 1. You get a syntax error
# 2. You get a name error
# 3. It returns no errors, 2++2 would be the same as 2+2 and +2 would be the same as 2
# 4. You get a syntax error
# 5. You get a syntax error

# Exercise 1.2
# 1.
secondsConversion = (42 * 60) + 42
print(secondsConversion) #2562sec
# 2. 
milesConversion = (10 / 1.61)
print(milesConversion) #6.2mi
# 3.
averagePace = (secondsConversion / milesConversion) / 60
averageSpeed = milesConversion / (secondsConversion / 3600) 
print(averagePace) # 6min 52sec
print(averageSpeed) # 8.73 mph

# Exercise 2.1
# 1. 42 = n is illegal because the variable would be 42 and variables cannot start with a digit
# 2. x = y = 1 is legal, both x and y would be equal to one
# 3. The program still runs since it is legal syntax
# 4. You get a syntax error
# 5. You get a name error because it thinks it is a new variable 

# Exercise 2.2
# 1.
radius = 5.0
sphereVolume = (4/3)*(3.14)*(radius**3)
print(sphereVolume) # 523.33

# 2. 
bookCoverPrice = 24.95
discount = 0.40
shippingCostFirstBook = 3.0
shippingCostPerCopy = 0.75
totalCopies = 60
totalWholesaleCost = ((bookCoverPrice * (1.0 - discount) * totalCopies) + (shippingCostPerCopy * totalCopies-1) + shippingCostFirstBook)
print(totalWholesaleCost) # $946.19

#3. 
easyPaceInSeconds = 495
easyPaceMiles = 2
tempoPaceInSeconds = 432
tempoPaceMiles = 3
totalTimeInMinutes = ((easyPaceInSeconds * easyPaceMiles) + (tempoPaceInSeconds * tempoPaceMiles)) / 60
print(totalTimeInMinutes) # 38min
startingTime = (6 * 60) + 52
endingTime = (startingTime + totalTimeInMinutes) / 60
print(endingTime) # Time would be 7:30 AM