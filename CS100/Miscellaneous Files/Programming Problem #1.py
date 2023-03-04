words = ['And', 'this', 'above', 'all']
vowels = 'aeiouAEIOU'
wordsStartingWithVowels = 0
wordsEndingWithVowels = 0

for word in words:
    if word[0] in vowels:
        wordsStartingWithVowels += 1
    if word[-1] in vowels:
        wordsEndingWithVowels += 1

print([wordsStartingWithVowels, wordsEndingWithVowels])