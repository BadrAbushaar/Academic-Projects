# Badr Abushaar
# CS 100 2021F Section 035
# Practice Question 1

class State:
    '''Represents universities in a state'''

    def __init__(self, name):
        self.name = name
        self.universities = []

    def addUniversity(self, university):
        if university not in self.universities:
            self.universities.append(university)

    def isHomeOf(self, university):
        return university in self.universities


nj = State('New Jersey')
nj.addUniversity('NJIT')
nj.addUniversity('Princeton')
print(nj.isHomeOf('MIT'))
print(nj.universities)
