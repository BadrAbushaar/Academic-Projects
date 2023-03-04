# Badr Abushaar
# CS 100 2021F Section 035
# HW 11, November 29, 2021

# Problem 1
class Dog:
    '''Represents a dogs name and breed'''
    species = 'canis familiaris'

    def __init__(self, name, breed):
        self.name = name
        self.breed = breed
        self.tricks = []

    def teach(self, str):
        self.tricks.append(str)
        return f'{self.name} knows {str}'

    def knows(self, str):
        if str in self.tricks:
            print(f'Yes, {self.name} knows {str}')
            return True
        else:
            print(f'No, {self.name} doesn\'t know {str}')
            return False

sugar = Dog('Sugar', ' border collie')
print(sugar.name)

# Problem 2
print(sugar.tricks)

# Problem 3
print(sugar.teach('frisbee'))

# Problem 4
print(sugar.knows('frisbee'))
print(sugar.knows('arithmetic'))

# Problem 5
print(Dog.species)
print(sugar.species)
