T = input().strip()
t = T.lower()

vowels = 'aeiou'
vowelscount = 0
consonantscount = 0

for char in t:
    if char.isalpha():
        if char in vowels:
            vowelscount += 1
        else:
            consonantscount += 1


words = [word.strip(".,!?") for word in t.split()]
words.sort()

if words:  
    print(words[0])
print(vowelscount, consonantscount)
