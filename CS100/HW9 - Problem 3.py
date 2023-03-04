# Badr Abushaar
# CS 100 2021F Section 035
# HW 09, November 04, 2021
# 3

import string

def repeat_words(in_file, out_file):
    fin = open(in_file, 'r')
    fout = open(out_file, 'w')
    for line in fin:
        text = []
        words = []
        repeatedWords = []
        for word in line.split():
            words.append(word.lower().strip(string.punctuation))
        for word in words:
            if (words.count(word) > 1) and (word not in text) and (word not in repeatedWords):
                fout.write(word + " ") 
                repeatedWords.append(word)
        fout.write('\n')
    fin.close()
    fout.close()

repeat_words('Suess.txt', 'Repeated.txt')
