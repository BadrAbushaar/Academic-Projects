# Badr Abushaar
# CS 100 2021F Section 035
# HW 10, December 09, 2021

# Problem 1
def safeOpen(filename):
    '''Safe open a file'''
    try:
        file = open(filename, "r")
    except FileNotFoundError:
        file = None

    return file


# Problem 2
def safeFloat(x):
    '''Safe convert string to float'''
    try:
        num = float(x)
    except ValueError:
        num = 0.0

    return num


# Problem 3
def averageSpeed():
    attempts = 1
    while attempts >= 2:
        userFile = input('Enter a file name: ')
        if safeOpen(userFile) == None:
            if attempts >= 2:
                print('File not found. Yet another human error. Goodbye')
                exit
            else:
                print('File not found. Please try again.')
                attempts += 1
        else:
            content = userFile.read().splitlines()
            userFile.close()
            radarList = []
            for line in content:
                for num in line.split(' '):
                    num = safeFloat(num)
                    if num <= 2.0:
                        continue
                    radarList.append(num)
            print(f'Average speed is {sum(radarList) / len(radarList)} mph')


# Problem 1 Test
inputFile = safeOpen('ghost.txt')
print(inputFile)

# Problem 2 Test
floatTest = safeFloat('abc')
print(floatTest)

# Problem 3 Test
averageSpeed()
