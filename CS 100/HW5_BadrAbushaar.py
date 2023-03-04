# Badr Abushaar
# CS 100 2021F Section 035
# HW 05, October 04, 2021

# 1 
months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']
for month in months:
    if month[0] == 'J':
        print(month)

# 2
for num in range(0,100):
    if num % 2 == 0 and num % 5 == 0:
        print(num)

# 3 
horton = 'A person\'s a person, no matter how small.'
vowels = 'aeiouAEIOU'

for character in horton:
    if character in vowels:
        print(character)