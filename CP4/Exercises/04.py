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

words_count = {}

for word in words:
    if (word in words_count) == False:
        words_count[word] = 1
    else:
        words_count[word] += 1

maxs = -1
maxword = ""

for key in words_count.keys():
    if words_count[key] > maxs:
        maxs = words_count[key]
        maxword = key

if words:  
    print(words[0])

print(maxword)
print(vowelscount, consonantscount)

