# Badr Abushaar
# CS 100 2021F Section 035
# HW 08, October 28, 2021
# Problem 3

def enterNewPassword():
    digits = '1234567890'
    lengthState = False
    digitState = False
    while True:
        password = input('Enter a password between 8 and 15 characters with at least one digit: ')

        for digit in digits:
            if digit in password:
                digitState = True
        if (8 <= len(password) <= 15) and digitState == True:
            return password
        elif not (8 <= len(password) <= 15) and digitState == True: 
            print('Length is not between 8 and 15 characters')
        elif (8 <= len(password) <= 15) and digitState == False:
            print('Does not contain at least 1 digit')
        else:
            print('Length is not between 8 and 15 characters')
            print('Does not contain at least 1 digit')

newPassword = enterNewPassword()
print(newPassword)