# Badr Abushaar
# CS 100 2021F Section 035
# HW 03, September 27, 2021

import turtle
import math

shelley = turtle.Turtle()

# 1
# Equilateral Triangle
shelley.pd()
shelley.fd(100)
shelley.lt(120)
shelley.fd(100)
shelley.lt(120)
shelley.fd(100)
shelley.lt(120)
shelley.pu()
shelley.fd(200)

# Square
shelley.pd()
shelley.fd(100)
shelley.rt(90)
shelley.fd(100)
shelley.rt(90)
shelley.fd(100)
shelley.rt(90)
shelley.fd(100)
shelley.pu()
shelley.fd(200)

# Regular Pentagon
shelley.pd()
shelley.fd(100)
shelley.rt(72)
shelley.fd(100)
shelley.rt(72)
shelley.fd(100)
shelley.rt(72)
shelley.fd(100)
shelley.rt(72)
shelley.fd(100)
shelley.rt(72)
shelley.fd(100)
shelley.pu()
shelley.lt(90)
shelley.fd(300)

# 2 Concentric Circles
# Circle 1
shelley.pd()
shelley.circle(50)
shelley.pu()
shelley.rt(90)
shelley.fd(50)
shelley.lt(90)
# Circle 2
shelley.pd()
shelley.circle(100)
shelley.pu()
shelley.rt(90)
shelley.fd(50)
shelley.lt(90)
# Circle 3
shelley.pd()
shelley.circle(150)
shelley.pu()
shelley.rt(90)
shelley.fd(50)
shelley.lt(90)
# Circle 4
shelley.pd()
shelley.circle(200)
shelley.pu()

# 3 Math Module
# 3a
factorialOf100 = math.factorial(100)
print(factorialOf100)

# 3b
logOfOneMillion = math.log2(1000000)
print(logOfOneMillion)

# 3c
greatestCommonFactor = math.gcd(63, 49)
print(greatestCommonFactor)
