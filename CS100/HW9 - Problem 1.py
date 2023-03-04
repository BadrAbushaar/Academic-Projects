# Badr Abushaar
# CS 100 2021F Section 035
# HW 09, November 04, 2021
# 1

def file_copy(in_file, out_file):
    fin = open(in_file, 'r')
    fout = open(out_file, 'w')
    text = ''
    contents = fin.readlines()
    for line in contents:
        text += line
    fout.write(text)
    
file_copy('CreatedEqual.txt', 'CopyOfCreatedEqual.txt')
copy = open('CopyOfCreatedEqual.txt')
contents = copy.read()
copy.close()

