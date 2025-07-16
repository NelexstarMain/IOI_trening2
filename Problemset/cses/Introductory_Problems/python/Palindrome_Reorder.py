from collections import Counter

a = input()
v = Counter(a)

mid = ""
half = []

for ch, cnt in v.items():
    if cnt % 2 == 1:
        if mid:
            print("NO SOLUTION")
            break
        mid = ch * cnt
    half.extend([ch] * (cnt // 2))
else:
    print("".join(half + list(mid) + half[::-1]))



"""Old version

from collections import Counter

a = input()

v = Counter(a)
el = []
r_1 = []
r_2 = []
count = 0
for key, i in v.items():
    if i%2 == 1:
        el = [key]*i
        count += 1
    else:
        r_1.extend([key]*int(i/2))
        r_2.extend([key]*int(i/2))

    if count > 1:
        print("NO SOLUTION")
        break
    else:
        continue

else:
    r_2.reverse()
    if el != "":
        print("".join(r_1 + el + r_2))
    else:
        print("".join(r_1 + r_2))
"""