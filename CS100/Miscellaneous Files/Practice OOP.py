
class Section:
    '''Represents a course offering'''

    def __init__(self, sectionID):
        self.sectionID = sectionID
        self.enrolledStudents = []

    def enroll(self, studentName):
        self.enrolledStudents.append(studentName)

    def isEnrolled(self, studentName):
        return studentName in self.enrolledStudents


math111 = Section('Math111_101')
math111.enroll = 'Joe Josephson'
math111.enroll = 'Mary Smith'
print(math111.isEnrolled('Mary Josephosn'))
