# Badr Abushaar
# CS 100 2021F Section 035
# HW 09, November 04, 2021
# 2

def file_stats(in_file):
    fin = open(in_file, 'r')
    numOfLines = 0
    numOfWords = 0
    numOfChar = 0
    for line in fin:
        numOfLines += 1
        numOfWords += len(line.split())
        numOfChar += len(line)
    print(f'lines {numOfLines}')
    print(f'words {numOfWords}')
    print(f'characters {numOfChar}')


file_stats('CreatedEqual.txt')
