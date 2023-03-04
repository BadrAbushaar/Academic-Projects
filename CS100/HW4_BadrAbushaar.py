# Badr Abushaar
# CS 100 2021F Section 035
# HW 04, September 30, 2021

import turtle

# 1a
a = 3
b = 4
c = 5

# 1b
if a < b:
    print('OK')

# 1c 
if c < b:
    print('OK')

# 1d
if (a + b) == c:
    print('OK')

# 1e
if (a**2 + b**2) == (c**2):
    print('OK')

# 2
if (a**2 + b**2) == (c**2):
    print('OK')
else:
    print('NOT OK')

# 3
shapeColor = input('What color? ')
lineWidth = int(input('What line width? '))
lineLength = int(input('What line length? '))
shape = input('Line, Triangle, or Square? ')

shelley = turtle.Turtle()
shelley.color(shapeColor)
shelley.width(lineWidth)

if shape == 'line':
    shelley.pd()
    shelley.fd(lineLength)
elif shape == 'triangle':
    shelley.pd()
    shelley.fd(lineLength)
    shelley.lt(120)
    shelley.fd(lineLength)
    shelley.lt(120)
    shelley.fd(lineLength)
    shelley.lt(120)
elif shape == 'square':
    shelley.pd()
    shelley.fd(lineLength)
    shelley.rt(90)
    shelley.fd(lineLength)
    shelley.rt(90)
    shelley.fd(lineLength)
    shelley.rt(90)
    shelley.fd(lineLength)
