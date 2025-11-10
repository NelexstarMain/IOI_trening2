T = str(input())
t = t.lower()
vowelscount = 0
consonantscount = 0
for char in t:
    if char in 'auieo':
        vowelscount += 1
    else:
        consonantscount += 1

print(vowelscount, consonantscount)