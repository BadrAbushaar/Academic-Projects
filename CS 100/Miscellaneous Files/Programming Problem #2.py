words = ['the', 'secret', 'to', 'a', 'better', 'health', 'is', 'exercise']
divergentWords = 0

for word in words:
    if word[0] == word[-1]:
        divergentWords += 1

print((divergentWords, len(words) - divergentWords))
